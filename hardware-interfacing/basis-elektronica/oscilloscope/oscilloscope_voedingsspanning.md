# Een meting aan de stekkervoeding

De voeding is een belangrijk onderdeel van een systeem. Fabrikanten
besteden daar veel aandacht aan. In de eerste plaats moet een juiste
spanning gekozen worden. Daarbij hoort ook een keuze voor het maximaal
geleverde vermogen. Ook is het belangrijk of het een wisselspanning of
een gelijkspanning moet zijn. Praktisch gezien zijn alle voedingen voor
een elektronisch apparaat gelijkspanningsvoedingen. Heel soms zit de
gelijkrichter in het apparaat zelf en levert de voeding een eenvoudige
wisselspanning af.

Ook voor de kwaliteit van een voeding moet een keuze worden gemaakt. De
vraag is natuurlijk wat de kwaliteit van een voeding is. Welke
eigenschappen van een voeding zijn belangrijk voor een gegeven
toepassing?

```

```

Voor een voeding die een gelijkspanning levert kun je denken aan de
volgende gegevens:

- nauwkeurigheid van de geleverde spanning
- zuiverheid van de geleverde gelijkspanning
- (spannings)gedrag bij zware belasting
- efficiëntie van de spanningsomzetting en warmteontwikkeling
- verbruik bij nullast (als er geen vermogen wordt afgenomen)
- gedrag bij kortsluiting
- mate van storingsgevoeligheid (bijvoorbeeld het doorgeven van storingen van
  het lichtnet)

Welke eigenschap voor een voeding kun je zelf nog bedenken?

```

```

### Wat is een spanningsbron

De eigenschap van een “ideale” spanningsbron is het leveren van de
juiste spanning bij iedere willekeurige belasting. Bij iedere belasting
levert de voeding exact de juiste (bijbehorende) stroom. De spanning is
dus vast en de stroom wordt door de voeding automatisch ingesteld. Bij
grote (of zware) belasting levert de voeding ook een grote stroom. Een
spanningsbron mag niet worden kortgesloten, dan gaat er (theoretisch)
een oneindig grote stroom lopen. Hoe komt dat? Tip, verklaar dit aan de
hand van de wet van Ohm.

```

```

### Meting van de rimpelspanning

De zuiverheid van de uitgangsspanning geeft aan hoe “mooi” de
gelijkspanning is. Een batterij heeft een ideale strakke gelijkspanning
(bij een constante belasting). Bij de spanning van de stekkervoeding is
het anders. Onze stekkervoeding wordt gevoed vanuit het lichtnet en
heeft een omzetter (gelijkrichter) die van de wisselspanning een
gelijkspanning maakt. Die omzetting wordt zo goed mogelijk uitgevoerd
maar het is lastig om er een perfecte gelijkspanning van te maken.

Afhankelijk van de kwaliteit van de voeding is er een “rimpel” op de
uitgangspanning aanwezig. Het is belangrijk om te weten hoe groot deze
rimpel is. Ook is het belangrijk om te weten of het apparaat dat gevoed
wordt daar tegen kan. Bij de volgende meting ga je de “rimpel” van de
stekkervoeding meten.

Sluit **kanaal A** van de oscilloscoop aan op de voeding (rood op rood
en zwart op blauw). De oscilloscoop moet ingesteld worden op **AC**
(wisselspanning). Bij de keuze gelijkspanning (**DC**) is de rimpel niet
zichtbaar omdat deze klein is ten opzichte van de 5 volt die de voeding
geeft.

Kies bij “channel options” (button naast de DC/AC keuze) voor een
resolutie van **8 bits**. Kies voor de gevoeligheid een **+/-100 mV**.
Kies voor de tijdbasis **2 ms/div**. en triggermode op **Auto**.

Het blijkt dat de stekkervoeding (met een prijs van minder dan 10 Euro)
een heel goede gelijkspanning afgeeft. De rimpel op de gelijkspanning is
nog net te meten.

Hoe groot is de rimpel **maximaal** (dus inclusief de grootste pieken)?
Meet in de persistence-mode voor een aantal seconden lang.

Geef het antwoord van **top tot top** (Vtt) in millivolt. Dat is dus de
spanning boven de nullijn plus de spanning onder de nullijn (schat de
waarde als het beeld niet goed stil staat):

```
Vtt-rimpel =    mV (maak een schermafdruk van de meting)
```

**Plaats het ingevulde meetrapport met de gemaakte schermafdrukken in de GitHub-repository van je team.**