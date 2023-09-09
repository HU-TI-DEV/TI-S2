![logo](img/1-Wire-Protocol.png) [](logo-id)

# Communicatieprotocol: 1-Wire[](title-id)

### Inhoud[](toc-id)

- [Communicatieprotocol: 1-Wire](#communicatieprotocol-1-wire)
    - [Inhoud](#inhoud)
  - [Een introductie](#een-introductie)
    - [Bus systeem](#bus-systeem)
    - [Serieel protocol](#serieel-protocol)
    - [Parallel protocol](#parallel-protocol)
    - [1-Wire](#1-wire)
    - [Daisy chain topologie](#daisy-chain-topologie)
    - [Ster topologie](#ster-topologie)
    - [DS18B20 temperatuursensor](#ds18b20-temperatuursensor)
  - [De schakeling](#de-schakeling)
  - [Arduino voorbeeld code](#arduino-voorbeeld-code)
  - [Referenties](#referenties)

---

**v0.1.0 [](version-id)** Start document voor 1-Wire uitleg en voorbeeld code. Harm Snippe[](author-id).

---

## Een introductie

1-Wire is een communicatieprotocol wat sterk lijkt op [I<sup>2</sup>C](../I2C/README.md) datacommunicatie. Er is echter minder dataoverdracht mogelijk bij een lagere snelheid. De afstand die overbrugt kan worden is echter wel groter. Deze vorm van communicatie zie je vaak terug in goedkope sensor toepassingen zoals het meten van temperatuur. Dit bus systeem is ontwikkeld door Dallas Semiconductor Corporation daarom spreken we ook wel van Dallas 1-Wire. Bij definitie gebruikt 1-Wire slechts een enkele lijn voor voeding en dataoverdracht.

### Bus systeem
Een bus is in de computertechniek een manier om verschillende componenten in een computer of tussen computers op een standaard manier te verbinden. Een bus voldoet vaak aan een standaard.

### Serieel protocol
Een serieel protocol voor gegevensoverdracht stuurt alle bits informatie één voor één door. Omdat er minder signalen gelijktijdig worden verzonden is een goedkopere kabel mogelijk. Voor de komst van USB(universal serial bus) waren de meeste computers uitgerust met een seriele interface voor het aansluiten van bijvoorbeeld randapparatuur zoals muis en toetsenbord.

### Parallel protocol
Bij parallelle communicatie worden er zoveel mogelijk bits gelijktijdig verzonden over een verzameling van kabels. Gegevensoverdracht is wel hoger, maar bovendien complexer omdat data dat over verschillende kabels gaat synchroon moet blijven. Seriële communicatie is daardoor zeer populair gebleven ook omdat daar geen grote connectoren voor nodig zijn die ook nog eens makkelijk kunnen beschadigen.

    PCI-E
    PCI Express is een vorm van parallele communicatie. Daar heeft echter elke data lijn een eigen clock-signaal. Er kan dus over meerdere kabels informatie verzonden worden zonder dat er synchronisatie issues ontstaan.

### 1-Wire
1-Wire is een twee draads bus systeem. Er is een draad nodig voor de data communicatie en mogelijk de voeding en een andere draad wordt gebruikt als aarde. Elk component in een 1-Wire bus systeem heeft een uniek 64 bit adresseerbaar adres om sensor data op te halen. In theorie kan je aan een 1-Wire netwerk meer dan honderd sensoren koppelen.

Er zijn twee mogelijke manieren om sensoren aan te sluiten. In 'Parasite' mode is de data (DQ) lijn tevens de voedingsspanning van 5V+.

    Bij sommige sensoren is het in dit geval noodzakelijk pin 3 en 1 te verbinden met een 100nF condensator.

Bij grote netwerken wordt een derde draad gebruikt voor het leveren van de voedingsspanning. Dit is de 'regular' of non parasatic mode.

### Daisy chain topologie
Wanneer je sensoren steeds aan elkaar doorverbind dan heb je een Daisy chain topologie. De sensoren staan als het ware in serie met elkaar.

### Ster topologie
Zoals de naam al aangeeft zijn de sensoren bij een ster topologie met 1 centraal punt gekoppeld. De sensoren in het netwerk staan parallel verbonden met de centrale 1-Wire controller.
 
### DS18B20 temperatuursensor
Om temperatuur te meten kan je gebruik maken van DS18B20 temperatuursensor. Dit is een digitale sensor met een 1-Wire interface. De sensor komt in verschillende vormen in dit voorbeeld maken we gebruik van een waterdichte variant.

 De DS18B20 met drie poten lijkt erg op een [transistor](../elektronische-componenten/transistor/README.md) maar is dit niet. Let goed op wat je gebruikt.


## De schakeling
De waterdichte DS18B20 versie heeft drie draden: rood, zwart en geel of wit. Rood is de voeding 5V, zwart naar ground en geel of wit is de data pin. Gebruik een pull-up weerstand voor de data pin. De signaal pin komt zo niet in een 'zwevende' staat. 

![img url](../1-wire/files/Arduino_DS18B20_probe_bb.png?raw=true "Schakeling voor de DS18B20")


- De 5V op de Arduino -> rood van de temperatuursensor
- De pin 12 op de Arduino -> geel of wit temperatuursensor (signaal)
- De GND op de Arduino -> zwart van de temperatuursensor

## Arduino voorbeeld code

```arduino
//1-Wire Arduino sketch for BS18B20 waterproof temperature sensor

#include <OneWire.h>
#include <DallasTemperature.h>

float temp = 0.0;
int oneWireBus = 12;
OneWire oneWire(oneWireBus);
DallasTemperature sensors(&oneWire);

void setup() {
  Serial.begin(9600);
  Serial.println("1-Wire Arduino sketch for BS18B20 waterproof temperature sensor");
  sensors.begin();
}

void loop() {
  sensors.requestTemperatures();
  temp = sensors.getTempCByIndex(0);

  Serial.print("Temperature reading: ");
  Serial.println(temp);

  delay(5000);
}
```
[Arduino bestand](../1-wire/files/Arduino_DS18B20_probe/Arduino_DS18B20_probe.ino) 

## Referenties

- 1-Wire (<https://en.wikipedia.org/wiki/1-Wire>)