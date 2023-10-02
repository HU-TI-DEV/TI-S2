![logo]() [](logo-id)

# Capacitor[](title-id)

### Inhoud[](toc-id)

- [Capacitor](#capacitor)
    - [Inhoud](#inhoud)
  - [Een introductie](#een-introductie)
  - [Referenties](#referenties)

---

**v0.1.0 [](version-id)** Start document voor Capacitor door HU IICT[](author-id).

---

## Een introductie

A capacitor is a component that can store current (as charge). When current ‘enters’ a capacitor, the capacitor charges and the voltage across the capacitor rises. A charged capacitor can deliver current. When it does so, the voltage falls. How fast the voltage rises and falls depends on the capacity of the capacitor, expressed in Farads (symbol F). A one Ampere current into a one Farad capacitor will rise the voltage by one Volt each second. In a formula (∆ means change):

$$
∆ V = I * ∆  T/C
$$

One Farad is a very high value, most capacitors have a much lower value, from a few pF up to 100.000 µF (for some reason, mF is almost never used). Two important purposes for capacitor’s are storage and timing. The symbol for a capacitor is two parallel lines, which mimic how a capacitor is physically constructed. One of the lines can be an open box, which identifies the capacitor as an electrolytic capacitor, which requires that the box side is the positive side. Capacitors of 10 µF and more are often electrolytic.

Batteries and accus are not very good at delivering an amount of current that changes very quickly: when you try to do this the voltage will change rapidly (and dramatically). A chip can draw a (quickly) varying amount of current, and doesn’t respond well to a change in its power supply voltage. The solution is to place a **decoupling** capacitors close to the chip. This capacitor charges itself to the voltage of the power supply, and when the chip requires a large current for a short time the capacitor will deliver this. The capacitance of the capacitor must be high enough that this short current draw doesn’t lower the voltage too much. In practice values of 100nF or 1µF are used close to key chips, and values of 1µF up to 1000µF for one capacitor per PCB.

Modern micro-controllers draw **very** large current spikes, run at very low voltage, and are very sensitive to voltage variations. Hence modern PC moter- boards have a large number of capacitors around the CPU to supply it with a smooth voltage. Due to the high current spikes and the high temperature around the CPU special ‘high temperature, high current’ are used. Still, when a motherboard malfunctions one or more of these capacitors are often defect.

The other common use of a capacitor is for timing. When constant current flows into a capacitor, the voltage across that capacitor indicates how long the current has been flowing. Turning this around, if we want to do something after a fixed amount of time, we can start with an empty capacitor, charge it with a constant current, do whatever we need to to when the voltage reaches a particular level.

Now imagine that ‘what we do’ is emptying the capacitor, and we have a periodic system, with the period determined by the current, the capacitor, and the voltage at which we discharge the capacitor. This is called a **relaxation oscillator**. A very simple realisation uses a neon lamp. Such a lamp doesn’t conduct (has a high resistance) until its breakdown voltage ( 80V) is reached. At that moment it ‘breaks down’ and has a low resistance, until its voltage drops to a very low value (≈ 20V).


## Referenties

- Capacitor (<https://en.wikipedia.org/wiki/Capacitor>)