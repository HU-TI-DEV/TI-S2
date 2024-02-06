// LDR-NTC.ino - Analog Input example - 2024-02-04-hp
// Tested on Arduino Nano
// [+5V]---[=LDR or NTC_10K=]---[A0]---[=10k=]---[GND]

const long baudrate = 9600;
const int  delaytime_ms = 1000; // delay 1000ms = 1s

const int pinAnalogIn = A0;
int dataAnalogIn = 0;

// The Arduino Analog-to-Digital Converter (ADC) has 10 bit resolution.
// Each measurement results in a number from 0 to 1023.
// Arduino Uno and Arduino Nano map this to a range from 0 Volts to 5 Volts.
const float analogDataToVolt = 5.0 / 1024;

void setup() {
  pinMode(pinAnalogIn, INPUT);
  // Initialize serial interface and wait for port to open:
  Serial.begin(baudrate);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  Serial.println("LDR-NTC.ino - Analog Input example");
}

void loop() {
  dataAnalogIn = analogRead(pinAnalogIn);
  Serial.print("Analog input value: ");
  Serial.print(dataAnalogIn);
  Serial.print(" - Voltage: ");
  Serial.println(dataAnalogIn * analogDataToVolt);
  delay(delaytime_ms);
}

//EOF