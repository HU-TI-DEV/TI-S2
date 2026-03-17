![logo](./img/Architecture_lorawan.png) [](logo-id)

# LoRaWAN[](title-id) <!-- omit in toc -->

### Inhoud[](toc-id) <!-- omit in toc -->

- [Hardware voorbereiden](#hardware-voorbereiden)
  - [End device configuratie](#end-device-configuratie)
  - [Arduino IDE geschikt maken](#arduino-ide-geschikt-maken)
  - [RadioLib installeren](#radiolib-installeren)
- [End Node aanmaken in TTN](#end-node-aanmaken-in-ttn)
  - [Voorbeeld Applicatie](#voorbeeld-applicatie)
  - [Arduino voorbeeld sketch](#arduino-voorbeeld-sketch)
  - [Payload formatteren](#payload-formatteren)
  - [JavaScript voorbeeld data formatter](#javascript-voorbeeld-data-formatter)
- [Referenties](#referenties)

---

**v0.1.0 [](version-id)** Start document voor LoRaWAN en installatie instructies door HU IICT[](author-id).

---

## LoRaWAN

LoRaWAN (Long Range Wide Area Network) is een specificatie voor een telecommunicatienetwerk geschikt voor langeafstandscommunicatie met weinig vermogen. Deze techniek gaan we dit semester gebruiken om sensor data over lange afstand te versturen. De hardware componenten bestaan uit een Raspberry Pi Pico W uit Semester 1 in combinatie met een Pico-LoRa-SX1262-868M Waveshare head. Als software backbone gebruiken we netwerkinfrastructuur van [The Things Network](https://www.thethingsnetwork.org).

Iedere student kan het onderstaande stappenplan doorlopen om een werkende verbinding te laten zien. Je gaat daarna met je team verder om de hardwareintegratie met jullie sensor-node verder vorm te geven.

# Hardware voorbereiden

Je hebt nodig:
- Raspberry Pi Pico W
- een USB kabel (moet ook geschikt zijn voor data)
- een Waveshare head
- Een antenne

## End device configuratie

Bevestig eerst de antenne aan de Waveshare head (dit is een SMA naar I-PEX MHF I antennekabel). Installeer dan pas de Waveshare head op de Raspberry Pi Pico W. **Op de PCB van de Waveshare head staat de richting van de USB aansluiting aangeven** zo weet je hoe je deze module moet orienteren. 

## Arduino IDE geschikt maken

We gaan nu de Arduino IDE geschikt maken om softare op de Raspberry Pi Pico te flashen.

1) Installeer als je dit nog niet hebt gedaan de Arduino IDE. Ik heb gebruik gemaakt van Arduino IDE versie 2.3.8.
2) Open Arduino IDE
3) Ga naar File->Preferences (op een Mac Arduino IDE -> Preferences)  
Voeg bij “Additional Boards Manager URLs” de volgende URL toe: https://github.com/earlephilhower/arduino-pico/releases/download/global/package_rp2040_index.json en klik op OK
4) Ga naar Tools->Boards->Board Manager.  
Type “pico”
Installeer “Raspberry Pi Pico/RP2040/RP2350 by Earle F. Philhower, III” (mijn versie is 5.5.1)

## RadioLib installeren

RadioLib geeft ons de SX1262 radio driver dat is de chip waarmee we data draadloos kunnen versturen.

1) Ga naar Tools->Manage Libraries en zoek op “RadioLib”
2) Installeer “RadioLib by Jan Gromes” (mijn versie is 7.6.0)

Je ben nu klaar met de voorbereidingen.

# End Node aanmaken in TTN

We maken nu een uitstapje naar The Things Network(TTN). Je kunt bij TTN gratis een account aanmaken en tot 50 devices registeren. Op de HU hebben we een aantal LoRaWAN gateways staan dus het bereik moet voldoende zijn. Nieuwe end-nodes maar ook gateways moet je op het TTN platform registeren.

Ga naar https://eu1.cloud.thethings.network/ en login met je TTN login en wachtwoord (maak deze aan als je dit nog niet hebt gedaan).

1) Kies 'Create application'. Maak een applicatie aan.
2) Kies 'Add end device' en klik daarna op je eerder aangemaakte applicatie
3) Selecteer End device type
Kies “Enter end device specifics manually”  
Frequency plan: Europe 868.1 MHz  
LoRaWAN version: 1.1.0  
Regional Parameters version: RP001 1.1 revision A  

The joinEUI for custom devices is JoinEUI = 0000000000000000  

De volgende keys kan je laten genereren (ik laat in verband om veiligheidsredenen de keys hier niet zien)  
DevEUI: generate one in TTN (70xxxxxxxxxxxxxx)  
AppKey: generate one in TTN (ABxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx)  
NwkKey: generate one in TTN (CAxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx)  

Noteer deze keys. **Sla ze niet op in je repo**. Plaats ze eventueel in een bestand en voeg een .gitignore regel toe voor dat bestand (oefen dit eerst een keer).

## Voorbeeld Applicatie

We gaan nu een voorbeeld sketch uploaden naar de Raspberry Pi Pico W. Sluit de USB kabel aan op je computer. Daarna kan je de Raspberry Pi Pico W aansluiten en gelijktijdig de BOOTSEL button inhouden. De Pico komt zo in boot mode zodat we nieuwe firmware kunnen flashen. 

In de Arduino IDE:

1) Selecteer jouw developement board
Selecteer je board onder Tools->Board->Raspberry Pi (…)->Raspberry Pi Pico W

![Pico W](./img/Pico_W.png)

2) De sketch die je moet gebruiken staat bij het volgende kopje in deze manual (hieronder bij "Arduino voorbeeld sketch").    
De DevEUI key, AppKey en NwKey moet je toevoegen aan de voorbeeld sketch. 
4) Kies board Pico W onder Tools->Board
5) Kies UFL board onder Tools->Port
6) Kies Upload

