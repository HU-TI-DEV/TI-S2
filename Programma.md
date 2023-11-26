![logo](https://www.hu.nl/-/media/hu/afbeeldingen/algemeen/hu-logo.ashx) [](logo-id)

# Semester 2 van Technische Informatica[](title-id)

### Inhoud[](toc-id)

- [Semester 2 van Technische Informatica](#semester-2-van-technische-informatica)
    - [Inhoud](#inhoud)
  - [Een introductie](#een-introductie)
  - [Programma](#programma)
    - [Onderwijsweek C1](#onderwijsweek-c1)
    - [Onderwijsweek C2](#onderwijsweek-c2)
    - [Onderwijsweek C3](#onderwijsweek-c3)
    - [Onderwijsweek C4](#onderwijsweek-c4)
    - [Onderwijsweek C5](#onderwijsweek-c5)
    - [Onderwijsweek C6](#onderwijsweek-c6)
    - [Onderwijsweek C7](#onderwijsweek-c7)
    - [Onderwijsweek C8](#onderwijsweek-c8)
    - [Onderwijsweek C9](#onderwijsweek-c9)
    - [Onderwijsweek C10](#onderwijsweek-c10)

---

**v0.1.0 [](version-id)** Semester 2 TI programma door HU IICT[](author-id).

---

## Een introductie

In semester 2 van Technische Informatica staat het kweekkas project centraal. Je krijgt in dit semester verschillende facetten van Technische Informatica te zien. Van Object Georienteerd programmeren tot aan de beginselen van elektronica. In het project zal je merken dat je deze opgedane kennis direct kunt gebruiken. Je komt in aanreking met veel Internet of Things (IoT) concepten. Elke week maak je een stapje. Aan het einde van dit semester heb je samen met je  ontwikkelteam een geautomatiseerd kas systeem gemaakt.

## Programma

### Onderwijsweek C1

Onderwijsweek | Dag | Thema | Project | Kennissessie
--- | --- | --- | --- | ---
C1 | di | Project Kick-off. Inrichten van een [ontwikkelomgeving](./software/inrichten-ontwikkelomgeving/readme.md) & werken met [Git](./software/git/readme.md). Week C1. We leren een ADC te gebruiken. Aan het eind van deze week kan je een temperatuursensor uitlezen een analoge waarde omzetten naar een temperatuur. In een for-loop kan je graden Kelvin omzetten naar graden Celsius en het resultaat laten weergeven in een console. | Project introductie. De slimme kas. Curriculum toelichting semester 2 TI. Wat gaan we doen? Indelen van de groepen. | Introductie en geschiedenis C/C++
C1 | wo | Project Kick-off. Inrichten van een [ontwikkelomgeving](./software/inrichten-ontwikkelomgeving/readme.md) & werken met [Git](./software/git/readme.md). | Scrum en projectplanning | Inrichten ontwikkelomgeving en opzetten. Visual studio code & Platform IO basics. "Hello world" voorbeeld code.
C1 | do | Project Kick-off. Inrichten van een [ontwikkelomgeving](./software/inrichten-ontwikkelomgeving/readme.md) & werken met [Git](./software/git/readme.md). | Werken aan project | Git introductie en opzetten. Eerste project "Hello greenhouse" aanpassen en op Git plaatsen. Analoge pin uitlezen. SI eenheden. Rekenkundige expressies.
C1 | vr | Project Kick-off. Inrichten van een [ontwikkelomgeving](./software/inrichten-ontwikkelomgeving/readme.md) & werken met [Git](./software/git/readme.md). | Team contract inleveren. | Data types, int float, bool en C++ for loop 

### Onderwijsweek C2

Onderwijsweek | Dag | Thema | Project | Kennissessie
--- | --- | --- | --- | ---
C2 | di | [Digitale & analoge I/O](./hardware-interfacing/communicatie/analoog-en-digitaal/README.md). Wat heb je minimaal nodig om een eigen microcontroller te kunnen aansturen? Week C2. We leren werken met vectoren in C++. We gebruiken een digitale pin om te registreren of een deur open en dicht gaat. | Uitleg retrospective en sprint review | C++ vector en condities if then else
C2 | wo | [Digitale & analoge I/O](./hardware-interfacing/communicatie/analoog-en-digitaal/README.md). | Werken aan project | C++ vector controle, dubbele for-loop
C2 | do | [Digitale & analoge I/O](./hardware-interfacing/communicatie/analoog-en-digitaal/README.md). | Werken aan project | C++ vector input, C++ oefenen met vectoren
C2 | vr | [Digitale & analoge I/O](./hardware-interfacing/communicatie/analoog-en-digitaal/README.md). | Show & Tell |

### Onderwijsweek C3

Onderwijsweek | Dag | Thema | Project | Kennissessie
--- | --- | --- | --- | ---
C3 | ma | Vakantie | |
C3 | di | Vakantie | |
C3 | wo | Vakantie | |
C3 | do | Vakantie | |
C3 | vr | Vakantie | |

### Onderwijsweek C4

Onderwijsweek | Dag | Thema | Project | Kennissessie
--- | --- | --- | --- | ---
C4 | ma | **Excursie** | Excursie glastuinbouw Westland | **Excursie volledige dag!**
C4 | di | We behandelen [actieve elektronica](./hardware-interfacing/elektronische-componenten/README.md) en het lezen van (sensor)data met behulp van het [1-Wire](./hardware-interfacing/communicatie/1-wire/) protocol. Met half duplex [I2C communicatie](./hardware-interfacing/communicatie/I2C/README.md) sluiten we een Real Time Clock (RTC) om de tijd bij te houden. Week C4. Een low-power clock-controlled IoT device met een Arduino Uno. Gebruik de clock om periodiek de temperatuur van de omgeving te meten. (Een P-channel mosfet voor het schakelen.) | Arduino Omgevging installeren | Datasheet lezen
C4 | wo | 1-Wire, I2C & RTC | Werken aan project | cpp en hpp files, includes, namespace
C4 | do | 1-Wire, I2C & RTC | Werken aan project | struct, compositie UML relatie, bits, uint8
C4 | vr | 1-Wire, I2C & RTC | Werken aan project | files i/o, fstream

### Onderwijsweek C5

Onderwijsweek | Dag | Thema | Project | Kennissessie
--- | --- | --- | --- | ---
C5 | di | We leren het gebruik van een (output) [schuifregister](./hardware-interfacing/elektronische-componenten/ic/74HC595/README.md). Bi-directionele communicatie met [SPI](./hardware-interfacing/communicatie/SPI/README.md) is een veel gebruikte bus in seriele communicatie. Zo kan je gegevens uitwisselen tussen sensoren en je microcontroller. Week C5. Met 8 leds simuleren we de stand van deuren en ramen we sturen deze aan met een 74HC595. Sluit een bme280 sensor aan om temperatuur en relatieve luchtvochtigheid uit te lezen en leer het gebruik van een driver. | | Schuifregister, libraries, recursie
C5 | wo | Schuifregister & SPI | Werken aan project | Functies schrijven, references en const, Goede naamgeving, vermijden van herhaling, Doxygen en documenteren
C5 | do | Schuifregister & SPI | Werken aan project |
C5 | vr | Schuifregister & SPI | Show & Tell | 

### Onderwijsweek C6

Onderwijsweek | Dag | Thema | Project | Kennissessie
--- | --- | --- | --- | ---
C6 | di | Een actor gebruik je om een actie te genereren. Soms moet dat ook met hogere voltages en gebruiken we een relais. Week C6. Schakel een grotere spanning met behulp van een [relais](./hardware-interfacing/elektronische-componenten/relais&SSR/README.md) voor het activeren van een [linear-actuator](./hardware-interfacing/elektronische-componenten/linear-actuator/README.md) om een raam of deur te openen. Je leert om een multimeter te gebruiken en een logic analyzer om hardware te debuggen. | Werken aan project | use-case & activity diagrammen
C6 | wo | Relais & Linear-actuator | Werken aan project | Multimeter
C6 | do | Relais & Linear-actuator | Werken aan project| Logic Analyzer
C6 | vr | Relais & Linear-actuator | **[1e Peilmoment](../TI-S2/Verantwoordingsdocument_TI_S2.md)** |

### Onderwijsweek C7

Onderwijsweek | Dag | Thema | Project | Kennissessie
--- | --- | --- | --- | ---
C7 | di | UART communicatie voor het aansluiten van randapparatuur. Een servo of LED-strip stuur je naukeurig aan met Pulse Width Modulatie (PWM). Week C7. We gebruiken [UART](./hardware-interfacing/communicatie/UART/README.md) om te communiceren tussen de [Arduino Uno](./hardware-interfacing/embedded/microcontroller/Arduino-UNO/README.md) en [Raspberry Pi](./hardware-interfacing/embedded/computer/Raspberry-Pi/README.md). Met [PWM](./hardware-interfacing/communicatie/analoog-en-digitaal/DAC/README.md) sturen we een ventilator en passen de snelheid aan op het gewenste niveau. | | UART
C7 | wo | UART communicatie & PWM | | PWM
C7 | do | UART communicatie & PWM | |
C7 | vr | UART communicatie & PWM | Show & Tell |

### Onderwijsweek C8

Onderwijsweek | Dag | Thema | Project | Kennissessie
--- | --- | --- | --- | ---
C8 | di | Om data van A naar B krijgen heb je datacommunicatie nodig, opslag en visualisatie. Week C8. We communiceren sensor-data met [MQTT](./software/communicatie/MQTT/README.md), [PostgreSQL](./infrastructuur/OS/Raspberry-Pi-OS/README.md) voor dataopslag, [Node-RED](./software/visueel-programmeren/Node-RED/README.md) voor het visueel programmeren en [Flask](./software/webserver/Flask/README.md) om een eenvoudige webserver te maken. De verschillende services draai je in [Docker](./infrastructuur/Docker/README.md) containers. | | Docker & MQTT
C8 | wo | Node-Red, PostgreSQL, MQTT, Flask & Docker | |  PostgreSQL & Node-Red
C8 | do | Node-Red, PostgreSQL, MQTT, Flask & Docker | | Flask
C8 | vr | **Goedevrijdag** | |

### Onderwijsweek C9

Onderwijsweek | Dag | Thema | Project | Kennissessie
--- | --- | --- | --- | ---
C9 | di | | |
C9 | wo | | |
C9 | do | | |
C9 | vr | | |

### Onderwijsweek C10

Onderwijsweek | Dag | Thema | Project | Kennissessie
--- | --- | --- | --- | ---
C10 | di | | |
C10 | wo | | |
C10 | do | | |
C10 | vr | | |
