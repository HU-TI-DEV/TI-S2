# Het Finite State Machine (FSM) Paradigma

In deze les gaan we ontdekken dat we door toepassing van het FSM-paradigma op een microcontroller veel dingen tegelijk kunnen doen en toch overzichtelijke code kunnen houden.

## Voorbereiding

- Neem je electronica spullen (breadboard, weerstanden etc) mee.   

- Lees van [VDEIN microcontrollers reader](https://github.com/HU-TI-DEV/TI-S2/blob/main/hardware-interfacing/pdfs/2017-2018-VDEIN-micro-controllers-reader.pdf) blz 13 tm 21 goed door. Bestudeer met name de delen die gaan over FSM.
- Wat highlights daarvan kun je ook in video-vorm bestuderen: [video finite state machine paradigm](https://www.youtube.com/watch?v=xMtzhGA3vIc)

## Tijdens de les

Tijdens de les breng je de kennis die je hebt opgedaan tijdens je voorbereiding in praktijk:<br>
Wat hebben we nodig:
- breadboard & jumper wires <br>
- 3 verschillende kleuren ledjes<br>
- 3 voorschakelweerstanden voor de ledjes (kun je zelf de waarde berekenen?)<br>
- 2 knopjes<br>
- 2 pull up weerstanden voor de knopjes<br>

### We gaan een stoplicht nabouwen. <br>
Het stoplicht zal normaal op groen staan. <br>
Knopje A is verbonden met de knop van het voetgangerspad op de straat die er loodrecht op staat/loopt.<br>
Knopje B is verbonden met de knop van het voetgangerspad van de straat waar het stoplicht staat. <br>
Het stoplicht staat normaal op groen. Als op knopje A wordt gedrukt moet het stoplicht van groen -> oranje/geel -> rood gaan. Dan moet hij op rood blijven staan.<br>
Als knopje B wordt ingedrukt moet hij (het is een duits stoplicht) van rood -> knipperend rood & orange/geel -> groen gaan.<br>

1) Maak eerst een State diagram (hier zijn UML standaarden voor, we gaan nu even iets simpels edoch duidelijk schetsen.
2) Maak de opstelling.
3) Maak de Class(es).
4) Check met je diagram.
5) Testen!  



### Canvas
- Lever het resultaat in op de Canvas entry voor deze opdracht.   

## Portfolio Tip
Pas het FSM paradigma ook zoveel mogelijk toe. Zowel in je eigen applicatie als in die van het totale project. Laat een voorbeeld van een van je toepassingen daarvan van feedback voorzien.
