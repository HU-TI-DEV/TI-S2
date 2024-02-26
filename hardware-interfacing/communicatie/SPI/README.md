![logo](../SPI/img/SPI_basic_operation,_single_Main_&_Sub.svg) [](logo-id)

# SPI: Serial Peripheral Interface[](title-id)

### Inhoud[](toc-id)

- [SPI: Serial Peripheral Interface](#spi-serial-peripheral-interface)
    - [Inhoud](#inhoud)
  - [Een introductie](#een-introductie)
  - [SPI protocol](#spi-protocol)
  - [De schakeling](#de-schakeling)
  - [Arduino voorbeeld code](#arduino-voorbeeld-code)
  - [Referenties](#referenties)

---

**v0.1.0 [](version-id)** Start document voor SPI door HU IICT[](author-id).

---

## Een introductie

SPI (Serial Peripheral Interface) is een communicatiestandaard waarbij één chip, de master, bepaalt welke van de andere chips (slaves) mag communiceren over de bus. De SPI-aansluiting bestaat in haar meest simpele vorm uit twee datalijnen en een kloklijn. De eerste datalijn heet MOSI (Master Out Slave In) hierover wordt de data van de master naar een slave gestuurd. De tweede datalijn is de MISO (Master In Slave Out) hierover wordt de data van een slave naar de master gestuurd. De kloklijn, SCLK (Serial CLocK), is er om aan te geven wanneer de volgende bit wordt verstuurd over de datalijn. Het signaal van de kloklijn wordt gegenereerd door de master.

    Om de associatie met slavernij te voorkomen is het voorstel gedaan om de pin referenties in relatie tot SPI aan te passen. [A Resolution to Redefine SPI Signal Names](<https://www.oshwa.org/a-resolution-to-redefine-spi-signal-names/>). Deze terminologie is nog niet volledig overgenomen in dit document.

![SPI met één master en één slave.](../SPI/img/SPI_master_slave.png)

In bovenstaand figuur zien we een master en een slave die voor SPI op elkaar zijn aangesloten. Over de MOSI- en de MISO-lijnen wordt de data één bit tegelijk verstuurd. We kunnen het geheel dus zien als een cyclische schuifregister die deels in de master zit en deels in de slave zit.

![SPI met één master en drie slaves.](../SPI/img/SPI_three_slaves.png)

Het is ook mogelijk om met SPI meerdere slaves op de master aan te sluiten waarbij de slaves de MOSI- en de MISO-lijnen delen. Wel hebben we dan per slave een selectielijn, SS (Slave Select), nodig om aan te geven welke slave mag communiceren met de master. De master stuurt deze SS-lijnen aan. Bovenstaand figuur laat een SPI aansluiting met meerdere slaves zien. De SS-lijnen zijn meestal active low, dat betekent dat de lijn van de slave die actief is een laag signaal heeft en de andere een hoog signaal hebben.

![De aansluitingen van een 74HC595 output schuifregister](../SPI/img/74HC595_intern.png)  ![](../SPI/img/74HC595.png) ![](../SPI/img/74HC595_img.png)

In bovenstaand figuur zien we de [74HC595](../../elektronische-componenten/ic/74HC595/README.md) schuifregister. Door deze als slave via SPI aan te sluiten op je Arduino kan je het aantal output pinnen van je Arduino vergroten. Je kan ook juist het aantal input pins verhogen door een SN74LS598 schuifregister aan te sluiten. SPI heb je ook nodig om met sommige sensoren en actuatoren te communiceren en natuurlijk kan je SPI ook gebruiken om twee Arduino’s met elkaar te laten communiceren.

    Er kunnen ook een andere reden zijn om een schuifregeister te gebruiken omdat er dan bijvoorbeeld minder draden hoeven te lopen naar van de micro-controller naar de plek waar de IO pinnen nodig zijn. Of omdat de pinnen van een extender chip vaak meer stroom kunnen leveren dan die van een micro-controller. Of gewoon omdat de pinnen van de micro-controllerr op zijn: goedkope micro-controllerrollers hebben vaak veel minder IO pinnen. Een PIC10F200 heeft er bijvoorbeeld maar 6.

## SPI protocol

Het SPI protocol kan je op verschillende manieren implementeren. De Arduino Uno heeft een peripheral (speciaal stukje hardware op de chip) dat het SPI protocol implementeert. Als je de maximale snelheid van dataoverdracht wil bereiken dan moet je deze peripheral gebruiken, maar dat is niet triviaal, en hoe je zo’n peripheral precies moet aansturen verschilt van chip tot chip.

## De schakeling

De BME280 is een luchtdruk- en temperatuur en (relatieve)luchtvochtigheid sensor van Bosch. De sensor kan gevoed worden met 3V3-5V. De module heeft een logic level shifter voor de SDA en SCL lijn. Je kunt dus ook aansluiten via [I<sup>2</sup>C](../I2C/README.md) op 3V3. In dit voorbeeld demonsteren wij een aansluiting via (hardware) SPI. De naamgeving kan verwarrend zijn. Kijk naar de afbeelding voor de juiste benaming voor SPI bij deze module. 

    Luchtdruk is een indicator van het weer. Wanneer er een laag-drukgebied ons land binnenkomt wijst dat op de komst van wolken, wind en regen. Een hoog-drukgebied wijst daarentegen op mooi en zonnig weer. Verandering van luchtdruk kan je dus gebruiken voor het voorspellen van het weer.

![BME280](../SPI/img/BME280_bb.png)

## Arduino voorbeeld code

Je kunt de BME280 library gebruiken van Adafruit. Pas dan de interface aan van I<sup>2</sup>C naar hardware of software SPI.

Arduino voorbeeld [code](../SPI/files/bme280test/bme280test.ino)

Er is ook een versie zonder luchtvochtigheid sensor de BMP280. Deze is goedkoper en beter beschikbaar in de [TI lab shop] (https://hu-hbo-ict.gitlab.io/turing-lab/ti-lab-shop/BMP280%20sensor%20module.html).

Arduino voobeeld [code](../SPI/files/bmp280test/bmp280test.ino)

## Referenties

- SPI (<https://en.wikipedia.org/wiki/Serial_Peripheral_Interface>)
- Adafruit BME280 (<https://github.com/adafruit/Adafruit_BME280_Library>)