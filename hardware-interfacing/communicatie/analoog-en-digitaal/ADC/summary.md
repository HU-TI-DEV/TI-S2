# Samenvatting ["Analoge pin uitlezen."](README.md)

Na deze les/oefening:

* heb je een werkend Arduino IDE op jouw laptop
* kan je met de Arduino IDE een Arduino Uno met een programma flashen
* kan je de serial output van deze programma zien in de [Serial Monitor](#serial-monitor)
* kan je in jouw team op een breadboard een eenvoudige schakeling opbouwen om met een [LDR of NTC](LDR-NTC.md) veranderingen in de omgeving in een spanning om te zetten
* kan je een spanning door een Analog Input pin op de Arduino Uno laten omzetten in een getal van 0 t/m 1023 en deze getal in jouw eigen programma verwerken
* weet je dat je moet opletten dat de spanning die je wil meten niet te hoog is voor de Analog Pin van een microcontroller, anders kan de hele microcontroller kapot gaan
* weet je dat het omzetten van Analog Input getallen naar een voor mensen geschikte waarde (bv Lux of graad celsius) vaak iets meer werk nodig maakt (kijken in een datasheet of eigen onderzoek)

## Serial monitor

De Arduino IDE heeft een serial monitor ingebouwd. Deze kan je openen met het menu `Tools` > `Serial Monitor`.
Let op dat de ingestelde snelheid (bv 9600 baud) dezelfde is als met `Serial.begin()` ingesteld in jouw programma.
