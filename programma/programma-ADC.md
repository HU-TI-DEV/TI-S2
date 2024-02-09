# Samenvatting ["Analoge pin uitlezen."](../hardware-interfacing/communicatie/analoog-en-digitaal/ADC/README.md)

## Na deze les

* heb je een werkend Arduino IDE op jouw laptop
* kan je met de Arduino IDE een Arduino Uno met een programma flashen
* kan je de serial output van deze programma zien in de [Serial Monitor](#serial-monitor)
* kan je in jouw team op een breadboard een eenvoudige schakeling opbouwen om met een [LDR of NTC](../hardware-interfacing/communicatie/analoog-en-digitaal/ADC/LDR-NTC.md) veranderingen in de omgeving in een spanning om te zetten
* kan je een spanning door een Analog Input pin op de Arduino Uno laten omzetten in een getal van 0 t/m 1023 en deze getal in jouw eigen programma verwerken
* weet je dat je moet opletten dat de spanning die je wil meten niet te hoog is voor de Analog Pin van een microcontroller, anders kan de hele microcontroller kapot gaan
* weet je dat het omzetten van Analog Input getallen naar een voor mensen geschikte waarde (bijvoorbeeld Lux of graden Celsius) vaak iets meer werk nodig heeft (kijk in de datasheet van de sensor of doe eigen onderzoek)

### Serial monitor

De Arduino IDE heeft een serial monitor ingebouwd. Deze kan je openen met het menu `Tools` > `Serial Monitor`.
Let op dat de ingestelde snelheid (bv 9600 baud) dezelfde is als met `Serial.begin()` ingesteld in jouw programma.
