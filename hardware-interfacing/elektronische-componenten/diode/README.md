![logo](../diode/img/diode.svg) [](logo-id)

# Diode[](title-id)

### Inhoud[](toc-id)

- [Diode](#diode)
    - [Inhoud](#inhoud)
  - [Een introductie](#een-introductie)
  - [Referenties](#referenties)

---

**v0.1.0 [](version-id)** Start document voor Diode door HU IICT[](author-id).

---

## Een introductie

A diode is a component that has a low resistance when a voltage is applied to it in one direction, but a high resistance when the voltage is applied to it in the other direction. Its symbol is like an arrow, pointing in the direction in which the diode will conduct current.

![Diode symbol](../diode/img/diode.svg)

For calculation purposes, you can assume that the ‘forward’ resistance is such that the voltage across the diode is 0.6V, and the ‘reverse’ resistance is infinite. When the voltage is less than 0.6V, you can assume that diode does not conduct (has infinite resistance).

The circuit shows a voltage source, two diodes and two resistors. The left diode is connected in reverse, hence no current flows through that diode and its resistor. The right diode is forward connected with a voltage > 0.6V, hence current flows through it. The diode ‘claims’ 0.6 V, hence 5V – 0.6V = 4.4V remains for the resistor. The current through the resistor (and through the diode) will be 4.4 V / 1000 Ω = 0.0044 A = 4.4 mA.

The diodes that you might use are small cylindrical objects, which an indicator band at the side where the symbol points to.

Note that connecting a diode directly to a voltage source (of more than 0.6V) is not a good idea: the diode will try to conduct as much current as needed to keep the voltage across its terminals down to 0.6V, while at the same time the voltage source will try to supply as much current as needed to keep that voltage at let’s say 10V. Something will have to give, in practice often the diode. If you watch this process (from a safe distance, with goggles, etc.) you might see some smoke (or even flames) escape from a puncture in the diode, and your diode is no longer functional. The same effect can be observed with other components that are grossly misused. From this observation comes the saying that “electronic components run on magic smoke”, because, if you let it escape, the component won’t work anymore. BTW: don’t try this at home. Or at least not **in** your home. And from a safe distance.

![Releasing the magic smoke from a diode](../diode/img/Magic_smoke.jpg)


## Referenties
- Diode (<https://nl.wikipedia.org/wiki/Diode>)

