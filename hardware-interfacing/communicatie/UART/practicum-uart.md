# Practicum Uart

## Voorbereiding

- Neem een arduino mee.
- Neem een geinstalleerde raspberry pi mee.
- Neem je electronica spullen (breadboard, weerstanden etc) mee.
- Neem je logic analyser mee (als je die al hebt)
- Lees alvast de lesstof door: [uart](../README.md) en [uart](./README.md)
- Kijk de volgende video [Salae Logic Analyser Tutorial](https://www.youtube.com/watch?v=rR5cEFRO9_s)
- Een indruk voor de plaats van deze opdracht in het geheel vind je [in dit overzicht](./img/overzicht1.png) en [in dit overzicht](./img/overzicht2.png).

## Opdracht 1
Laat je arduino via uart (rx,tx) communiceren met de arduino van je buurman.    
<img src="./img/opdracht1.png" width="350px" />

### Vraag a
Noteer je bevindingen / persoonlijke lessen. 
### Vraag b
Voeg een foto toe van een screenshot van de logic analyser met daarop een gecommuniceerde byte. Leg uit hoe uit de bits volgt dat de waarde van de gecommuniceerde byte het getal is dat de logic analyser erbij weergeeft.

## Opdracht 2
Laat je arduino via seriele verbinding (rx,tx pinnen) communiceren met je raspberri-pi.   
<img src="./img/opdracht2.png" width="450px" />
### Vraag a
Noteer je bevindingen / persoonlijke lessen.

## Bonus Opdracht 1
Communiceer vanuit een python of c++ programma op je windows laptop via uart met je raspberri pi ([gebruik python op VSCode](../../../software/python/python-op-vscode.md)).
Leen daarvoor een USB to serial converter.
Check even welk type je gebruikt. Als het gebruik maakt van een CP210x chip, kun je hier de driver downloaden:  [driver voor CP210x](https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers?tab=downloads))   
<img src="./img/bonus-opdracht.png" width="350px" />

### Vraag a
Welke code heb je gebruikt op de pc kant?
### Vraag b
Noteer je bevindingen / persoonlijke lessen.

## Bonus Opdracht 2
Zelfde als de vorige Bonus Opdracht, maar nu twee laptops die (zonder arduinos) via USB-naar-Serial converters met elkaar communiceren.
