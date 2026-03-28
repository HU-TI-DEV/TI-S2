// LoRaWAN example code for the Raspberry Pi Pico W and the Waveshare LoRa HAT
// Version 2 with EEPROM persistent LoRA join information
// Controlling a trafficlight
#include <Arduino.h>
#include <SPI.h>
#include <EEPROM.h>
#include <RadioLib.h>
#include <math.h>
#include <stddef.h>
#include <string.h>

// Waveshare Pico-LoRa-SX1262-868M pin mapping
constexpr uint8_t LORA_SCK   = 10;
constexpr uint8_t LORA_MISO  = 12;
constexpr uint8_t LORA_MOSI  = 11;
constexpr uint8_t LORA_CS    = 3;
constexpr uint8_t LORA_DIO1  = 20;
constexpr uint8_t LORA_RST   = 15;
constexpr uint8_t LORA_BUSY  = 2;

// TTN / LoRaWAN configuration
const LoRaWANBand_t region = EU868;
constexpr uint8_t subBand = 0;
constexpr uint8_t UPLINK_FPORT = 1;
constexpr uint8_t DOWNLINK_FPORT = 15;
constexpr unsigned long UPLINK_INTERVAL_MS = 5UL * 60UL * 1000UL; // 5 minutes
constexpr size_t MAX_DOWNLINK_SIZE = 32;
constexpr size_t EXPECTED_DOWNLINK_SIZE = 4;
constexpr unsigned long BLINK_INTERVAL_MS = 300;

// OTAA credentials
// Reused from the uploaded EEPROM sketch
uint64_t joinEUI = 0x0000000000000000ULL;  // zero's for your own created device
uint64_t devEUI  = 0x0000000000000000ULL;  // replace with your DevEUI

uint8_t appKey[16] = {
  0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00
};

uint8_t nwkKey[16] = {
  0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00
};

// Radio + LoRaWAN node
SX1262 radio = new Module(
  LORA_CS,
  LORA_DIO1,
  LORA_RST,
  LORA_BUSY,
  SPI1,
  RADIOLIB_DEFAULT_SPI_SETTINGS
);

LoRaWANNode node(&radio, &region, subBand);

// Persistent storage layout in RP2040 simulated EEPROM
constexpr uint32_t EEPROM_MAGIC = 0x4C575031UL;   // "LWP1"
constexpr uint16_t EEPROM_VERSION = 1;

struct PersistedLoRaState {
  uint32_t magic;
  uint16_t version;
  uint8_t hasNonces;
  uint8_t hasSession;
  uint8_t nonces[RADIOLIB_LORAWAN_NONCES_BUF_SIZE];
  uint8_t session[RADIOLIB_LORAWAN_SESSION_BUF_SIZE];
  uint32_t checksum;
};

static_assert(sizeof(PersistedLoRaState) <= 4096, "Persistent state does not fit in RP2040 EEPROM emulation");

PersistedLoRaState g_state{};

// Traffic light pins and payload handling
constexpr uint8_t LED_RED_PIN    = 16;
constexpr uint8_t LED_YELLOW_PIN = 17;
constexpr uint8_t LED_GREEN_PIN  = 18;

constexpr uint8_t RED_BIT    = 0;
constexpr uint8_t YELLOW_BIT = 1;
constexpr uint8_t GREEN_BIT  = 2;

struct BlinkChannel {
  uint8_t pin;
  bool active;
  uint16_t togglesRemaining;
  bool currentOutputState;
  unsigned long lastToggleMs;
};

uint8_t g_stateByte = 0;

BlinkChannel g_redBlink    = { LED_RED_PIN,    false, 0, false, 0 };
BlinkChannel g_yellowBlink = { LED_YELLOW_PIN, false, 0, false, 0 };
BlinkChannel g_greenBlink  = { LED_GREEN_PIN,  false, 0, false, 0 };

// Helpers
uint32_t fnv1a32(const uint8_t* data, size_t len) {
  uint32_t hash = 2166136261UL;
  for (size_t i = 0; i < len; ++i) {
    hash ^= data[i];
    hash *= 16777619UL;
  }
  return hash;
}

uint32_t calculateStateChecksum(const PersistedLoRaState& state) {
  return fnv1a32(reinterpret_cast<const uint8_t*>(&state), offsetof(PersistedLoRaState, checksum));
}

void initEmptyState(PersistedLoRaState& state) {
  memset(&state, 0, sizeof(state));
  state.magic = EEPROM_MAGIC;
  state.version = EEPROM_VERSION;
  state.checksum = calculateStateChecksum(state);
}

