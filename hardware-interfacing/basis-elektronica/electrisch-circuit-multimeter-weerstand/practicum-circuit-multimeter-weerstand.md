**Jouw naam:  
Naam van jouw teamgenoot:**

# Voorbereiding

Zorg voordat je aan de practica begint, dat je:

1. de bijbehorende theorie (reader en sheets) goed hebt doorgenomen

2. de benodigde materialen en gereedschappen voor alle opdrachten
   gereed hebt

## Benodigdheden

Voor deze practica heb je (als team) nodig:

- Een breadboard

- Een multimeter

- Twee 1k weerstanden (1k is een verkorte schrijfwijze voor 1k Ω,
  ofwel 1000 ohm)

- Wat geisoleerd, stug draad (geschikt om in breadboard te prikken)

- Wat breadboard wires

- Een striptang

- Een spanningsbron van rond de 5V.  
  Mogelijkheden: een adapter van 5V, een USB-adapter, een
  arduino-nano, een 4,5V batterij.

Als je van een van deze dingen niet weet wat het is, google er dan even
op.

# Wat wordt er van je verwacht?

- Voor de opdrachten uit samen met een andere student.

- Het is niet erg als je in overleg met andere teams komt tot een antwoord.  
  Zorg er wel voor dat je het 100% begrijpt, anders schiet je jezelf
  in je voet: je leert door zelf te doen!

- Maak een copie van dit document, en voeg daarin je antwoorden
  toe. Als je iets moet invullen, wordt dat aangekondigd met
  **vetgedrukte** letters.

- Vermeld bij het inleveren helemaal bovenaan zowel je eigen naam als
  die van je teamgenoot.

# Breadboard

## Benodigd

- Een breadboard

- Een multimeter

## Opdracht

1. Neem een breadboard.

2. Zet de multimeter in “contact detectie” stand.  
   Vaak wordt die stand weergegeven als een .))) symbool, omdat er een
   pieptoon ontstaat als de meetpennen van de multimeter contact maken.

3. Maak met behulp van de multimeter in “contact detectie” stand een
   tekening die weergeeft hoe de connectors van het breadboard met
   elkaar verbonden zijn.  
   Zet die tekening (of eventueel een foto ervan) hieronder:

> <img title="" src="./media/media/image1.jpeg" alt="" width="553">

# De wet van Ohm, Spanning, Stroom, Vermogen

## Benodigd

- Een breadboard

- Een multimeter

- Een 1k weerstand

- Breadboard wires of draad + striptang

## Opdracht

### Spanning

1. Sluit een 5V spanningsbron aan op de (horizontale-) voedingslijnen
   van je breadboard.

2. Zet de multimeter in de modus “DC spanning meten”.

3. Controleer de gelijkspanning die tussen je voedingslijnen staat met
   de multimeter in “dc spanning meet modus” (aangegeven met DCV of
   V=)  
   **Welke spanning meet je (in 3 decimalen nauwkeurig)?**

### Weerstand

1. **Leg uit hoe je de 1k weerstand herkent (google eventueel op
   kleurcodes).**

2. Controleer de weerstand met de multimeter in “weerstand meet modus”
   (aangegeven met Ω).  
   **Welke weerstand meet je (in 3 decimalen nauwkeurig)?**

### Stroom

1. Zet de multimeter in “stroom meet modus” (aangegeven met DCA of mA)

2. Bekijk de onderstaande schakeling met de weerstand, voedingsspanning
   en multimeter:  
   
   <img title="" src="./media/media/image2.png" alt="" width="576">

3. **Geef een berekening van de stroomgrootte die de multimeter naar
   verwachting in die situatie weergeeft. Welke wet heb je daarbij
   gebruikt?**  
   
   Bouw en test de schakeling.  
   Houdt rekening met de richtlijnen voor het bouwen en testen van
   schakelingen (zie de bijlagen “testen van een schakeling” en
   “bedraden van een schakeling” in de reader).  
   **Welke stroom geeft de multimeter aan (in 3 decimalen
   nauwkeurig)?**

### Lading

1. **Hoeveel lading (in Coulomb) aan elektronen stroomt er per seconden
   door de weerstand?**

2. **Hoeveel lading (in Coulomb) aan elektronen stroomt er gedurende 1
   uur in totaal door de weerstand?**

3. **Hoeveel is die lading, als je het uitdrukt in mAh (milli ampere
   uur) in plaats van Coulomb?**

4. **Hoe groot is knooppuntsspanning V1? (tip: een knooppuntsspanning
   is de spanning tussen dat knooppunt en de ground
   (**<img src="./media/media/image3.png"/>)

5. **Hoe groot is knooppuntsspanning V2?**

6. **Hoeveel spanning staat er over de weerstand (tip: leen even een
   extra multimeter om dat te meten)?**

7. **Hoeveel spanning staat er over de stroom metende multimeter (tip:
   leen even een extra multimeter om dat te meten)?**

8. **Bereken hoe groot de weerstand van de (nog als stroommeter
   geschakelde-) multimeter is.**

### Vermogen en energie

1. **Hoeveel electrisch vermogen (in Watt) wordt er gedissipeerd in de
   weerstand (laat de berekening zien. Gebruik de gemeten stroom en
   spanning)?**

2. **Geef een afleiding van de formule die het in de weerstand
   gedisspeerde vermogen uitdrukt in alleen de spanning en de weerstand
   (tip: substitueer de stroom in bovenstaande formule met de stroom
   die volgt uit de wet van Ohm).**

3. **Controleer de formule door hem in te vullen.**

4. **Geef een afleiding van de formule die het in de weerstand
   gedisspeerde vermogen uitdrukt in alleen de stroom en de weerstand
   (tip: als voorgaande, maar substitueer nu de spanning (in plaats van
   de stroom) die volgt uit de wet van Ohm).**

5. **Controleer de formule door hem in te vullen.**

6. **Als de spanning over een weerstand verdubbelt, hoeveel neemt het
   in de weerstand gedissipeerde vermogen dan toe? Beargumenteer waarom**

7. **Als de stroom door een weerstand verdubbelt, hoeveel neemt het in
   de weerstand gedissipeerde vermogen dan toe?**

8. **Hoeveel elektrische energie (in Joules) wordt er in de weerstand
   gedurende 10 seconden in totaal omgezet naar warmte-energie?**

9. **Als je de weerstand zou vervangen door een weerstand van 10 Ω, wat
   zou dan het in de weerstand gedissipeerde vermogen zijn?**

10. **Hoeveel vermogensdissipatie kan een “normaal, qua afmetingen klein
    weerstandje”, zoals je 1k weerstand aan (in plaats van 1kΩ wordt
    vaak kortweg 1k geschreven)?**

11. Stel dat je over een 3,7V LiPo (Lithium Polymer) batterij beschikt
    met een (ladings-) capaciteit van 100mAh.  
    **Hoeveel energie (in Joules) bevat de volledig opgeladen
    batterij?**
    (Hint: P = I * V en E = P * t)

12. Stel dat je een 1k weerstand tussen de plus en min van de batterij
    zet. 
    **Hoeveel uur duurt het dan voordat de batterij leeg is?**
