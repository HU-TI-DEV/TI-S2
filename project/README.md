# Agri Monitor (LoRa) <!-- omit in toc -->

### Inhoud <!-- omit in toc -->

- [De Toekomst van Monitoring in Agro \& Food](#de-toekomst-van-monitoring-in-agro--food)
  - [Een Modulaire en Slimme Meetoplossing](#een-modulaire-en-slimme-meetoplossing)
    - [1. Brede toepasbaarheid](#1-brede-toepasbaarheid)
    - [2. Modulaire opbouw](#2-modulaire-opbouw)
    - [3. Eenvoudige communicatie (LoRa)](#3-eenvoudige-communicatie-lora)
    - [4. Beheer op afstand](#4-beheer-op-afstand)
    - [5. Meten en opslaan van omgevings- en gewasparameters](#5-meten-en-opslaan-van-omgevings--en-gewasparameters)
  - [6. Unique Selling Point (USP)](#6-unique-selling-point-usp)
- [Projectopdracht](#projectopdracht)
  - [Doel](#doel)
  - [Randvoorwaarden](#randvoorwaarden)
  - [Deliverables](#deliverables)
  - [Testen op locatie](#testen-op-locatie)
- [Inspiratie: 4–5 mogelijke systemen](#inspiratie-45-mogelijke-systemen)
  - [Systeem A — Canopy Microclimate Node](#systeem-a--canopy-microclimate-node)
  - [Systeem B — Weerstation / Microklimaat Referentie](#systeem-b--weerstation--microklimaat-referentie)
  - [Systeem C — Wortelmilieu / Substraat Monitoring](#systeem-c--wortelmilieu--substraat-monitoring)
  - [Systeem D — Plantstress \& Bladtemperatuur](#systeem-d--plantstress--bladtemperatuur)
  - [Systeem E — Watergift \& Drain (indicatief)](#systeem-e--watergift--drain-indicatief)

---

**v0.2.0** Startdocument voor agri monitor (POC) in opdracht van HAS Green Academy.

---

# De Toekomst van Monitoring in Agro & Food

## Een Modulaire en Slimme Meetoplossing

In de agro- en food-sector is inzicht in **groei en bloei** sterk afhankelijk van betrouwbare metingen in en rond het gewas en het wortelmilieu. In deze opdracht ontwikkelen studentgroepen **verschillende monitoring-systemen** die op locatie bij HAS Green Academy getest kunnen worden.

De oplossingen worden **hoog over** beschreven: er is bewust ruimte voor teams om eigen requirements op te stellen, keuzes te onderbouwen en iteratief te verbeteren.

### 1. Brede toepasbaarheid

De systemen zijn ontworpen met brede toepasbaarheid in gedachten: verschillende gewassen, teeltwijzen, proefopstellingen en seizoenen. Elk team definieert een eigen meetdoel (bijv. stress-indicatie, groeicondities, wortelmilieu, microklimaat) en vertaalt dat naar:
- meetpunten (waar/hoe vaak)
- sensorkeuze
- dataformaten en interpretatie
- testplan op locatie

### 2. Modulaire opbouw

Elk systeem bestaat uit losse, vervangbare bouwblokken. Denk aan:
- **Sensor-node** (microcontroller + 2–4 sensoren)
- **Communicatiemodule** (LoRaWAN)
- **Voedingsmodule** (externe voeding; accu/solar als uitbreiding)
- **Back-end** (MQTT server, database)
- **Dashboard / data-analyse** (minimaal: uitlezen + trend; uitbreiding: alerts)

Deze modulaire aanpak maakt het mogelijk om later sensoren te wisselen, nodes toe te voegen of een andere datastroom te kiezen zonder de hele oplossing opnieuw te bouwen.

### 3. Eenvoudige communicatie (LoRa)

Elk systeem moet data verzenden via **LoRa** (EU868). De implementatie is **LoRaWAN** via een gateway.

Belangrijk is dat teams rekening houden met:
- payload-grootte en verzendinterval (duty-cycle)
- foutafhandeling (missed packets, CRC, retries)
- identificatie van nodes (node-id) en meetkanalen
- energieverbruik versus meetfrequentie

### 4. Beheer op afstand

De oplossing ondersteunt (minimaal conceptueel, bij voorkeur ook technisch):
- status van het systeem (online/offline, batterij/voeding, meetfouten)
- logging en diagnose (zodat testen op locatie reproduceerbaar zijn)
- optioneel: eenvoudige herconfiguratie (bijvoorbeeld meetinterval) óf een plan daarvoor

### 5. Meten en opslaan van omgevings- en gewasparameters

De kern is het verzamelen en bruikbaar maken van data. Elk team beschrijft:
- welke parameters worden gemeten en waarom (link met groei/bloei)
- meetfrequentie (bijvoorbeeld elke 5 minuten is vaak geschikt, maar motiveer dit)
- opslag (time-series database, of eenvoudige cloud/local opslag)
- visualisatie (grafiek, trends, grenzen/alerts)

## 6. Unique Selling Point (USP)

De oplossingen onderscheiden zich door:
- focus op **praktijk-testbaarheid** op locatie
- **modulair** en uitbreidbaar (sensoren/nodes)
- **LoRa** als robuuste communicatie voor buiten/veldopstellingen
- duidelijke koppeling tussen metingen en **teeltinzicht** (groei/bloei)

---

# Projectopdracht

## Doel

Ontwikkel in groepsverband een monitoring-oplossingen die op locatie bij HAS Green Academy getest kunnen worden. Elke oplossing meet een relevante set parameters die inzicht geeft in groei- en bloeicondities van planten.

## Randvoorwaarden

Per systeem:
- **2 tot 4 sensoren** integreren (en onderbouwen)
- **LoRa-communicatie** toepassen (EU868)
- **Externe voeding** (bijv. adapter/powerbank);  
  **Nice-to-have:** accu + solar voor buiten meetstations
- Een **hoog-over ontwerp** (architectuur + keuzes), met ruimte voor eigen requirements
- Realistisch testbaar op locatie (montage, behuizing, bereik, data-uitleesbaarheid)

Niet verplicht (wel waardevol als uitbreiding):
- OTA/remote configuratie
- lokale buffering bij verbindingsverlies
- kalibratie-aanpak en foutmarges
- eenvoudige alerts (drempelwaarden)

## Deliverables

1. **Conceptdocument (README + diagrammen)**
   - meetdoel en context
   - architectuur (node → LoRa → gateway/back-end → dashboard)
   - sensorkeuze + meetbereik/accuratesse + motivatie
   - datamodel/payload (voorbeeld payloads)
2. **Requirements (team-eigen)**
   - functioneel (wat moet het kunnen)
   - niet-functioneel (energie, robuustheid, onderhoud, kosten)
   - testbare acceptatiecriteria
3. **Proof of Concept**
   - werkende meetketen of aantoonbaar deel daarvan
   - demo met minimaal één realistische meetcyclus
4. **Testplan**
   - wat ga je op locatie testen, hoe, en welke succes-criteria
5. **Reflectie**
   - beperkingen, verbeterpunten, volgende iteratie

## Testen op locatie

Bij het testen op locatie is belangrijk:
- montage/plaatsing van sensoren (hoogte, oriëntatie, afscherming)
- invloed van weer/zon/regen op metingen
- LoRa-bereik en betrouwbaarheid
- interpretatie: wat zegt de data over groei/bloei, en wat niet?

---

# Inspiratie: 4–5 mogelijke systemen

Onderstaande systemen zijn ter *inspiratie*. Teams mogen varianten maken, combineren of eigen concepten voorstellen, zolang randvoorwaarden gehaald worden.

## Systeem A — Canopy Microclimate Node

**Doel:** microklimaat net boven/naast het gewas volgen (relevant voor groei/bloei en stress).

**Sensoren (kies 2–4):**
- luchttemperatuur
- luchtvochtigheid
- CO2 (optioneel, afhankelijk van context)
- PAR/licht (indicatie van fotosynthese-condities)

**LoRa:** periodiek (bijvoorbeeld 5 min) microklimaatpayload.

**Nice-to-have:** stralingsschild + ventilatie voor betere luchtmeting.

## Systeem B — Weerstation / Microklimaat Referentie

**Doel:** referentiemetingen buiten/veld voor correlatie met gewascondities.

**Sensoren (kies 2–4):**
- buitentemperatuur + luchtvochtigheid (combi-sensor)
- windsnelheid (evtueel windrichting als extra)
- regen (ja/nee of tipping bucket)
- straling / zoninstraling (indien beschikbaar)

**LoRa:** meetinterval bijvoorbeeld 5 min; extra event bij regen-start.

**Nice-to-have:** autonoom (solar + accu).

## Systeem C — Wortelmilieu / Substraat Monitoring

**Doel:** inzicht in wortelcondities (sterk bepalend voor groei en opname). Let op! Dit is een moeilijke opdracht omdat geschikte sensoren niet eenvoudig te krijgen zijn.

**Sensoren (kies 2–4):**
- vochtgehalte (substraat/grond)
- EC (geleidbaarheid; indicatie nutriënten/zouten)
- bodem-/substraattemperatuur
- (optioneel) pH, afhankelijk van sensortechniek en haalbaarheid

**LoRa:** trenddata; eventueel extra bericht bij overschrijding drempels.

**Nice-to-have:** lokale filtering (moving average) om ruis te beperken.

## Systeem D — Plantstress & Bladtemperatuur

**Doel:** stress-indicatie en energiebalans via plant-/bladoppervlak.

**Sensoren (kies 2–4):**
- plant-/bladtemperatuur (IR-thermometer)
- luchttemperatuur (referentie voor delta T blad-lucht)
- luchtvochtigheid (voor verdamping/comfort)
- (optioneel) licht/PAR

**LoRa:** interval bijvoorbeeld 5 min; dashboard toont delta T en trend.

**Nice-to-have:** eenvoudige stress-index (team definieert en motiveert).

## Systeem E — Watergift & Drain (indicatief)

**Doel:** indicatie van waterbalans, zonder volledige installatie-integratie. Let op! Dit is een moeilijke opdracht omdat geschikte sensoren niet eenvoudig te krijgen zijn.

**Sensoren (kies 2–4):**
- substraatvocht
- EC of temperatuur in wortelzone
- (optioneel) gewichtmeting (load cell) van pot/tray als proxy voor wateropname
- (optioneel) flow-schakelaar/volume-schatting indien haalbaar

**LoRa:** combineer langzame trends (gewicht/vocht) met status-events.

**Nice-to-have:** edge-detectie van watergiftmoment op basis van trendbreuk.