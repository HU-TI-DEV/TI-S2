![logo](/hardware-interfacing/communicatie/analoog-en-digitaal/img/Original_message.jpg) [](logo-id)

# DAC: digitaal naar analoog[](title-id)

### Inhoud[](toc-id)

- [DAC: digitaal naar analoog](#dac-digitaal-naar-analoog)
    - [Inhoud](#inhoud)
  - [Een introductie](#een-introductie)
  - [PWM](#pwm)
  - [Dyty cycle](#dyty-cycle)
  - [Referenties](#referenties)

---

**v0.1.0 [](version-id)** Start document voor digitaal naar analoog door Marius Versteegen[](author-id) en Jorn Bunk[](author-id).

---

## Een introductie

*Digital-to-Analog Converters* (DAC) hebben net als ADC’s een beperking met betrekking tot de resolutie van het signaal. Afhankelijk van hoeveel bits ze als input hebben kunnen ze een hoeveelheid verschillende analoge signalen maken. Er zijn verschillende types van *Digital-to-Analog Converters*  (DAC). We gaan hier in op *Pulse Width Modulation*  (PWM), omdat dit een techniek is die je als Technische Informaticus nog wel eens zal implementeren. Naast PWM zijn er ook andere type DAC’s.

## PWM

Bij PWM is de output niet direct een analoog signaal. Iets wat andere DAC wel produceren In plaats daarvan stuurt PWM pulsen van digitale signalen. Door deze in lengte te variëren staat er “gemiddeld” een bepaalde analoge waarde op een draad. 

## Dyty cycle

De lengte van de digitale signalen drukken we bij PWM uit in *duty cycle*. De duty cycle beschrijft hoe de verhouding is van hoe lang het signaal hoog is en hoe lang het signaal laag is.

![Duty cycle](../DAC/img/Duty_Cycle_Examples.png)

In bovenstaand figuur zien we drie voorbeelden van duty cycle. PWM is makkelijk zelf te implementeren door snel, in de juiste verhouding, een pin een hoog signaal en daarna weer een laag signaal te laten sturen. Het nadeel hiervan is dat microcontroller dan ondertussen geen andere taken kan uitvoeren. Gelukkig is hier ook specifieke hardware (zoals de TL5002) voor. Op de meeste Arduino’s zijn enkele pins uitgerust met PWM. Voor de meeste Arduino’s zijn dat pin 3, 5, 6, 9, 10 en 11. PWM is erg handig als je bijvoorbeeld een elektromotor of servo wil aansturen.

## Referenties

- Analoog en digitaal (<https://en.wikipedia.org/wiki/Analogue_electronics#Analogue_vs_digital_electronics>)
- Pulse-width modulation (<https://en.wikipedia.org/wiki/Pulse-width_modulation>)