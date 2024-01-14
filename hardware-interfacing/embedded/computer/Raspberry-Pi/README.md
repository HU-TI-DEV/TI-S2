![logo](../Raspberry-Pi/img/Raspberry_Pi_4_Model_B_-_Top.jpg) [](logo-id)

# Raspberry Pi[](title-id)

### Inhoud[](toc-id)

- [Raspberry Pi](#raspberry-pi)
    - [Inhoud](#inhoud)
  - [Een introductie](#een-introductie)
    - [General Purpose Input/Output (GPIO)](#general-purpose-inputoutput-gpio)
  - [Referenties](#referenties)

---

**v0.0.1 [](version-id)** Start document Raspberry Pi door HU IICT[](author-id).

---

## Een introductie

De Raspberry Pi hardware is ontstaan als een onderwijsproject om computeronderwijs op scholen te stimuleren. Het computer systeem wordt nu wereldwijd toegepast in uiteenlopende projecten. De Raspberry Pi is singleboardcomputer gebasseerd op een ARM-processer. Omdat de computer een General Purpose Input/Output (GPIO)-bus heeft kan je deze eenvoudig uitbreiden.

### General Purpose Input/Output (GPIO)

Een GPIO pin is een elektronische aansluiting (pin) van een chip of board, die onder directe besturing van een programma staat. Een GPIO pin kan als output (voor het aansturen van iets buiten het board) of als input (om iets buiten het boord waar te nemen) worden gebruikt. We beginnen met het gebruik als output.
Om een GPIO pin op de Raspberry Pi in Python te gebruiken moeten we eerste wat ‘standaard’ dingen doen. Breek hier je hoofd niet over, dit moet gewoon altijd aan het begin van je Python programma code staan. 

    In tegenstelling tot bijvoorbeeld de Arduino Uno is de interne logica 3V3! Hoog is een pin dus maximaal 3.3V en de GPIOs geven een maximale stroom van 16mA. De GPIO pinnen zijn ook allemaal digitale pinnen. De Raspberry Pi heeft geen Analoog naar Digitaal Converter (ADC).

Het Raspberry Pi chip heeft een groot aantal GPIO pinnen, die ieder een nummer hebben. Een aantal GPIO pinnen zijn beschikbaar op de dubbele rij pinnen. Daarnaast zijn er ook pinnen die verbonden zijn met GND, +5V, +3.3V, en nog wat bijzondere pinnen.

![GPIO pinnen](../Raspberry-Pi/img/raspio-ports.jpg)

Let er op dat pinnen op twee manieren zijn gelabeled: ze hebben zowel een nummer dat aangeeft waar de pin zich bevindt (het physical pinnummer) als een nummer dat als naam gebruikt wordt (het BCM pinnummer). De fysieke pin 8 komt bijvoorbeeld overeen met het label "GPIO14" of "BCM14". Als het niet lukt een pin vanuit Python aan te spreken dan heb je mogelijk het verkeerde nummeringsschema gebruikt.

## Referenties

- Raspberry Pi (<https://en.wikipedia.org/wiki/Raspberry_Pi>)
- GPIO pins (<https://projects.raspberrypi.org/en/projects/physical-computing/1>)