bool loadPersistedState(PersistedLoRaState& state) {
  EEPROM.get(0, state);

  if (state.magic != EEPROM_MAGIC) {
    return false;
  }

  if (state.version != EEPROM_VERSION) {
    return false;
  }

  const uint32_t expected = calculateStateChecksum(state);
  if (state.checksum != expected) {
    return false;
  }

  return true;
}

void savePersistedState(PersistedLoRaState& state) {
  state.magic = EEPROM_MAGIC;
  state.version = EEPROM_VERSION;
  state.checksum = calculateStateChecksum(state);

  PersistedLoRaState current{};
  EEPROM.get(0, current);

  if (memcmp(&current, &state, sizeof(state)) == 0) {
    return;
  }

  EEPROM.put(0, state);
  EEPROM.commit();
}

void copyNoncesFromNode(PersistedLoRaState& state) {
  const uint8_t* buffer = node.getBufferNonces();
  memcpy(state.nonces, buffer, RADIOLIB_LORAWAN_NONCES_BUF_SIZE);
  state.hasNonces = 1;
}

void copySessionFromNode(PersistedLoRaState& state) {
  const uint8_t* buffer = node.getBufferSession();
  memcpy(state.session, buffer, RADIOLIB_LORAWAN_SESSION_BUF_SIZE);
  state.hasSession = 1;
}

void clearSessionInState(PersistedLoRaState& state) {
  memset(state.session, 0, sizeof(state.session));
  state.hasSession = 0;
}

String decodeState(int16_t state) {
  switch (state) {
    case RADIOLIB_ERR_NONE: return "RADIOLIB_ERR_NONE";
    case RADIOLIB_ERR_CHIP_NOT_FOUND: return "RADIOLIB_ERR_CHIP_NOT_FOUND";
    case RADIOLIB_ERR_NETWORK_NOT_JOINED: return "RADIOLIB_ERR_NETWORK_NOT_JOINED";
    case RADIOLIB_ERR_NO_RX_WINDOW: return "RADIOLIB_ERR_NO_RX_WINDOW";
    case RADIOLIB_ERR_NO_JOIN_ACCEPT: return "RADIOLIB_ERR_NO_JOIN_ACCEPT";
    case RADIOLIB_ERR_UPLINK_UNAVAILABLE: return "RADIOLIB_ERR_UPLINK_UNAVAILABLE";
    case RADIOLIB_ERR_CHECKSUM_MISMATCH: return "RADIOLIB_ERR_CHECKSUM_MISMATCH";
    case RADIOLIB_LORAWAN_NEW_SESSION: return "RADIOLIB_LORAWAN_NEW_SESSION";
    case RADIOLIB_LORAWAN_SESSION_RESTORED: return "RADIOLIB_LORAWAN_SESSION_RESTORED";
    default: return "UNKNOWN";
  }
}

void printState(const char* label, int16_t state) {
  Serial.print(label);
  Serial.print(": ");
  Serial.print(decodeState(state));
  Serial.print(" (");
  Serial.print(state);
  Serial.println(")");
}

void configureSpi() {
  SPI1.setSCK(LORA_SCK);
  SPI1.setTX(LORA_MOSI);
  SPI1.setRX(LORA_MISO);

  pinMode(LORA_CS, OUTPUT);
  digitalWrite(LORA_CS, HIGH);

  SPI1.begin();
}

bool restoreBuffersIfPresent() {
  const bool loaded = loadPersistedState(g_state);

  if (!loaded) {
    Serial.println("No valid persisted LoRaWAN state found.");
    initEmptyState(g_state);
    return false;
  }

  Serial.println("Found persisted LoRaWAN state.");

  if (g_state.hasNonces) {
    const int16_t nonceState = node.setBufferNonces(g_state.nonces);
    printState("node.setBufferNonces", nonceState);

    if (nonceState != RADIOLIB_ERR_NONE) {
      Serial.println("Stored nonces buffer is invalid for current credentials. Starting fresh.");
      initEmptyState(g_state);
      savePersistedState(g_state);
      return false;
    }
  }

  if (g_state.hasSession) {
    const int16_t sessionState = node.setBufferSession(g_state.session);
    printState("node.setBufferSession", sessionState);

    if (sessionState != RADIOLIB_ERR_NONE) {
      Serial.println("Stored session buffer is invalid. Keeping nonces, discarding session.");
      clearSessionInState(g_state);
      savePersistedState(g_state);
      return false;
    }
  }

  return g_state.hasNonces || g_state.hasSession;
}

