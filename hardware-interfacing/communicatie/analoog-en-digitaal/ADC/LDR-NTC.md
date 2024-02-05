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

De LDR's in het [Turing Lab Hardware Shop](https://hu-hbo-ict.gitlab.io/turing-lab/ti-lab-shop/) veranderen hun weerstand tussen ca. 2 MegaOhm (donker) tot ca. 600 Ohm (erg helder). Waarschijnlijk is dat een 5528 type (LDR03/LDR04).

Met hulp van een vaste weerstand kunnen we deze verandering in een spanning wandelen. Deze spanning kan de ADC meten.

### NTC

Een ''Negative Temperature Coefficient resistor'' (NTC) verandert zijn weerstand afhankelijk van de temperaturr van d eomgeving.

Een weerstand heeft een 'positive temperature coefficient' (PTC) als de waarde van de weerstand hoger wordt als de temperatuur hoger wordt. Als de waarde van de weerstand kleiner wordt met verhoging van de temperatuur spreken we van 'negative temperature coefficient' (NTC).

### De schakeling

![LDR-NTC breadboard schakeling](img/LDR-NTC_bb.png)

## Arduino voorbeeld code

De voorbeeld code meet alleen een spanning en geeft deze via het serial interface uit.

> Let op: Het voorbeeld gebruikt Analog Pin 'A0', maar op de Arduino Nano is Analog Pin 'A7' erg makkelijk bereikbaar. Voor een andere Analog Pin kan je makkelijk het programma aanpassen.

```arduino
// LDR-NTC.ino - Analog Input example - 2024-02-04-hp
// Tested on Arduino Nano
// [+5V]---[=LDR or NTC_10K=]---[A0]---[=10k=]---[GND]

const long baudrate = 9600;
const int  delaytime_ms = 1000; // delay 1000ms = 1s

const int pinAnalogIn = A0;
int dataAnalogIn = 0;

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
```
[Arduino bestand](../ADC/files/LDR-NTC/LDR-NTC.ino) 

## Referenties

LDR Datasheets

- [NTE Electronics, Inc. - LDR Photoresistors Datasheet](https://www.nteinc.com/resistor_web/pdf/LDR-Series.pdf)
- [Alldatasheet.com GL5528 (GL55 series)](https://www.alldatasheet.com/datasheet-pdf/pdf/1131893/ETC2/GL5528.html)

NTC Datasheets

- [Cantherm MF52 series - Pearl-Shaped Precision NTC Thermistor for Temperature Measurement](https://www.cantherm.com/wp-content/uploads/2017/05/cantherm_mf52_1.pdf)