## Arduino voorbeeld sketch

```c++
// LoRaWAN example code for the Raspberry Pi Pico W and the Waveshare LoRa head
#include <Arduino.h>
#include <RadioLib.h>
#include <math.h>

// Waveshare Pico-LoRa-SX1262-868M pin mapping
constexpr uint8_t LORA_SCK   = 10;
constexpr uint8_t LORA_MISO  = 12;
constexpr uint8_t LORA_MOSI  = 11;
constexpr uint8_t LORA_CS    = 3;
constexpr uint8_t LORA_DIO1  = 20;
constexpr uint8_t LORA_RST   = 15;
constexpr uint8_t LORA_BUSY  = 2;

// LoRaWAN region, Europe 868 MHz
const LoRaWANBand_t region = EU868;
constexpr uint8_t subBand = 0;

// TTN OTAA credentials
// Replace these with your own values from TTN, devEUI, appKey and nwkKey can be auto-generated
// JoinEUI may be all zeros for TTN if that is how your device is registered

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

// Uplink settings
constexpr uint8_t UPLINK_FPORT = 1;
constexpr unsigned long UPLINK_INTERVAL_MS = 5UL * 60UL * 1000UL; // 5 minutes

// Helpers
String decodeState(int16_t state) {
  switch (state) {
    case RADIOLIB_ERR_NONE: return "RADIOLIB_ERR_NONE";
    case RADIOLIB_ERR_CHIP_NOT_FOUND: return "RADIOLIB_ERR_CHIP_NOT_FOUND";
    case RADIOLIB_ERR_NETWORK_NOT_JOINED: return "RADIOLIB_ERR_NETWORK_NOT_JOINED";
    case RADIOLIB_ERR_NO_RX_WINDOW: return "RADIOLIB_ERR_NO_RX_WINDOW";
    case RADIOLIB_ERR_NO_JOIN_ACCEPT: return "RADIOLIB_ERR_NO_JOIN_ACCEPT";
    case RADIOLIB_ERR_UPLINK_UNAVAILABLE: return "RADIOLIB_ERR_UPLINK_UNAVAILABLE";
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

bool joinNetwork() {
  Serial.println("Initialising radio...");

  SPI1.setSCK(LORA_SCK);
  SPI1.setTX(LORA_MOSI);
  SPI1.setRX(LORA_MISO);

  pinMode(LORA_CS, OUTPUT);
  digitalWrite(LORA_CS, HIGH);

  SPI1.begin();

  int16_t state = radio.begin();
  printState("radio.begin", state);
  if (state != RADIOLIB_ERR_NONE) {
    return false;
  }

  Serial.println("Configuring OTAA credentials...");
  state = node.beginOTAA(joinEUI, devEUI, nwkKey, appKey);
  printState("node.beginOTAA", state);
  if (state != RADIOLIB_ERR_NONE) {
    return false;
  }

  Serial.println("Joining TTN...");
  state = node.activateOTAA();
  printState("node.activateOTAA", state);

  return (state == RADIOLIB_LORAWAN_NEW_SESSION) ||
         (state == RADIOLIB_LORAWAN_SESSION_RESTORED);
}

void setup() {
  Serial.begin(115200);

  unsigned long start = millis();
  while (!Serial && (millis() - start < 5000UL)) {
    delay(10);
  }

  delay(1000);
  Serial.println();
  Serial.println("Pico W + Waveshare SX1262 LoRaWAN test");

  if (!joinNetwork()) {
    Serial.println("Join failed. Check keys, TTN region, gateway coverage, and wiring.");
    while (true) {
      delay(1000);
    }
  }

  Serial.println("Join successful.");
}

void loop() {
  // Read RP2040 internal temperature in Celsius
  float tempC = analogReadTemp();

  // Encode as signed int16 in centi-degrees Celsius
  // Example: 23,45 C -> 2345
  int16_t tempCenti = static_cast<int16_t>(lroundf(tempC * 100.0f));

  uint8_t payload[2];
  payload[0] = static_cast<uint8_t>((tempCenti >> 8) & 0xFF);
  payload[1] = static_cast<uint8_t>(tempCenti & 0xFF);

  Serial.print("Internal temperature: ");
  Serial.print(tempC, 2);
  Serial.println(" C");

  int16_t state = node.sendReceive(payload, sizeof(payload), UPLINK_FPORT);
  printState("node.sendReceive", state);

  if (state > 0) {
    Serial.println("Downlink received.");
  } else if (state == 0) {
    Serial.println("No downlink received.");
  } else {
    Serial.println("Uplink failed.");
  }

  Serial.print("Waiting ");
  Serial.print(UPLINK_INTERVAL_MS / 1000UL);
  Serial.println(" seconds...");
  delay(UPLINK_INTERVAL_MS);
}
```