bool isBitSet(uint8_t value, uint8_t bitIndex) {
  return (value & (1U << bitIndex)) != 0;
}

void writeSteadyOutputs() {
  digitalWrite(LED_RED_PIN,    isBitSet(g_stateByte, RED_BIT) ? HIGH : LOW);
  digitalWrite(LED_YELLOW_PIN, isBitSet(g_stateByte, YELLOW_BIT) ? HIGH : LOW);
  digitalWrite(LED_GREEN_PIN,  isBitSet(g_stateByte, GREEN_BIT) ? HIGH : LOW);
}

void restoreSteadyStateForPin(uint8_t pin) {
  if (pin == LED_RED_PIN) {
    digitalWrite(pin, isBitSet(g_stateByte, RED_BIT) ? HIGH : LOW);
  } else if (pin == LED_YELLOW_PIN) {
    digitalWrite(pin, isBitSet(g_stateByte, YELLOW_BIT) ? HIGH : LOW);
  } else if (pin == LED_GREEN_PIN) {
    digitalWrite(pin, isBitSet(g_stateByte, GREEN_BIT) ? HIGH : LOW);
  }
}

void startBlink(BlinkChannel& channel, uint8_t blinkCount) {
  if (blinkCount == 0) {
    return;
  }

  channel.active = true;
  channel.togglesRemaining = static_cast<uint16_t>(blinkCount) * 2U;
  channel.currentOutputState = false;
  channel.lastToggleMs = millis();

  digitalWrite(channel.pin, LOW);
}

void updateBlink(BlinkChannel& channel) {
  if (!channel.active) {
    return;
  }

  const unsigned long now = millis();
  if (now - channel.lastToggleMs < BLINK_INTERVAL_MS) {
    return;
  }

  channel.lastToggleMs = now;
  channel.currentOutputState = !channel.currentOutputState;
  digitalWrite(channel.pin, channel.currentOutputState ? HIGH : LOW);

  if (channel.togglesRemaining > 0) {
    channel.togglesRemaining--;
  }

  if (channel.togglesRemaining == 0) {
    channel.active = false;
    restoreSteadyStateForPin(channel.pin);
  }
}

String toHexByte(uint8_t value) {
  if (value < 0x10) {
    return String("0") + String(value, HEX);
  }
  return String(value, HEX);
}

void printBufferHex(const uint8_t* data, size_t len) {
  for (size_t i = 0; i < len; ++i) {
    Serial.print(toHexByte(data[i]));
    Serial.print(' ');
  }
  Serial.println();
}

void handleTrafficLightPayload(const uint8_t* payload, size_t length) {
  if (payload == nullptr || length < EXPECTED_DOWNLINK_SIZE) {
    Serial.println("Downlink te kort voor verkeerslichtcommando.");
    return;
  }

  const uint8_t stateByte   = payload[0];
  const uint8_t blinkRed    = payload[1];
  const uint8_t blinkYellow = payload[2];
  const uint8_t blinkGreen  = payload[3];

  g_stateByte = stateByte;
  writeSteadyOutputs();

  startBlink(g_redBlink, blinkRed);
  startBlink(g_yellowBlink, blinkYellow);
  startBlink(g_greenBlink, blinkGreen);

  Serial.println("Verkeerslicht updated vanuit downlink.");
  Serial.print("State byte: 0x");
  Serial.println(stateByte, HEX);
  Serial.print("Blink rood: ");
  Serial.println(blinkRed);
  Serial.print("Blink geel: ");
  Serial.println(blinkYellow);
  Serial.print("Blink groen: ");
  Serial.println(blinkGreen);
}

bool activateNode() {
  int16_t state = node.beginOTAA(joinEUI, devEUI, nwkKey, appKey);
  printState("node.beginOTAA", state);
  if (state != RADIOLIB_ERR_NONE) {
    return false;
  }

  node.setADR(true);

  restoreBuffersIfPresent();

  uint32_t failedJoinCount = 0;

  while (true) {
    Serial.println("Calling node.activateOTAA()...");
    state = node.activateOTAA();
    printState("node.activateOTAA", state);

    // Always save current nonces after every OTAA attempt.
    // This prevents DevNonce rollback after power loss/reset.
    initEmptyState(g_state);
    copyNoncesFromNode(g_state);

    if ((state == RADIOLIB_LORAWAN_NEW_SESSION) ||
        (state == RADIOLIB_LORAWAN_SESSION_RESTORED)) {
      copySessionFromNode(g_state);
      savePersistedState(g_state);
      return true;
    }

    clearSessionInState(g_state);
    savePersistedState(g_state);

    failedJoinCount++;
    const unsigned long retryDelayMs = min(180000UL, failedJoinCount * 60000UL);

    Serial.print("Join failed, retrying in ");
    Serial.print(retryDelayMs / 1000UL);
    Serial.println(" seconds.");
    delay(retryDelayMs);
  }
}

