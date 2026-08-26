# Je eigen library en applicatie  <!-- omit in toc -->

Zodra je plan van aanpak door een vakdocent is goedgekeurd, kun je die in deze opdracht uitvoeren en uploaden.

### Inhoud[](toc-id) <!-- omit in toc -->

- [Eisen oplevering](#eisen-oplevering)
- [Persoonlijk assessment](#persoonlijk-assessment)
- [Reflectieverslag](#reflectieverslag)
- [Spelregels van deze opdracht](#spelregels-van-deze-opdracht)
- [Eisen aan Kwaliteit en Functionaliteit](#eisen-aan-kwaliteit-en-functionaliteit)
  - [Checklist](#checklist)
  - [Verder letten we op](#verder-letten-we-op)
- [Afbakening](#afbakening)
- [Ter inspiratie](#ter-inspiratie)

## Eisen oplevering

Wat je oplevert is een zip van:

- Het goedgekeurde PVA,
- Je zelfgeschreven library,
- De bijbehorende test-code,
- De bijbehorende applicatie waarin je zelfgeschreven library goed tot zijn recht komt.
- Daarnaast een link naar de code in je git-repo.

## Persoonlijk assessment

Na een eerste controle van je inlevering wordt je uitgenodigd voor een assessment met een vakdocent. Tijdens het assessment vraagt de vakdocent om je testcode en applicatie te demonstreren. Verder zal hij feedback leveren op het product en je steekproefsgewijs bevragen over je code. Bijvoorbeeld welk deel van de datasheet je hebt gebruikt voor een bepaald stuk code.

## Reflectieverslag

Na afloop van het assessment wordt je gevraagd om een kort reflectieverslag over deze opdracht te schrijven en die hier ook te uploaden.
Neem daarin de volgende kopjes op:

- Wat was jouw verwachting van deze opdracht?
- Klopt je verwachting met wat er is gebeurd?
- Wat was je belangrijkste les? Geef een voorbeeld.
- Hoe heb je de opdracht ervaren?
- Wat is de invloed op je persoonlijke ontwikkeling?
- Wat zou je een volgende keer anders doen?

## Spelregels van deze opdracht

Voor deze opdracht gelden een aantal spelregels.

- Je PVA (en daarmee je chip) was goedgekeurd.
- Je hebt je library zelf geschreven, op basis van de datasheet van een chip.
- Je hebt voor je library geen andere libraries gebruikt dan de "vanilla" Arduino IDE libraries.\
  Dus bijvoorbeeld wel: Wire, SPI. Maar niet: Dallas libraries.
- Voor de library interface is Doxygen documentatie gemaakt.
- Voor je demonstratie-applicatie mag je alle additionele libraries gebruiken die je maar wil, zolang
voor je eigen chip maar je zelfgeschreven library gebruikt wordt.

## Eisen aan Kwaliteit en Functionaliteit

Via deze opdracht toon je een aantal capaciteiten aan. De onderstaande checklist helpt je een beeld te krijgen van in hoeverre je op de goede weg bent. Loop die goed door voordat je je werk hier inlevert.

### Checklist

- Goed leesbare en begrijpbare code

- De code gebruikt een consistente taal (ofwel Engels (voorkeur), ofwel Nederlands)

- Consistente code stijl: Gebruik bij voorkeur `camelCase` voor functie- en variabelenamen.

- Klassen beginnen met hoofdletter.

- Interface klassen krijgen daarnaast de letter `I` ervoor.

  Voorbeelden: getInsideTemperature(), float insideTemperature, `class ITemperatureSensor`.

- Functienamen zijn commando's of vragen:\
  temperature() is dus geen goede functienaam, readCurrentTemperature() is beter

- Gebruik voor setten en getten de prefixes set en get (ook bij Nederlands):\
  getTemperature(), setTemperature(float temp).

- Gebruik voor uitlezen van een boolean waarde de prefix "is" (ook bij Nederlands):\
  isTemperatureAboveThreshold().

- Voorkom repetative code.
  
  Als op meerdere plekken in de code blokken code staan die gelijk zijn of veel op elkaar lijken, is dat een aanwijzing dat er een functie voor gemaakt moet worden.

  Elk van die blokken kan dan vervangen worden door een aanroep naar die functie.

  Of soms kan een enkel blok blijven staan, en kan er een loop-constructie geschreven worden.

- Gebruik liever langere namen die duidelijk zijn dan korte namen die je later kan vergeten.

  Dus geen getT() maar (afhankelijk van wat je bedoelt) getTemperature(), getTime(), getCharacterT().

- Geen 'schapen met 5 poten'!

  Probeer zoveel mogelijk de verantwoordelijkheid per klasse te scheiden.

  Als je chip zelf een schaap met meer poten is (hij kan temperatuur, luchtdruk, CO2 en meer meten),
  is het prima om een klasse te schrijven die dat allemaal kan, bijvoorbeeld class MultiSensor3000 oid.

  Het is wel aan te bevelen om die klasse dan af te leiden van meerdere abstracte basisklassen / Interface klassen, in dit geval van ITemperatuurSensor, ILuchtdrukSensor, ICO2Sensor etc.

  Dat leidt tot flexibiliteit (in chip-keuze) en herbruikbare code.

- Hetzelfde geldt voor functies.

  - Combineer binnen een functie niet twee dingen die eigenlijk los van elkaar staan.
    Maak daar aparte functies voor.

  - Niet te grote functies.

    Als functies groot of diep genest worden, verlaagt dat de leesbaarheid en is afsplitsing van functies aan te bevelen.

- Expose (maak beschikbaar) alleen het relevante deel van de library.

  Maak dus alleen de functies `public` waar de gebruiker iets met (moet) doen.

- Gebruik geen globale variabelen.

- Gebruik geen publieke variabelen in klassen, behalve bij pure data-classes -
  gebruik daarvoor voor de duidelijkheid structs in plaats van klassen.

- Gebruik geen `#define`s.

  Gebruik in plaats daarvan `const` variabelen, of in geval van functies of klassen `templates`.

- Initialiseer members zoveel mogelijk in de `initialiser list`.

- Gebruik geen "magic numbers".

  Dus niet Wire.start(0x42) maar Wire.start(i2cAddressTempSensor), waarbij i2cAddressTempSensor een constante is.

  Als je een lijst met veel van die constante waarden hebt die bij elkaar horen, splits die dan af in een header file.

- Splits elke klasse op in een header file `*.hpp` (declaratie) en source file `*.cpp` (definitie).

- Gebruik geen dynamisch geheugen in je library:

  Gebruik dus geen new() en delete() of malloc() en free() in je library, maar prealloceer de data (= maak een array of vector aan).

### Verder letten we op

- Compleetheid van de functionaliteit.

  Ondersteunt je library alle mogelijke functionaliteit van de chip?

  Zo niet, wat niet, en wat waren je afwegingen daarbij?

- Complexiteit.

  We zijn uiteraard meer onder de indruk van wat complexere chips en/of een wat complexere applicatie.

  Als de ene wat mager is, hopen we dat de ander daarvoor compenseert.
  (Eenvoudigere chip -> complexere applicatie!)

  (NB: de code zelf zien we liefst zo min mogelijk complex, dus zo duidelijk mogelijk.)

- Fun van de applicatie.

  Goede werking, bug-vrijheid van de applicatie. Leuk en vriendelijk interface.

## Afbakening

- In jouw C++ code hoef je geen switch-case te gebruiken.
- Voor jouw tests hoef je geen Catch2 te gebruiken.

(Als je het toch doet en deze constructies goed gebruikt kan je daarmee jouw professionele houding tonen. Ook in een bedrijf is "over het bordje kijken" belangrijk en gewardeerd.)

## Ter inspiratie

[Arduino library repositories en aantekeningen](./library-voorbeelden.md).
