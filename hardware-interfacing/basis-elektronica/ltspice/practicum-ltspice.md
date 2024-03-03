**Jouw naam:**

# Practicum LtSpice

# Voorbereiding

- Zorg dat je **ruim te voren** LtSpice hebt **geinstalleerd** (het kan uren duren (misschien, althans een update zeker)):
    <https://www.analog.com/en/design-center/design-tools-and-calculators/ltspice-simulator.html>
    
- Zorg dat je een of meerdere **tutorials ervan hebt doorgenomen**  
    ( bijvoorbeeld: <https://www.youtube.com/watch?v=JRcyHuyb1V0> )

**Belangrijke LtSpice Tips:**
- In "het echt" zet je vaak een condensator parallel aan een voeding, om diens spanning (extra) te ontstoren/vlak te maken.
- In (LtSpice-) simulaties kun je die condensators parallel aan voedingen (voorlopig) beter weglaten. Dat zorgt ervoor dat de simulatie trager wordt en moeilijker (of zelfs helemaal niet) convergeert.

-   In plaats van de PMOS-FET NDP6020P kun je in LtSpice: kiezen:  
    “pmos” met als type “FDC638P” (plaats eerst de “pmos”. Vervolgens
    rechter muisknop er op en “Pick new mosfet” -\> “FDC638P”

-   In plaats van een opamp van de chip LM324 kun je in LtSpice
    kiezen:  
    “UniversalOpamp2”, met “Level3b” (te selecteren met rechtermuisknop
    op de geplaatste opamp).

-   Je mag ervan uitgaan dat een LED goed zichtbaar brandt als er 1mA of
    meer doorheen gaat.

-   Een potmeter / potentiometer kun je in LtSpice modelleren met twee
    serieweerstanden. Je kunt de waarden van die twee serieweerstanden
    aanpassen, maar moet er dan wel voor zorgen dat de som van die
    weerstanden gelijk blijft (dus bijvoorbeeld 10k Ohm bij een 10k potentiometer
    gaat).    

    Alternatief kun je er een (custom-) model voor gebruiken of maken, waarbij de stand met een parameter in te stellen is. Dat zou je dan even (via chat gpt4 of google tutorials) kunnen uitvogelen.

## De Opdracht
### Servo controller bouwen
Bouw de servo-controller (gebruik een weerstand naar ground van 1 kOhm in plaats van het gele draadje van de servo) uit de vorige opdracht na in LtSpice. Gebruik daarbij geen NE55, maar modelleer die met aparte, eenvoudige componenten zoals in het tweede schema van het servo-controller practicum was aangegeven.   

Gebruik daarbij bijvoorbeeld:
- het model UniversalOpamp2 (zie tips) voor de comparators.
- 

