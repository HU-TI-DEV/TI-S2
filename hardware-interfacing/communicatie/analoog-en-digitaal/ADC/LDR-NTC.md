![logo](../img/Kennline_NTC.png) [](logo-id)

# LDR-NTC: analoog naar digitaal met passief sensoren [](title-id)

### Inhoud[](toc-id)

- [LDR-NTC: analoog naar digitaal met passief sensoren](#ldr-ntc-analoog-naar-digitaal)
  - [Inhoud](#inhoud)
  - [LDR](#ldr)
  - [NTC](#ntc)
  - [De schakeling](#de-schakeling)
  - [Arduino voorbeeld code](#arduino-voorbeeld-code)
  - [Referenties](#referenties)

---

### LDR

![Light Dependent Resistor 4mm](img/r-ldr-4mm-th.jpg)

Een Light Dependent Resistor (LDR) verandert zijn weerstand afhankelijk van de hoeveelheid licht die erop valt.

De LDR's in het [Turing Lab Hardware Shop](https://hu-hbo-ict.gitlab.io/turing-lab/ti-lab-shop/) veranderen hun weerstand tussen ca. 2 MegaOhm (donker) tot ca. 600 Ohm (erg helder).

Met hulp van een vaste weerstand kunnen we deze verandering in een spanning wandelen. Deze spanning kan de ADC meten.

### NTC

Een ''Negative Temperature Coefficient resistor'' (NTC) verandert zijn weerstand afhankelijk van de temperaturr van d eomgeving.

Een weerstand heeft een 'positive temperature coefficient' (PTC) als de waarde van de weerstand hoger wordt als de temperatuur hoger wordt. Als de waarde van de weerstand kleiner wordt met verhoging van de temperatuur spreken we van 'negative temperature coefficient' (NTC).

### De schakeling

![LDR-NTC breadboard schakeling](img/LDR-NTC_bb.png)

## Arduino voorbeeld code

De voorbeeld code meet alleen een spanning en geeft deze via het serial interface uit.

> Let op: Op de Arduino Nano is Analog Pin 'A7' erg makkelijk bereikbaar. Als je een Arduino Uno gebruikt, neem beter een andere pin en pas het programma aan. (Je kan bijvoorbeeld A5 gebruiken.)

```arduino
// LDR-NTC.ino - Analog Input example - 2024-02-04-hp
// Tested on Arduino Nano
// [+5V]---[=LDR or NTC_10K=]---[A7]---[=10k=]---[GND]
const long baudrate = 9600;
const int  delaytime_ms = 1000; // delay 1000ms = 1s

const int pinAnalogIn = A7;
int dataAnalogIn = 0; // 0..1023 (10bit resolution)

// The Arduino Analog-to-Digital Converter (ADC) has 10 bit resolution.
// Arduino Uno and Arduino Nano map this to a range from 0 Volts to 5 Volts.
const float analogDataToVolt = 5.0 / 1024;

void setup() {
  pinMode(pinAnalogIn, INPUT);
  // Initialize serial interface and wait for port to open:
  Serial.begin(baudrate);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  Serial.println("analog_01 - Analog Input example");
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
```
[Arduino bestand](../ADC/files/LDR-NTC/LDR-NTC.ino) 

## Referenties

- [Analoog en digitaal](<https://en.wikipedia.org/wiki/Analogue_electronics#Analogue_vs_digital_electronics>)

