# Practicum Comparator - MOSFET

## Tip: Datasheet opdrachten het laatst
Het is een goed idee om te proberen tijdens de les de praktijk-gerelateerde opdrachten klaar te hebben, en daarna pas te beginnen aan de datasheet gerelateerde opdrachten (die kunnen makkelijker na de les worden afgemaakt).

## Benodigd

- Een breadboard
- Een multimeter
- Een LM324 (chip met 4x opamp)
- Een 10k potmeter (potentiometer of regelbare weerstand)
- Een 2 weerstanden van 1k
- Een weerstand van 2,2k
- Breadboard wires of draad+striptang
- Een PMOS-FET NDP6020P
- Een weerstand van 10k
- Een weerstand van 100 Ω

# Comparator

## Benodigd

- Een breadboard
- Een multimeter
- Een LM324 (chip met 4x opamp)
- Een 10k potmeter (potentiometer of regelbare weerstand)
- Een 2 weerstanden van 1k
- Een weerstand van 2,2k
- Breadboard wires of draad+striptang

## Opdracht

1. Bouw de volgende schakeling, met Vsup=5V, R1=1k, R2=1k, R3=2,2k,
   P1=10k en een van de opamps op een LM324 (zoek de pinnen op in zijn
   datasheet).

<img title="" src="./media/media/image4.png" alt="" width="527">

1. Potentiometer P1 is nu geschakeld als instelbare weerstandsdeler. Je
   kunt het zien als een spanningsdeler bestaande uit twee weerstanden
   waarvan de som 10k is.  
   Je kunt met P1 knooppuntsspanning V3 dus instellen tussen 0 en
   Vsup.  
   **Teken nu een grafiek met op de horizontale as V3 en op de
   verticale as V4. Zorg dat de waarde van V3 bij het “omslagpunt”
   nauwkeurig is verwerkt. Verklaar de grafiek**

2. Stel nu dat je de ingangen andersom aansluit:  
   <img title="" src="./media/media/image6.png" alt="" width="461">  
   
   **Hoe gedraagt de schakeling zich dan? Verklaar!****  
   
   **Zoek op in de datasheet van de opamp:****

3. **Wat is zijn typische versterkingsfactor? (de versterking van de
   verschil-spanning tussen zijn ingangen naar de knooppuntsspanning op
   zijn uitgang)**

4. **Wat is zijn maximale input offset spanning?
   Wat heeft dat tot gevolg in bovenstaande schakeling? ** 

5. **Wat is zijn maximale input instel stroom?   
   Wat heeft dat tot gevolg in bovenstaande schakeling?** 

6. **Wat is zijn maximale input offset stroom?  
   Wat heeft dat tot gevolg in bovenstaande schakeling?**

7. **Wat is de minimaal gegarandeerde stroom die zijn uitgang kan
   “sinken” (die er in kan stromen)?**

8. **Wat is de minimaal gegarandeerde stroom die zijn uitgang kan
   “sourcen” (die er uit kan stromen)?**

9. **Stel dat we de led+R1 zouden vervangen door een 5V motor die 1A
   stroom nodig heeft, zou die motor dan met deze schakeling aan een
   uitgezet kunnen worden? Waarom wel/niet?**

10. **Wat is de kleinste voedingsspanning waarvoor de opamp nog goed
    werkt?**

11. **Wat is de maximale voedingsspanning?**

12. **Wat is zijn maximale stroomverbruik (als je niets aan de uitgangen
    hangt)?**

13. **Wat is de maximale uitsturing (uitgangsspanning) naar beneden (bij
    5V voedingsspanning en een 10k weerstand als belasting naar de
    positieve voedingsspaning)?**

14. **Wat is de maximale uitsturing (uitgangsspanning) naar boven (bij
    5V voedingsspanning en een 2k weerstand als belasting naar
    ground)?**

# PMOS transistor

## Benodigd

- Een breadboard
- Een multimeter
- Een PMOS-FET NDP6020P
- Een 10k potmeter (potentiometer of regelbare weerstand)
- Een weerstand van 10k
- Een weerstand van 100 Ω
- Breadboard wires of draad+striptang

## Opdracht

1. Bouw de onderstaande schakeling, met Vsup=5V, P1=10k, R2=10k en
   R1=100 Ω.  
   Zoek in de datasheet van de PMOS zijn pinnen op. Zijn source is met
   de voedingsspanning verbonden, zijn drain met belastingsweerstand R1
   en zijn gate met (stroom-) meetweerstand R2.  
   
   <img title="" src="./media/media/image7.png" alt="" width="435">

2. Met P1 kun je V1 regelen. D.m.v. een spanningsmeting over R2 en de
   wet van Ohm kun je de stroom bepalen die in de gate van de PMOS
   transistor loopt.  
   Varieer V1 langzaam van 0V tot 5V, terwijl je de spanning VR2 over
   R2 meet.  
   **Wat is de hoogste spanning VR2 die je hebt gemeten?**

3. **Wat is de hoogste stroom die in de gate van de PMOS transistor
   loopt?**

4. **Maak nu een grafiek met V1 op de horizontale as (van 0V tot 5V, in
   stappen van 0,25V) en I1 langs de verticale as (I1 bepaal je door de
   spanning over R1 te meten en de wet van Ohm te gebruiken).**  
   
   **Zoek in de datasheet van de PMOS op:**

5. **Wat de maximale drain-stroom is die hij kan leveren.**

6. **Wat de maximale source-drain spanning is waarbij hij nog kan
   werken.**

7. **Wat de maximaal toegestane source-gate spanning is.**

8. Bij de eerste schakeling in de comparator opdracht zagen we dat de
   comparator niet al te veel stroom kan “sourcen”.  
   Stel nu dat we met de comparator (in plaats van een led+R1) een 5V
   motor willen aanschakelen (die 1A stroom verbruikt als hij aan
   staat).  
   **Bedenk een aanpassing van die schakeling waardoor dat mogelijk
   wordt (hint: gebruik de PMOS). Leg uit hoe het werkt.**

9. Je kunt ook sterke stromen schakelen met een NMOS transistor.**  
   **In wat voor situaties zijn NMOS transistors handiger?**  
   **In wat voor situaties zijn PMOS transistors handiger?**  
