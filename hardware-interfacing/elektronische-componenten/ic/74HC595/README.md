![logo](../1-wire/img/1-Wire-Protocol.png) [](logo-id)

# Communicatieprotocol: 1-Wire[](title-id)

### Inhoud[](toc-id)

- [Communicatieprotocol: 1-Wire](#communicatieprotocol-1-wire)
    - [Inhoud](#inhoud)
  - [Een introductie](#een-introductie)
  - [De schakeling](#de-schakeling)
  - [Referenties](#referenties)

---

**v0.1.0 [](version-id)** Start document voor HC595 IC door HU IICT[](author-id).

---

## Een introductie

Een (output) schuifregister is een chip waar je stap voor stap bitjes in kan schuiven. Het schuifregister heeft een aantal ‘stages’ achter elkaar, in het onderstaande plaatje. 

![Blokdiagram van een schuifregister met 4 stages.](../74HC595/img/Blokdiagram_schuifregister_4stages.png)

Alle stages zijn verbonden met een gemeenschappelijk klok signaal. Als dit kloksignaal verandert van laag naar hoog neemt iedere stage de waarde van de voorgaande over, en de eerste neemt de waarde op zijn ingang over. Hiermee kan je (in 4 stappen) de 4 stages ieder in een door jou gewenste toestand (hoog of laag) brengen. De uitgangen van de schuifregister stages (Q1 t/m Q4) kan je gebruiken als uitgangspinnen, bv. om LEDs aan te sturen. Met een schuifregister van 4 stages kan je zo 4 LEDs aansturen. Om een schuifregister op deze wijze aan te sturen zijn maar 2 GPIO pinnen nodig, ongeacht het aantal stages. Dit is handig als je meer uitgangen wil hebben dan je GPIOs ter beschikking hebt, of als je LEDs op afstand van je microcontroller zitten, en je het aantal draadjes naar de LEDs wil beperken.


    74HC595 schuifregister is geen SPI device we gebruiken SPI alleen om een 'bitstream' te genereren


## De schakeling

De 74HC595 chip is een veelgebruikt 8-stage (output) schuifregister. We gaan deze chip gebruiken om 8 LEDs aan te sturen.

Deze chip heeft behalve 8 schuifregister stages ook nog een opslag (‘holding’ of ‘latch’) register waarin de 8 bitjes opgeslagen worden, zodat het schuiven niet zichtbaar is op de uitgangspinnen.

![In een 74HC595: shuifregister en ‘hold’ register (heet hier ‘latch’)](../74HC595/img/HC595_latch.png)

Om 8 waarden op de uitgangspinnen van een 74HC595 chip te krijgen moeten we dus het volgende doen:

    1) Doe dit 8 keer:
    - Maak de data (shift) ingang van de HC595 gelijk aan de waarde van het hoogste (achtste) bitje van de value (want het eerste bitje dat je aanbiedt wordt het verst doorgeschoven)
    - Maak de shift clock ingang van de HC595 hoog, en daarna meteen weer laag
    - Schuif de bitjes in de value 1 stapje naar links (dit kan je doen door te vermeningvuldigen met een geschikte waarde)
    2) Maak de de holding / latch clock ingang hoog en meteen weer laag 
    3) (om het effect te laten zien moet je nu wachten)


![Tijdsvolgorde van de wat er gebeurt in een 74HC595](../74HC595/img/HC595_tijdsvolgorde.png)

De 74HC595 schuifregister heeft drie ingangen die aan de micro-controller moeten worden aangesloten: shift-clock (SHCP = SHift Clock Pulse), data (DS), en hold-clock (STCP = STorage Clock Pulse). Verder moet je natuurlijk GND en VCC (3.3V) aansluiten, en MR (Master Reset) aan VCC en OE (Outpout Enable) aan GND.

## Referenties

- Shift register (<https://en.wikipedia.org/wiki/Shift_register>)
- Datasheet (<https://www.ti.com/lit/ds/symlink/cd74hc595.pdf>)