We versturen een temperatuur meting van de interne temperatuur sensor. Dit doen we alleen als een test. Dit is geen betrouwbare manier om de omgevingstemperatuur te meten.

## Payload formatteren

Op het TTN moeten we voor deze end node nog laten weten hoe onze payload is geformateerd. Daarvoor voegen we een Payload formatter toe. Ga terug naar [https://eu1.cloud.thethings.network/](https://eu1.cloud.thethings.network/) en kies je project. Selecteer dan je end node. Onder het tabblad 'Payload formatters' voeg je een Custom Javascript formatter toe. De javascript behorende bij de Arduino voorbeeld sketch is de volgende:

## JavaScript voorbeeld data formatter

```javascript
function decodeUplink(input) {
  const bytes = input.bytes;

  if (bytes.length !== 2) {
    return {
      errors: [`Expected 2 bytes, got ${bytes.length}`]
    };
  }

  let value = (bytes[0] << 8) | bytes[1];

  if (value & 0x8000) {
    value -= 0x10000;
  }

  return {
    data: {
      temperature_c: value / 100.0
    }
  };
}
```

Kies het tabblad Live data. Zie je de data binnenkomen?

# Referenties

- LoRaWAN (<https://nl.wikipedia.org/wiki/LoRaWAN>)
- The Things Network (<https://www.thethingsnetwork.org>)