void saveCurrentSession() {
  if (!g_state.hasNonces) {
    initEmptyState(g_state);
    copyNoncesFromNode(g_state);
  }

  copySessionFromNode(g_state);
  savePersistedState(g_state);
}

void setup() {
  Serial.begin(115200);

  unsigned long start = millis();
  while (!Serial && (millis() - start < 5000UL)) {
    delay(10);
  }

  delay(1000);
  Serial.println();
  Serial.println("Pico W + Waveshare SX1262 + TTN persistent OTAA verkeerslicht");

  pinMode(LED_RED_PIN, OUTPUT);
  pinMode(LED_YELLOW_PIN, OUTPUT);
  pinMode(LED_GREEN_PIN, OUTPUT);

  digitalWrite(LED_RED_PIN, LOW);
  digitalWrite(LED_YELLOW_PIN, LOW);
  digitalWrite(LED_GREEN_PIN, LOW);

  EEPROM.begin(sizeof(PersistedLoRaState));
  configureSpi();

  int16_t radioState = radio.begin();
  printState("radio.begin", radioState);
  if (radioState != RADIOLIB_ERR_NONE) {
    while (true) {
      delay(1000);
    }
  }

  if (!activateNode()) {
    Serial.println("Activation failed.");
    while (true) {
      delay(1000);
    }
  }

  Serial.println("Activation successful.");
  // set all leds to off
  g_stateByte = 0;
  g_redBlink.active = false;
  g_yellowBlink.active = false;
  g_greenBlink.active = false;
  writeSteadyOutputs();
  Serial.println("Traffic light reset: all outputs off.");
}

void loop() {
  updateBlink(g_redBlink);
  updateBlink(g_yellowBlink);
  updateBlink(g_greenBlink);

  static unsigned long lastUplinkMs = millis() - UPLINK_INTERVAL_MS;

  if (millis() - lastUplinkMs < UPLINK_INTERVAL_MS) {
    delay(5);
    return;
  }

  lastUplinkMs = millis();

  const float tempC = analogReadTemp();
  const int16_t tempCenti = static_cast<int16_t>(lroundf(tempC * 100.0f));

  uint8_t payload[2];
  payload[0] = static_cast<uint8_t>((tempCenti >> 8) & 0xFF);
  payload[1] = static_cast<uint8_t>(tempCenti & 0xFF);

  Serial.print("Internal temperature: ");
  Serial.print(tempC, 2);
  Serial.println(" C");

  uint8_t downlink[MAX_DOWNLINK_SIZE] = {0};
  size_t downlinkLen = sizeof(downlink);
  LoRaWANEvent_t uplinkEvent;
  LoRaWANEvent_t downlinkEvent;

  const int16_t state = node.sendReceive(
    payload,
    sizeof(payload),
    UPLINK_FPORT,
    downlink,
    &downlinkLen,
    false,
    &uplinkEvent,
    &downlinkEvent
  );

  bool appDownlinkHandled = false;

  printState("node.sendReceive", state);

  if (state >= 0) {
    saveCurrentSession();
    Serial.println("Session saved to EEPROM.");
  } else {
    Serial.println("Uplink failed. Session not updated.");
  }

  if (state > 0) {
    Serial.print("Downlink ontvangen op FPort ");
    Serial.println(downlinkEvent.fPort);
    Serial.print("Downlink bytes: ");
    printBufferHex(downlink, downlinkLen);

    if (downlinkEvent.fPort == DOWNLINK_FPORT) {
      handleTrafficLightPayload(downlink, downlinkLen);
      appDownlinkHandled = true;
    } else {
      Serial.println("Downlink ontvangen, maar niet op de verkeerslicht FPort.");
    }
  } else if (state == 0) {
    Serial.println("Geen downlink ontvangen.");
  }

  if (!appDownlinkHandled) {
    writeSteadyOutputs();
  }
}