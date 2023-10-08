![logo](/hardware-interfacing/communicatie/SPI/img/SPI_timing_diagram_CS.svg) [](logo-id)

# Communicatie[](title-id)

### Inhoud[](toc-id)

- [Communicatie](#communicatie)
    - [Inhoud](#inhoud)
  - [Een introductie](#een-introductie)
  - [Referenties](#referenties)

---

**v0.1.0 [](version-id)** Start document voor communicatieprotocollen door HU IICT[](author-id).

---

## Een introductie

Bij communicatie tussen twee chips of elektronische onderdelen spreken we vaak over een bus waarover de communicatie gaat. Een bus is de hardware waar de communicatie over heen gaat (draadjes en pins). Echter enkel de hardware is niet voldoende om communicatie op te zetten. Er moet ook worden gedefinieerd hoe de data over de bus wordt verstuurd. Dit noemen we een communicatieprotocol. In literatuur wordt de term bus soms gebruikt voor enkel de hardware en soms voor de combinatie hardware en communicatieprotocol. Dit komt doordat de meeste communicatieprotocollen niet zonder een specifieke hardware bus kunnen. De twee meest extreme vormen van een hardware bussen zijn een bus met maar 1 draad en een bus met evenveel draadjes als databits die verstuurd moet worden.

Bij een bus met maar 1 draad moet de databits achter elkaar (serieel) verstuurd worden. Aangezien we maar één draad hebben kunnen we niet aangeven wanneer één bit is verzonden en de volgende begint. Het verschil tussen twee bitjes met de zelfde waarde of de data die gewoon langzaam wordt gestuurd is niet te zien. Het voordeel is wel dat we weinig hardware (draaden en I/O-pinnen) nodig hebben.

Een bus met even veel draadjes als de hoeveelheid databits die gestuurd moeten worden heeft ook uitdagingen. Allereerst zijn er hoge kosten voor de hardware. Niet enkel qua geld, maar ook qua ruimte. Onze elektronica willen we steeds kleiner. Het is daarom zonde om veel ruimte kwijt te zijn aan draadjes en I/O-pinnen. Daarbij is een dergelijke bus niet echt flexibel. Als er meer databits verstuurt moeten worden moet de hardware worden aangepast. Een voordeel is wel dat de data snel wordt verzonden.

Er zijn veel verschillende bussen en communicatieprotocollen. Iedere combinatie bus + communicatieprotocol maakt een andere overweging en eindigd qua voor en nadelen tussen de bovenstaand genoemde extreeme vormen. Hier behandelen we [SPI](../communicatie/SPI/README.md) en [I2C](../communicatie/I2C/README.md), de populairste bus en communicatieprotocol combinaties voor de communicatie tussen chips. Daarnaast leren we [1-Wire](../communicatie/1-wire/README.md) te gebruiken en het uitwisselen van data via [analoge en digitale signalen](../communicatie/analoog-en-digitaal/README.md).

Om sensordata uit te wisselen met een Arduino Uno en Raspberry Pi 4 kunnen we gebruik maken van UART. Een veel gebruikte seriele interface om randapparatuur aan te sluiten.

## Referenties
- Serial Peripheral Interface (<https://en.wikipedia.org/wiki/Serial_Peripheral_Interface>)