# Practicum UART voor Pico met Arduino

## Voorbereiding

- Neem mee:
  - een Arduino Uno
  - een Raspberry Pi Pico
  - je elektronica spullen (breadboard, weerstanden etc.)
  - je logic analyser
- Lees alvast de lesstof door: [UART](../README.md)
- Kijk de volgende video: [Saleae Logic Analyser Tutorial](https://www.youtube.com/watch?v=rR5cEFRO9_s)

## Opdracht 1 - UART test ARduino Uno

- Zet de [Arduino code](./arduino_uart_test/) op de Arduino
- Kijk wat je op de "Serial Monitor" kan zien.
- Verbind twee channels van de Logic Analyzer met D0 (`RX<-0`) en D1 (`TX->1`), en GND met GND
- Zet de Logic Analyzer op 1MHz en start de analyzer (met de "play" button)
- Stop ne een minuut de opname en kijk wat op welke channel zichtbaar is
- Voeg een Analyzer toe voor "Async Serial" met een Bit rate van 115200
- Schakel van Data Table om naar Terminal en kijk wat je in "Data"kan zien.

## Opdracht 2 - UART test Raspberry Pi Pico

- Zet de [Pico code](./pico_uart_test/) op de Pico.
- Zet de "Run configuration" op MicroPython, schakel aan dat de REPL wordt getoond na het opstarten van de app
- Verbind twee channels van de Logic Analyzer met GPIO4 (`UART1 TX`) en GPIO5 (`UART1 RX`), en GND met GND (laat je niet verwarren door de SPI0-functies)
- Zet de Logic Analyzer op 1MHz en start de analyzer (met de "play" button)
- Stop ne een minuut de opname en kijk wat op welke channel zichtbaar is
- Voeg een Analyzer toe voor "Async Serial" met een Bit rate van 115200
- Schakel van Data Table om naar Terminal en kijk wat je in "Data"kan zien.

## Opdracht 3 - UART test met Arduino en Pico

Nu hebben we een kleine schakeling nodig, omdat de ingang van de Pico geen 5V van de Arduino mag krijgen.

Onderdelen:

- Arduino Uno
- Raspberry Pi Pico
- Weerstand 1 kOhm
- Weerstand 2,2 kOhm
- draadjes
- breadboard
- Logic Analyzer met tenminste drie draadjes

Maak met de weerstanden een spanningsdeler

**Schakel Arduino en Pico out (unplug from USB) voor het maken van verbindingen!**

Maak deze verbindingen voor het zenden van Arduino Uno naar Pico:

- Arduino `TX->1` lijn (D1)
- 1 kOhm-weerstand
- Pico `UART1 RX` lijn (GPIO5, Module pin 7)
- 2,2 kOhm weerstand
- GND (Arduino en Pico)

Maak deze verbindingen voor het zenden van Pico naar Arduino Uno:

- Pico `UART1 TX` lijn (GPIO4, Module pin 6)
- Arduino `RX<-0` lijn (D0)
- GND (Arduino en Pico)

**Check alle verbindingen voordat je Arduino en Pico met USB verbindt!**

Met de Logic Analyzer kan je nu met twee channels de communicatie in beide richtigen opnemen/zien.
