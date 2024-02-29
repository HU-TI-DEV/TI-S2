# Rekenen met eenheden[](title-id)

### Inhoud[](toc-id)

- [Rekenen met eenheden](#rekenen-met-eenheden)
    - [Inhoud](#inhoud)
  - [Een introductie](#een-introductie)
    - [Grootheden versus eenheden](#grootheden-versus-eenheden)
    - [Wetten uit de elektrotechniek](#wetten-uit-de-elektrotechniek)
    - [Standaardeenheden](#standaardeenheden)
    - [Tip 1: Van tekst naar formules: noteer waarden met eenheden](#tip-1-van-tekst-naar-formules-noteer-waarden-met-eenheden)
    - [Tip 2: Synchroniseer compatibele eenheden](#tip-2-synchroniseer-compatibele-eenheden)
    - [Tip 3: Schrijf eenheden in elkaar om via standaardeenheden](#tip-3-schrijf-eenheden-in-elkaar-om-via-standaardeenheden)
    - [Tip 4: Zorg ervoor dat je vermenigvuldig en deelwetten snel kunt herschrijven](#tip-4-zorg-ervoor-dat-je-vermenigvuldig-en-deelwetten-snel-kunt-herschrijven)
  - [Vermenigvuldiging is impliciet](#vermenigvuldiging-is-impliciet)
  - [“Per” betekent “gedeeld door”](#per-betekent-gedeeld-door)
  - [References](#references)

---

**v0.1.0 [](version-id)** Start document voor rekenen met eenheden door HU IICT[](author-id).

---

## Een introductie

Er zijn vaak situaties dat je “even iets uit wilt rekenen” op basis van formules die alleen bestaan uit vermenigvuldigingen of delingen. Eindeloos veel natuurwetten voldoen daaraan. Denk aan de wet van Ohm: R = U/I, de definitie van vermogen: P = E/t, stroom: I = Q/t en spanning: U = E/Q.

Om iets te berekenen moeten er dingen door elkaar gedeeld worden of met elkaar vermenigvuldigd. Door goed op de eenheden te letten kun je fouten daarbij voorkomen.

### Grootheden versus eenheden

Het is goed om je het **verschil tussen grootheden en eenheden** te beseffen.

Het wordt misschien het duidelijkst met een lijst met voorbeelden:

| Grootheid | Bijbehorende eenheden |
| -------- | --------- |
| d (distance, afstand)  | mm, cm, ***m***, km, mile, ae (astronomische eenheid), inch | 
| t (tijd) | ms, ***s*** (seconde), h (hour, uur) | 
| v (velocity, snelheid) | m/s, km/s, mile/s, km/h, mph | 
| m (massa) | mg, g, ***kg***, ounce, pound | 
| | | 
| **In het electrische domein:** | | 
| Q (lading) | ***C*** (Coulomb), As (Ampereseconde) | 
| E (energie) | ***J*** (Joule), Wh (Wattuur) | 
| P (vermogen) | ***W*** (Watt), VA (VoltAmpere), J/s (Joule per seconde) | 
| I (electrische stroom) | ***A*** (Ampere), C/s (Coulomb per seconde) | 
| V of U (voltage, electrische spanning) | ***V*** (Volt), mV, kV, J/Q (Joule per Coulomb) | 
| R (electrische weerstand) | milliohm, ***Ohm***, kiloOhm V/A (Volt per Ampere) | 
| C (capaciteit) | microFarad, milliFarad, ***F*** (Farad) | 
| L (inductie) | ***H*** (Henry) | 

Afstand is bijvoorbeeld een natuurkundige **grootheid**. Het duidt aan hoe ver twee dingen in de ruimte van elkaar verwijderd zijn. Zo’n afstand kun je zien als een **variabele** die je **waarden** kunt geven. In de informatica is een **waarde** een “constant” getal welke je aan een variabele kunt toekennen. Zo kun je bijvoorbeeld in de integer n de waarde 10 stoppen. 

Binnen de natuurkunde bestaat zo’n **waarde** behalve uit een “contant” **getal** ook nog uit een **eenheid**.

Grootheden kunnen zo worden **uitgedrukt** in allerlei verschillende **eenheden**. De grootheid afstand kan bijvoorbeeld worden uitgedrukt in millimeters, centimeters, meters, kilometers, mijlen, astronomische eenheden of inches. Maar in welke eenheid je de afstand tussen de voordeur en de achterdeur ook uitdrukt, de afstand blijft hetzelfde. Zowel natuurkundige grootheden als eenheden kun je in formules met afkortingen noteren. Als je **gemixed** grootheden en eenheden in een formule gebruikt, zoals bij v = 5 [m/s], kun je verwarring voorkomen door **eenheden tussen vierkante haken []** te noteren. Bij de bovenstaande formule is dan duidelijk dat er met de m de eenheid meters bedoeld wordt, en niet de grootheid massa. Maar in de meeste gevallen spreekt het wel voor zich, en zijn de vierkante haken niet nodig.

### Wetten uit de elektrotechniek

In de natuur, en dus ook in de elektrotechniek staan de verschillende grootheden in verband via de volgende vijf basis wetten:

| Wetmatigheid of definitie | Corresponderend verband van standaard-eenheden |
| -------- | --------- |
| P = E / t | [W] = [J] / [s] |
| V = E / Q | [V] = [J] / [C] |
| I = Q / t | [A] = [C] / [s] |
| R = V / I | [Ohm] = [V] / [A] |
| C = Q / V | [F] = [C] / [V] |

Zorg dat dat je deze wetten kunt dromen. Zowel qua grootheden als qua standaard-eenheden. Je kunt ze het makkelijkst in 2 stappen uit je hoofd leren:

- Voor elke grootheid de bijbehorende standaard eenheid. 
  Dus: Vermogen (P) is in Watt [W], Voltage (V) is in Volt[V], Stroom (I) is in Ampere [A], Weerstand (R) is in [Ohm] en Capaciteit [C] is in [Farad]

- Vervolgens de rechtse kolom met eenheids-relaties tussen de standaard-eenheden. Spreek daarbij de deelstrepen in je hoofd uit als “per”: “Watt is Joule **per** seconde”, “Volt is Joule **per** Coulomb”, “Ampere is Coulomb per seconde”, “Ohm is Volt **per** Ampere”, “Farad is Coulomb **per** Volt”.
  
Omdat grootheden worden uitgedrukt in eenheden, staan ook de eenheden (en in het bijzonder de **standaard-eenheden** met elkaar in verband.

### Standaardeenheden

In het tweede deel van de tabel zie je een opsomming van alle electrische grootheden met bijbehorende eenheden. De zogenaamde “standaardeenheden” zijn benadrukt weergegeven. Standaardeenheden zijn handig, omdat je ze ***direct*** naar mekaar kunt omzetten. 

**Voorbeeld 1**: De grootheid Q (electrische lading) kun je uitdrukken in [Ah] (Ampereuur), maar ook in de standaardeenheid [C] (Coulomb).

Stroom is gerateerd aan lading en tijd volgens de formule: 
        
        I = Q/t

Stel nu dat we de stroom I willen weten, en dat we Q en t hebben opgeschreven in standaardeenheden: Q = 60[C] en t = 30[s] 

Dan volgt: I = Q / t = 60[C] / (30[s]) = 2 [C]/[s] = 2 [A] 

Je ziet dus dat we de standaardeenheden [C]/[s] direct mogen vervangen door [A]. Dat kan alleen omdat het standaardeenheden zijn.

**Voorbeeld 2**: Stel nu dat we de stroom I willen weten, en dat we Q en t **niet** hebben opgeschreven in standaardeenheden: Q = 10[C] en t = 0.5[min]. 

Dan volgt: I = 20 [C]/[min] 

[min] is een eenheid voor de grootheid tijd, maar geen standaardeenheid. We moeten dat dus eerst nog omzetten naar de standaardeenheid voor tijd [s] voordat we de eenheden mogen vervangen door de standaardeenheid Ampere [A]:

We substitueren: [min] = 60*[s]. 

We krijgen dan: I = 20 [C]/ (60*[s]), ofwel I = 0.33 [C]/[s] = 0.33 [A].

Dus: Typisch bij opgaven waarbij 2 grootheden zijn gegeven (zoals bovenstaand tijd en lading), dan kun je via een van de 5 “**per**” **formules** de 3e grootheid uitrekenen. Gebruik bij twijfel altijd **standaardeenheden**.

### Tip 1: Van tekst naar formules: noteer waarden met eenheden

Om een probleem overzichtelijk te krijgen, wil je zo snel mogelijk van tekst naar formules. Het is daarbij belangrijk dat je **altijd** de **eenheden** van de waarden noteert. Dan wordt daaruit meestal wel duidelijk hoe je het kunt aanpakken.

**Voorbeeld**: Een opgeladen batterij bevat 5 Ah aan lading. Na hoeveel **uren** is de batterij ontladen, gegeven dat er een stroom loopt van 2.5A?

Als je formules **zonder eenheden** bij de waarden noteert, krijg je zoiets: ***Q=5, I=2.5, t=?***

Daaruit is niet zo makkelijk te zien of je beide getallen nu door mekaar moet delen, en zo ja, welk door welk, of dat je ze met elkaar moet vermenigvuldigen.

Noteren we de formules **met eenheden**, dan zien we:

***Q=5 [Ah], I=2.5 [A], t=.. [h]?*** (even voor de duidelijkheid met vierkante haken om de eenheden)

Bedenk je dat de eenheden zich in berekeningen gedragen als “**constantes**”. Hierboven staat dus: Q = 5 maal A maal h. (A = de eenheid Ampere, en h = de eenheid uren, hours).

Normaal gesproken schrijf je die vermenigvuldigingen niet op – dat hoeft bij vermenigvuldigingen immers niet: 5 X betekent hetzelfde als 5 * X. Voor de duidelijkheid doen we dat nu wel even:

We hebben dus: Q = 5*[A]*[h], I = 2.5*[A] en we willen weten t = .. * [h]
Voor grootheid Q (lading) wordt meestal Coulomb als eenheid gebruikt, maar in dit geval is het Ampere maal Uur. Je kunt daar aan zien dat de volgende wetmatigheid hier van toepassing is: Q = I * t (lading = stroom * tijd)

**We hebben dus 1 vergelijking met 3 grootheden. Van twee grootheden kunnen we de waarde invullen:**

        Q = I*t met Q = 5 [A]*[h] en I=2.5 [A], t=.. [h]?

Hoe berekenen we t nu? 

We hebben dus een vergelijking met 3 variabelen: I, Q en t, met een onbekende (t) en twee grootheden waarvan de waarde al bekend is (Q en I). Als het aantal vergelijkingen gelijk is aan het aantal onbekenden, kunnen we de onbekenden er uit oplossen. In dit geval willen we de vergelijking zodanig herschrijven dat de onbekende t aan een van beide kanten apart staat.

De betekenis van het = teken is dat wat links staat hetzelfde is als wat rechts staat. Als links en rechts gelijk aan elkaar zijn, dan moeten ze natuurlijk nog steeds gelijk aan elkaar zijn als je ze met hetzelfde vermenigvuldigt of deelt.

We willen t weten. Als we linker en rechter deel nu delen door I, dan houden we aan de rechterkant alleen t over:

Laten we linker en rechter deel dus delen door I:

        𝑸/𝑰= 𝑰∗𝒕/𝑰 <-> 𝑸/𝑰= 𝒕 (de I’s delen aan de rechterkant op elkaar weg).

De vergelijking is daarmee opgelost naar t. We kunnen nu de al bekende waarden van grootheden Q en I invullen. Vul ook altijd de eenheden van die waarden daarbij in:

        𝒕=𝑸/𝑰= 𝟓∗[𝑨]∗[𝒉]/𝟐.𝟓∗[𝑨]=𝟐[𝒉]

Bij de deling vallen in teller en noemer [A] tegen elkaar weg. De eenheid van het antwoord is dus in uren (h). Het antwoord is dus 2 uur.

### Tip 2: Synchroniseer compatibele eenheden

Bij het volgende voorbeeld komen van een bepaalde grootheid, in dit geval tijd, waarden met meerdere soorten eenheden voor.

**Voorbeeld**: Een opgeladen batterij bevat 5 Ah aan lading. Na hoeveel **seconden** is de batterij ontladen, gegeven dat er een stroom loopt van 2.5A ?

Vergelijkbaar met het vorige voorbeeld kunnen we dit probleem herformuleren tot:

        Q = I*t met Q = 5 [A]*[h] en I = 2.5 [A], t = .. [s]?

Dit keer zien we dus dat in de waarde van de grootheid lading de tijdseenheid uren (hours, h) voortkomt, terwijl het antwoord in tijdseenheid seconden gevraagd wordt. Dat moeten we zien te **synchroniseren**. Dat kan ofwel door alleen h te gebruiken, ofwel door alleen s te gebruiken. Het **gevraagde antwoord** is in seconden, dus kiezen we in dit geval voor s.

Het verband tussen h en s kunnen we weergeven met de volgende extra formule: 

***[h] = 3600 * [s]***

Een uur is 60 minuten maal 60 seconden per minuut: ***[h]=60[min]∗60[s]/[min]= 60∗60∗[min]∗[s]/[min]=3600[s]***

We mogen [h] dus vervangen door 3600*[s]. We krijgen dan:

        Q = I*t met Q = 5 [A]*3600*[s] en I = 2.5 [A], t = .. [s]?

Na deze synchronisatie kunnen we weer t oplossen en de bekende waarden invullen:

        𝒕=𝑸/𝑰= 𝟓∗[𝑨]∗3600∗[s]/𝟐.𝟓∗[𝑨]= 7𝟐00[s]

### Tip 3: Schrijf eenheden in elkaar om via standaardeenheden

**Voorbeeld 1**: Een opgeladen batterij bevat 18000 C aan lading. Na hoeveel seconden is de batterij ontladen, gegeven dat er een stroom loopt van 2.5A ? (C staat voor de eenheid Coulomb)

Noteren we deze formules met eenheden, dan zien we:

        Q = 18000 [C], I = 2.5*[A] en we willen weten t=.. * [s]?

We willen dus tijd weten, maar in de gegeven formules vinden we alleen de eenheden Coulombs en Amperes. Wat nu?

Oplossing: Ga bij jezelf na of je een van beide grootheden kan omschrijven naar iets met tijd en de andere grootheid. Bijvoorbeeld de stroom I. Bedenk je dat stroom = lading/tijd, ofwel I = Q/t, ofwel 1 Ampere = 1 Coulomb per seconde, ofwel [A] = [C] / [s].

We willen de waarde van de grootheid tijd uitrekenen, dus we voegen de wet met de **grootheid** tijd toe ( I = Q/t ). Reminder: een grootheid is een soort “variabele” waarvan we de waarde kunnen uitrekenen. We hebben dan:

        I = Q/t met Q = 18000 [C], I = 2.5*[A] en we willen weten t=.. * [s]?

Omdat we de tijd t willen weten, moeten we de vergelijking weer omschrijven naar de vorm waar t apart staat.

Eerst vermenigvuldigen we links en rechts met t, om t uit de noemer weg te krijgen:

**𝐼∗𝑡= 𝑸∗𝒕/𝒕 <-> 𝐼∗𝑡= 𝑸** (de t’s in teller en noemer vallen ten elkaar weg)

Vervolgens links en rechts delen door I om t apart te schrijven:

**I∗t/𝑰= Q/𝑰 <-> t = 𝑸/𝑰**

Vervolgens de waarden van Q en I met eenheden invullen:

        t = 18000 [C] / 2.5 [A]= 7200 [C]/[A]

We hebben nu een tijd uitgerekend, maar de eenheid is niet secondes. Bovenstaand merkten we al op dat [A] = [C]/[s].

We kunnen dus in onze formule [A] vervangen door [C]/[s].

We krijgen dan:

        t = 7200 [C]/[A]=7200 [C]/([C]/[s])=7200 [C]/1∗[s]/[C]=7200 [s]

(gebruikt is hier: delen door een breuk is hetzelfde als vermenigvuldigen met de omgekeerde breuk. Verder vallen de C’s in teller en noemer tegen elkaar weg)

### Tip 4: Zorg ervoor dat je vermenigvuldig en deelwetten snel kunt herschrijven

Zorg ervoor dat je vermenigvuldig en deelwetten snel kunt herschrijven. Dan hoef je niet alle vormen te onthouden.

## Vermenigvuldiging is impliciet

Eerder hebben we gezien dat als je eenheden met elkaar vermenigvuldigt, dat je het vermenigvuldigingsteken niet hoeft op te schrijven of zelfs uit te spreken – de vermenigvuldiging wordt zogezegd impliciet aangenomen.

Zo zagen we al Ampereuur, ofwel Ah voorbij komen.

## “Per” betekent “gedeeld door”

We hebben eerder ook gezien dat de grootheid stroom, kan worden geschreven de “hoeveelheid lading” die per “hoeveelheid tijd” voorbij komt. Als je in tekst het woord “per” tegenkomt, staat dat voor een deling in de bijbehorende formule. We kunnen bovenstaande dus opschrijven met **grootheden**: **𝑰= 𝑸/𝒕**

Hier staat dus een vergelijking met 3 variabelen: I, Q en t. De betekenis van het = teken is dat wat links staat hetzelfde is als wat rechts staat. Als links en rechts gelijk aan elkaar zijn, dan moeten ze natuurlijk nog steeds gelijk aan elkaar zijn als je ze met hetzelfde vermenigvuldigt of door hetzelfde deelt.

Laten we linker en rechter deel eens vermenigvuldigen met t:

        𝐼∗𝑡= 𝑄∗𝑡/𝑡 <-> 𝑰∗𝒕= 𝑸 (de t’s delen aan de rechterkant op elkaar weg).

Laten we bij deze laatste vergelijking eens linker en rechter deel delen door I:

        𝐼∗𝑡/𝐼= 𝑄/𝐼 <-> 𝒕= 𝑸/𝑰 (de I’s delen aan de linkerkant op elkaar weg)

Samengevat: door links en rechts met hetzelfde te vermenigvuldigen of door hetzelfde te delen kunnen eenvoudig de andere vormen worden afgeleid (en hoeven we dus maar 1 vorm te onthouden).
