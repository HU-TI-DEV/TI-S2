![logo](../SPI/img/SPI_basic_operation,_single_Main_&_Sub.svg) [](logo-id)

# SPI: Serial Peripheral Interface[](title-id) <!-- omit in toc -->

### Inhoud[](toc-id) <!-- omit in toc -->

- [Een introductie](#een-introductie)
- [SPI protocol](#spi-protocol)
- [De schakeling om individueel te oefenen](#de-schakeling-om-individueel-te-oefenen)
- [De schakeling met je team](#de-schakeling-met-je-team)
- [Arduino voorbeeld code](#arduino-voorbeeld-code)
- [Referenties](#referenties)

---

**v0.1.1 [](version-id)** Start document voor SPI door HU IICT[](author-id).

---

## Een introductie

SPI (Serial Peripheral Interface) is een communicatiestandaard waarbij één chip, de master, bepaalt welke van de andere chips (slaves) mag communiceren over de bus. De SPI-aansluiting bestaat in haar meest simpele vorm uit twee datalijnen en een kloklijn. De eerste datalijn heet MOSI (Master Out Slave In) hierover wordt de data van de master naar een slave gestuurd. De tweede datalijn is de MISO (Master In Slave Out) hierover wordt de data van een slave naar de master gestuurd. De kloklijn, SCLK (Serial CLocK), is er om aan te geven wanneer de volgende bit wordt verstuurd over de datalijn. Het signaal van de kloklijn wordt gegenereerd door de master.

> Om de associatie met slavernij te voorkomen is het voorstel gedaan om de pin referenties in relatie tot SPI aan te passen. [A Resolution to Redefine SPI Signal Names](<https://www.oshwa.org/a-resolution-to-redefine-spi-signal-names/>). Deze terminologie is nog niet volledig overgenomen in dit document.

![SPI met één master en één slave.](../SPI/img/SPI_master_slave.png)

In bovenstaand figuur zien we een master en een slave die voor SPI op elkaar zijn aangesloten. Over de MOSI- en de MISO-lijnen wordt de data één bit tegelijk verstuurd. We kunnen het geheel dus zien als een cyclische schuifregister die deels in de master zit en deels in de slave zit.

![SPI met één master en drie slaves.](../SPI/img/SPI_three_slaves.png)

Het is ook mogelijk om met SPI meerdere slaves op de master aan te sluiten waarbij de slaves de MOSI- en de MISO-lijnen delen. Wel hebben we dan per slave een selectielijn, SS (Slave Select), nodig om aan te geven welke slave mag communiceren met de master. De master stuurt deze SS-lijnen aan. Bovenstaand figuur laat een SPI aansluiting met meerdere slaves zien. De SS-lijnen zijn meestal active low, dat betekent dat de lijn van de slave die actief is een laag signaal heeft en de andere een hoog signaal hebben.

![De aansluitingen van een 74HC595 output schuifregister](../SPI/img/74HC595_intern.png)  ![](../SPI/img/74HC595.png) ![](../SPI/img/74HC595_img.png)

In bovenstaand figuur zien we de [74HC595](../../elektronische-componenten/ic/74HC595/README.md) schuifregister. Door deze als slave via SPI aan te sluiten op je Arduino kan je het aantal output pinnen van je Arduino vergroten. Je kan ook het aantal input pinnen verhogen door een SN74LS598 schuifregister aan te sluiten. SPI heb je ook nodig om met sommige sensoren en actuatoren te communiceren en natuurlijk kan je SPI gebruiken om twee Arduino’s met elkaar te laten communiceren.

> Er kunnen ook andere reden zijn om een schuifregeister te gebruiken omdat er dan bijvoorbeeld minder draden hoeven te lopen van de micro-controller naar de plek waar de IO pinnen nodig zijn. Of omdat de pinnen van een extender chip vaak meer stroom kunnen leveren dan die van een micro-controller. Of gewoon omdat de pinnen van de micro-controller op zijn: goedkope micro-controllers hebben vaak veel minder IO pinnen. Een PIC10F200 heeft er bijvoorbeeld maar 6.

## SPI protocol

Het SPI protocol kan je op verschillende manieren implementeren. De Arduino Uno heeft een peripheral (speciaal stukje hardware op de chip) dat het SPI protocol implementeert. Als je de maximale snelheid van dataoverdracht wil bereiken dan moet je deze peripheral gebruiken, maar dat is niet triviaal, en hoe je zo’n peripheral precies moet aansturen verschilt van chip tot chip.

## De schakeling om individueel te oefenen

De volgende schakeling maak je **individueel**. De voorbeeldcode laat de SPI communicatie zien met een [128x64 SPI OLED display](https://hu-hbo-ict.gitlab.io/turing-lab/ti-lab-shop/oled%20spi%20128%20x%2064.html).

Installeer eerst de Adafruit SSD1306 and Adafruit GFX libraries en de daarvan afhankelijke bibliotheken.

![Voorbeeld SSD1306](./img/SSD1306.png)

Sluit de OLED display als volgt aan op de Arduino Uno.

| OLED pin | Arduino Uno pin|
| --- | --- |
| VCC | 5V |
| GND | GND |
| SCL (CLK) | 13 (SCK) |
| SDA (MOSI) | 11 (MOSI) |
| RES | 9 |
| DC | 8 |
| CS (SS) | 10 |

Compileer en upload de volgende voorbeeld sketch.

```Arduino
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Define OLED display SPI pins
#define OLED_MOSI   11  // Hardware SPI MOSI
#define OLED_CLK    13  // Hardware SPI SCK
#define OLED_DC     8   // Data/Command
#define OLED_CS     10  // Chip select
#define OLED_RESET  9

// Initialize display
Adafruit_SSD1306 display(128, 64, &SPI, OLED_DC, OLED_RESET, OLED_CS);

void setup() {
    Serial.begin(9600);

    // Initialize the OLED display
    if (!display.begin(SSD1306_SWITCHCAPVCC)) {
        Serial.println(F("SSD1306 initialization failed!"));
        while (true) {
          //blink LED to indicate error
          digitalWrite(LED_BUILTIN, HIGH);
          delay(500);
          digitalWrite(LED_BUILTIN, LOW);
          delay(500);
        }

    }

    display.clearDisplay(); // Clear display
    display.setTextSize(2); // Text size
    display.setTextColor(WHITE); // Set text color
    display.setCursor(10, 20); // Move cursor
    display.println("Hello TI!"); // Print line
    display.display(); // Show the message on the display
}

void loop() {
    // Nothing here, just displaying "Hello TI!"
}

```

Waarom is er geen MISO verbinding? Wat zou de DC (DATA/COMMAND) verbinding voor zijn? Uitdagend: Wat is in de code een F() macro en waarom zouden we het gebruiken?

## De schakeling met je team

De volgende schakeling maak je **samen met je team**. Er is één  BME280 per team aanwezig.

De BME280 is een luchtdruk- en temperatuur en (relatieve)luchtvochtigheid sensor van Bosch. De sensor kan gevoed worden met 3V3-5V. De module heeft een logic level shifter voor de SDA en SCL lijn. Je kunt dus ook aansluiten via [I<sup>2</sup>C](../I2C/README.md) op 3V3. In dit voorbeeld demonsteren wij een aansluiting via (hardware) SPI. De naamgeving kan verwarrend zijn. Kijk naar de afbeelding voor de juiste benaming voor SPI bij deze module.

> Luchtdruk is een indicator van het weer. Wanneer er een laag-drukgebied ons land binnenkomt wijst dat op de komst van wolken, wind en regen. Een hoog-drukgebied wijst daarentegen op mooi en zonnig weer. Verandering van luchtdruk kan je dus gebruiken voor het voorspellen van het weer.

![BME280](../SPI/img/BME280_bb.png)

## Arduino voorbeeld code

Je kunt de BME280 library gebruiken van Adafruit. Pas dan de interface aan van I<sup>2</sup>C naar hardware of software SPI.

- [Arduino voorbeeld code voor BME280](../SPI/files/bme280test/bme280test.ino)

Er is ook een versie zonder luchtvochtigheid sensor de BMP280. Deze is goedkoper en beter beschikbaar in de [TI lab shop] (<https://hu-hbo-ict.gitlab.io/turing-lab/ti-lab-shop/BMP280%20sensor%20module.html>).

- [Arduino voorbeeld code voor BMP280](../SPI/files/bmp280test/bmp280test.ino)

## Referenties

- SPI (<https://en.wikipedia.org/wiki/Serial_Peripheral_Interface>)
- Adafruit BME280 (<https://github.com/adafruit/Adafruit_BME280_Library>)

BME280

- [BME280 Datasheet (PDF)](./files/bst-bme280-ds002.pdf)
- [Bosch Sensortec BME280 page](https://www.bosch-sensortec.com/products/environmental-sensors/humidity-sensors-bme280/)

BMP280

- [BMP280 Datasheet (PDF)](./files/bst-bmp280-ds001.pdf)
- Bosch Sensortec BMP280 page: removed, see Archive.org for a copy: <https://web.archive.org/web/20250615055645/https://www.bosch-sensortec.com/products/environmental-sensors/pressure-sensors/bmp280/>
