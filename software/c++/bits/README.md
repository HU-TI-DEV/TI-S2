# Bits [](title-id)

## Inhoud[](toc-id)
- [Bits ](#bits-)
  - [Inhoud](#inhoud)
    - [bitstring, byte](#bitstring-byte)
    - [tellen](#tellen)


Gegevens worden in het geheugen opslagen als bitjes. In C++ is het mogelijk om
op bitniveau te opereren door middel van **bitoperatoren**. Het op bitniveau opereren
hebben we als Technische Informatici nodig om hardware aan te sturen en uit te lezen. 

In dit hoofdstuk behandelen we bitoperatoren en bit statements (veelgebruikte combinaties van bitoperatoren).
In de voorbeelden in dit hoofdstuk zien we dat de variabelen van het datatype `uint8_t` zijn. Dit is omdat het aantal bitjes dat wordt gebruikt voor de meeste datatypes wisselt tussen de verschillende implementaties van C++. Voor `uint8_t` geldt wel dat het altijd uit slechts één byte bestaat<sup>[1](#uint8)</sup>.

De bitoperatoren werken ook op andere datatypes,
maar het kan zijn dat dezelfde code, afhankelijk van de compiler, een ander resultaat geeft!
Verder gebruiken we de `library bitset` en het datatype bitset. Deze gebruiken we om de bit-waarde makkelijk te printen<sup>[2](#bitprint)</sup>.

### bitstring, byte
Voordat we naar de bitoperatoren gaan is het nog belangrijk om te realiseren hoe we over reeksen van bitjes praten. Een reeks bitjes noemen we een *bitstring*. Een
bitstring van 8 bitjes noemen we een *byte*. 

### tellen
De bitjes van een bitstring nummeren van
rechts naar links waarbij we beginnen met tellen bij 0. 
Voorbeeld: als we de bitstring
1101 hebben, dan is het 0de bitje 1, het 1e bitje 0, het 2e bitje 1 en het 3e bitje 1.

<a name="uint8">1</a>: *uint8_t is een unsigned integer van 8 bits. In C++ hebben we ook de datatypes uint16_t, uint32_t en uint64_t. Dit zijn unsigned integers met respectievelijk 16, 32 en 64 bits. Daarnaast hebben we ook int8_t, int16_t, int32_t en int64_t. Dit zijn signed integers met respectievelijk 8, 16, 32 en 64 bits. Deze
grotere datatypes gebruiken we niet omdat dit de voorbeelden onduidelijker maakt.*

<a name="bitprint">2</a>: *De library bitset heeft ook andere handige functionaliteiten. Deze mogen tijdens deze cursus echter niet worden gebruikt. Zonder deze functionaliteiten kunnen we ons beter focussen op het begrijpen en toepassen van de bitoperatoren.*