# Programma UART (deel 2)

Tijdens deze les zetten we seriele communicatie met PCs en USB-to-serial adapters op.

We kijken met een Logic Analyzer naar de structuur van de data die over de draad gaat.

Optioneel gebruiken we een Arduino met een I2C OLED display om een andere manier van communicatie te zien.

## Voorbereiding

- Neem je elektronica spullen (breadboard, weerstanden etc) mee.
- Neem je Logic Analyzer mee (als je die al hebt)
- Lees alvast de UART lesstof door: [UART](../../hardware-interfacing/communicatie/UART/README.md)
- Kijk de volgende video [Salae Logic Analyzer Tutorial](https://www.youtube.com/watch?v=rR5cEFRO9_s)

Optioneel:

- Neem een Arduino Uno mee.
- Neem een Raspberry Pi mee.
- Lees de I2C lesstof pagina: [I2C](../../hardware-interfacing/communicatie/I2C/README.md)

## Tijdens de les

Tijdens de les krijg je een [CP2102 USB2.0 to UART TTL 5pin Connector](https://hu-hbo-ict.gitlab.io/turing-lab/ti-lab-shop/CP2102%20USB%202.0%20to%20UART%20TTL%205PIN%20Connector.html).

Je verbind twee PCs met deze adapters:

| 1e USB-2-TTL | 2e USB-2-TTL |
| :----:       | :----:       |
| TXD          | RXD          |
| RXD          | TXD          |
| GND          | GND          |

> De pinnen `3V3` en `+5V` gebruiken we niet in deze opdracht!

- Op de PCs gebruiken we een 'Seriel Terminal'' programma (bv. `Putty`) om data tussen de twee PCs te zenden en te ontvangen.
- Met de Logic Analyzer 'luister' je op RXD en TXD (vergeet GND niet aan te sluiten) naar de communicatie tussen de twee PCs.
- Documenteer dit met omschrijving en schermafbeeldingen.

----

Als je het nog niet gedaan hebt, werk aan:

- [Practicum UART](../../hardware-interfacing/communicatie/UART/practicum-uart.md)

Voer het zelf uit - tegelijkertijd met een medecursist. (Samenwerking is belangrijk, en het is zelfs essentieel bij de test met communicatie tussen 2 Arduinos.)

----

Optioneel:

- Zet een Arduino Uno op met een I2C OLED display en gebruik een testprogramma om data via de I2C-verbinding te sturen.
- Als alternatief kan je ook een Raspberry Pi PICO of PICO-W met een I2C OLED display gebruiken.
- Met de Logic Analyzer 'luister' je op SCK en SDA (vergeet GND niet aan te sluiten) naar de communicatie tussen de microcontroller en het display.
- Documenteer dit met omschrijving en schermafbeeldingen.

## Na de les

- Upload de resultaten van het practicum naar de bijbehorende Canvas entry.

## Portfolio-Tip

Tijdens het project zul je vermoedelijk de meetgegevens van de microcontroller via uart communiceren naar een PC of Raspberry Pi.
De resulterende code, de bijbehorende toelichting en feedback daarop kan gebruikt worden als portfolio-item.

Je kan een UART-adapter gebruiken voor testing en om fouten te vinden, een microcontroller kan daarmee data aan een PC zenden of zelfs commando's ontvangen.
