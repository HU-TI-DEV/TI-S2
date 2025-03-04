# Het Serial Peripheral Interface (SPI)

SPI is een communicatieprotocol waarmee een *Main*-device (bijvoorbeeld Arduino Uno) over vier verbindingen met een *Sub*-device (bijvoorbeeld een BME280 sensor) communiceert.

Als je meerdere ICs aan een Main-device wil ansluiten, dan kan je drie van deze verbindingen hergebruiken (CLK, MOSI, MISO).
Maar iedere Sub-device heeft een eigen "Chip Select" of "Sub Select" nodig.

Het Serial Peripheral Interface (SPI) kan bijvoorbeeld worden gebruikt:

- met een of meerdere 74HC595 ICs (schuifregister voor serieel-naar-parallel-omzetting) voor meer output pinnen
- met een BME280 of BMP280 sensor om luchtdruk, temperatuur en (BME280) relatieve luchtvochtigheid te lezen
- met een OLED display (SPI) om tekst en grafiek op een schermpje te tonen

## Voorbereiding

- Lees de info over [SPI op Wikipedia](https://nl.wikipedia.org/wiki/Serial_Peripheral_Interface)
- Lees het [lesmateriaal over SPI](../../hardware-interfacing/communicatie/SPI/README.md)

## Tijdens en na de les

Oefen je **individueel** met SPI door een OLED scherm aan te sluiten en daar tekst op te plaatsen.

Maak je met je **team** met behulp van de uitleg en voorbeeldcode een eerste opstelling met een Arduino Uno en een BME280.
Laat temperatuur, luchtdruk (en met een BME280 ook relatieve luchtvochtigheid) op de Serial Monitor zien.

Denk ook over na hoe je een 74HC595 (Sub-device) kan aansluiten aan een Arduino Uno (Main-device) via SPI. Kan je ook twee 74HC595 achter elkaar aan een Main-device aansluiten?

## Portfolio-Tip

Met een BME280 kan je een programma maken om weersvoorspelling te maken. Of je kan nuttige data verzamelen uit je leefomgeving.

Bespreek wat je wil gaan doen binnen je team. Wil je bijvoorbeeld een display aanluiten via SPI? Temperatuur tonen?

Beschrijf en documenteer alles goed, schrijf bijbehorende software. Laat je opgeleverde werk voorzien van feeback door een van de kennisdocenten.
