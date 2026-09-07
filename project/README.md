# Sensorbol voor een blusrobot

![Sensorbol](image.png)

<!-- omit in toc -->

### Inhoud
<!-- omit in toc -->

- [Sensorbol voor een blusrobot](#sensorbol-voor-een-blusrobot)
    - [Inhoud](#inhoud)
- [De toekomst van brandbestrijding](#de-toekomst-van-brandbestrijding)
- [Futurised](#futurised)
- [Waarom een sensorbol?](#waarom-een-sensorbol)
- [Projectopdracht](#projectopdracht)
  - [Doel](#doel)
- [De sensorbol](#de-sensorbol)
- [Wat moet de sensorbol kunnen?](#wat-moet-de-sensorbol-kunnen)
  - [1. Meten](#1-meten)
  - [2. Verwerken](#2-verwerken)
- [Deliverables](#deliverables)
  - [1. Conceptdocument](#1-conceptdocument)
  - [2. Requirements](#2-requirements)
  - [3. Proof of Concept](#3-proof-of-concept)
  - [4. Testplan](#4-testplan)
  - [5. Demonstratie](#5-demonstratie)
- [Technische uitdagingen](#technische-uitdagingen)
  - [Sensoren](#sensoren)
- [Inspiratie](#inspiratie)
  - [Concept A — Temperatuur en luchtvochtigheid](#concept-a--temperatuur-en-luchtvochtigheid)
    - [Doel](#doel-1)
    - [Sensoren](#sensoren-1)
    - [Mogelijke toepassing](#mogelijke-toepassing)
    - [Uitbreiding](#uitbreiding)
  - [concept B — Rook en luchtkwaliteit](#concept-b--rook-en-luchtkwaliteit)
    - [Doel](#doel-2)
    - [Sensoren](#sensoren-2)
    - [Belangrijk](#belangrijk)
  - [Concept C — Omgevingslicht](#concept-c--omgevingslicht)
    - [Doel](#doel-3)
    - [Sensoren](#sensoren-3)
  - [Concept D — Gecombineerde sensorbol](#concept-d--gecombineerde-sensorbol)
    - [Doel](#doel-4)
- [Testen](#testen)
  - [Test 1 — Sensor](#test-1--sensor)
  - [Test 2 — Communicatie](#test-2--communicatie)
  - [Test 3 — Bereik](#test-3--bereik)
  - [Test 4 — Herhaalbaarheid](#test-4--herhaalbaarheid)

---

# De toekomst van brandbestrijding

Brandweermensen werken regelmatig in situaties waarin de omgeving gevaarlijk, onvoorspelbaar of moeilijk toegankelijk is. Technologie kan helpen om eerst informatie over een omgeving te verzamelen voordat een brandweerman of -vrouw deze omgeving binnengaat.

Een voorbeeld hiervan is een **blusrobot**.

Een blusrobot kan een gebouw of ander gebied binnengaan terwijl de brandweer op afstand blijft. De robot kan bijvoorbeeld beelden maken, door een gebouw rijden en helpen bij het bestrijden van een brand.

Maar een camera vertelt niet alles.

- Hoe warm is het precies?
- Is er veel rook aanwezig?
- Is de luchtkwaliteit veranderd?
- Waar bevindt zich een gevaarlijke plek?
- Verandert de omgeving terwijl de robot door het gebouw rijdt?

Daarom krijgt de blusrobot in dit project een extra hulpmiddel:

> **Een kleine sensorbol die informatie over de omgeving verzamelt en deze informatie doorgeeft aan de blusrobot.**

---

# Futurised

Het project wordt uitgevoerd in samenwerking met **Futurised**.

Futurised richt zich op het versterken van first responders door gebruik te maken van expertise en technologie. Binnen het bedrijf komen onder andere robotics, innovatie en voertuigsystemen samen.

Voor dit project is de centrale vraag:

> **Hoe kunnen sensoren en embedded technologie een blusrobot helpen om een gevaarlijke omgeving beter te begrijpen?**

Jullie gaan deze vraag beantwoorden door zelf een werkend prototype te ontwerpen en te bouwen.

Het doel is niet om direct een product te maken dat door de brandweer gebruikt kan worden.

Het doel is om te onderzoeken:

- welke informatie nuttig is;
- welke sensoren daarvoor geschikt zijn;
- hoe je sensordata verwerkt;
- hoe je informatie naar een robot kunt sturen;
- en hoe je kunt aantonen dat jullie oplossing werkt.

---

# Waarom een sensorbol?

Een robot kan tijdens het rijden niet altijd overal komen.

Een sensorbol kan bijvoorbeeld:

- door de robot worden meegenomen;
- op een andere plek worden neergelegd;
- naar een bepaalde locatie worden gebracht;
- of zelfstandig informatie uit de omgeving verzamelen.

De bol hoeft in eerste instantie **niet zelf rond te rijden**.

De uitdaging zit vooral in het verzamelen en doorgeven van betrouwbare informatie.

De vorm van een bol is daarbij interessant omdat een bol:

- geen duidelijke boven- of onderkant heeft;
- tegen een stootje kan;
- compact kan worden gebouwd;
- op afstand betrouwbaar kan communiceren;
- verschillende sensoren rondom het object kan bevatten;
- en mogelijk kan rollen zonder dat de elektronica direct op de grond terechtkomt.

---

# Projectopdracht

## Doel
Ontwerp en realiseer in een projectgroep een **sensorbol voor een blusrobot**.

De sensorbol moet minimaal twee relevante eigenschappen van de omgeving kunnen meten en deze informatie op een begrijpelijke manier beschikbaar maken voor de gebruiker of blusrobot.

Voor de communicatie wordt gebruikgemaakt van het **LoRa-netwerk**.

Jullie bepalen zelf welke informatie jullie gaan meten.

Daarbij moeten jullie kunnen uitleggen:

> **Waarom is deze informatie nuttig voor een blusrobot?**

---

# De sensorbol

De sensorbol bestaat minimaal uit:

**Sensoren → Microcontroller → Dataverwerking → Communicatie → Informatie voor de gebruiker/robot**

# Wat moet de sensorbol kunnen?

## 1. Meten

De sensorbol moet minimaal **twee verschillende soorten sensordata** kunnen verzamelen.

Denk bijvoorbeeld aan:

- temperatuur;
- luchtvochtigheid;
- lichtintensiteit;
- rook/luchtkwaliteit;
- afstand;
- beweging;
- versnelling;
- oriëntatie;
- geluid.

Niet iedere sensor is geschikt voor iedere situatie.

Een belangrijk onderdeel van het project is daarom:

> **Onderzoeken welke sensor geschikt is voor jullie toepassing.**

Jullie moeten kunnen uitleggen waarom jullie voor een bepaalde sensor hebben gekozen.

---

## 2. Verwerken

Een sensor geeft niet automatisch informatie die direct bruikbaar is.

De microcontroller moet de meetwaarden bijvoorbeeld:

- uitlezen;
- omzetten;
- controleren;
- combineren;
- opslaan;
- of interpreteren.

Jullie kunnen bijvoorbeeld een eenvoudige classificatie maken:

```text
Temperatuur < 40 °C
        ↓
     Normaal

40 °C – 80 °C
        ↓
  Verhoogde temperatuur

Temperatuur > 80 °C
        ↓
  Gevaarlijke temperatuur
```
# Deliverables

## 1. Conceptdocument

Maak een document waarin jullie ontwerp wordt uitgelegd.

Beschrijf minimaal:

- het probleem;
- de doelgroep/gebruiker;
- jullie oplossing;
- de belangrijkste use case;
- systeemarchitectuur;
- gekozen sensoren;
- gekozen microcontroller;
- LoRa-communicatie;
- voeding;
- behuizing;
- belangrijkste ontwerpkeuzes.

---

## 2. Requirements

Maak een overzicht van:

- functionele requirements;
- niet-functionele requirements;
- technische requirements;
- testbare acceptatiecriteria.

Leg per belangrijke requirement uit:

> **Waarom hebben we deze requirement?**

---

## 3. Proof of Concept

Maak een werkend prototype.

Het prototype moet minimaal:

- twee sensoren uitlezen;
- de meetwaarden verwerken;
- de meetwaarden via LoRa versturen;
- en de ontvangen informatie zichtbaar maken voor de gebruiker.

Het prototype hoeft nog niet perfect te zijn.

Het moet vooral aantonen dat jullie technische oplossing werkt.

---

## 4. Testplan

Maak vooraf een testplan.

Beschrijf:

- wat jullie testen;
- waarom jullie dit testen;
- hoe jullie dit testen;
- welke meetwaarden jullie verwachten;
- wanneer een test geslaagd is.

Bijvoorbeeld:

| Test | Verwachting | Resultaat |
|---|---|---|
| Temperatuur meten | Waarde verandert bij verwarmen sensor | |
| Communicatie | Data komt aan bij ontvanger | |
| LoRa-bereik | Data komt binnen op minimaal 50 meter | |
| Opstarten | Sensor begint automatisch te meten | |
| Meetfrequentie | Sensor verstuurt iedere 10 seconden data | |

---

## 5. Demonstratie

Tijdens de demonstratie laten jullie zien:

1. De sensorbol.
2. De verschillende sensoren.
3. De werking van de microcontroller.
4. De LoRa-communicatie.
5. De ontvangen informatie.
6. Een realistische test.
7. Wat jullie zouden verbeteren in een volgende versie.

---

# Technische uitdagingen

Tijdens het project komen jullie verschillende technische problemen tegen.

Dat is onderdeel van de opdracht.

## Sensoren

Een sensor heeft eigenschappen zoals:

- meetbereik;
- nauwkeurigheid;
- resolutie;
- meetfrequentie;
- interface;
- energiegebruik.

Een sensor kiezen omdat deze "goedkoop" is, is dus niet voldoende.

Jullie moeten kunnen uitleggen:

> **Waarom past deze sensor bij onze toepassing?**

---
# Inspiratie

Onderstaande ideeën zijn bedoeld als inspiratie.

Jullie mogen één van deze concepten gebruiken, combineren of een volledig eigen oplossing bedenken.

---

## Concept A — Temperatuur en luchtvochtigheid

### Doel

De sensorbol geeft informatie over het klimaat rondom de robot.

### Sensoren

Bijvoorbeeld:

- temperatuur;
- luchtvochtigheid.

### Mogelijke toepassing

De robot kan bijvoorbeeld ontdekken dat hij een ruimte binnenrijdt waar de temperatuur sterk toeneemt.

### Uitbreiding

Bereken bijvoorbeeld:

```text
Normaal
Verhoogd
Gevaar
```
## concept B — Rook en luchtkwaliteit
### Doel

Onderzoeken of de luchtkwaliteit verandert wanneer de sensorbol een ruimte binnengaat.

### Sensoren

Bijvoorbeeld:

gas-/luchtkwaliteitssensor;
temperatuur;
luchtvochtigheid.
Mogelijke toepassing

De sensorbol geeft aan dat de luchtkwaliteit verandert.

### Belangrijk

Een goedkope luchtkwaliteitssensor is geen professionele rookdetector.

Onderzoek daarom goed wat jullie sensor daadwerkelijk kan meten en welke conclusies je wel en niet mag trekken.

Een sensor kan bijvoorbeeld een verandering in luchtkwaliteit detecteren, maar daarmee weet je niet automatisch:

of er brand is;
welk gas aanwezig is;
hoe gevaarlijk de situatie is.

Jullie moeten dus zorgvuldig omgaan met de interpretatie van meetgegevens.

## Concept C — Omgevingslicht
### Doel

De sensorbol bepaalt hoeveel licht er aanwezig is.

### Sensoren

Bijvoorbeeld:

LDR;
fotodiode;
digitale lichtsensor.
Mogelijke toepassing

De robot kan informatie krijgen over:

donkere ruimtes;
fel licht;
plotselinge veranderingen in licht.

## Concept D — Gecombineerde sensorbol
### Doel

Maak een sensorbol die meerdere eigenschappen van de omgeving combineert.

Bijvoorbeeld:

temperatuur;
luchtvochtigheid;
licht;
luchtkwaliteit;
beweging.

# Testen

Een goed prototype is niet alleen een apparaat dat werkt.

Jullie moeten ook kunnen **aantonen dat het werkt**.

Denk daarom na over verschillende soorten tests.

---

## Test 1 — Sensor

Verandert de meetwaarde wanneer de omgeving verandert? Komen de waarden overeen met wat te verwachten is volgens de datasheet?

---

## Test 2 — Communicatie

Komt de informatie daadwerkelijk bij de ontvanger aan? 

---

## Test 3 — Bereik

Hoe ver kan de sensorbol via LoRa communiceren?

Test bijvoorbeeld verschillende afstanden:

| Afstand | Bericht ontvangen? | Signaalsterkte | Opmerking |
|---:|:---:|:---:|---|
| 5 m | | | |
| 10 m | | | |
| 25 m | | | |
| 50 m | | | |
| 100 m | | | |

---

## Test 4 — Herhaalbaarheid

Krijg je bij dezelfde situatie ongeveer dezelfde meetwaarden?

Voer bijvoorbeeld meerdere keren dezelfde test uit.

```text
Test 1 → 74 °C
Test 2 → 75 °C
Test 3 → 74 °C
Test 4 → 76 °C
```
