---
# try also 'default' to start simple
theme: ./slidev-theme-hu
# https://sli.dev/custom/highlighters.html
highlighter: shiki
# show line numbers in code blocks
lineNumbers: false
# some information about the slides, markdown enabled
info: |
  ## Slidev Template for HU.

  Learn more at [Sli.dev](https://sli.dev)
fonts:
  sans: 'Avenir'
  serif: 'Roboto Slab'
  mono: 'Cascadia Mono'
# persist drawings in exports and build
drawings:
  persist: false
# page transition
transition: fade-out
# use UnoCSS
css: unocss
themeConfig:
  paginationX: r
  paginationY: t
  paginationPagesDisabled: [1]
layout: cover
---

<style>
code, pre {
  font-size: 0.9rem;
  line-height: 1.5rem;
}

pre {
  left: 6px;
  border-left: 3px solid rgba(255, 255, 255, 0.07);
}
</style>

# Technische Informatica Semester 2 (TI S2)

## HC595 Schuifregister

<subtitle><b>2023-2024</b><br>
TI Semester 2
</subtitle>

---

# Leerdoelen 

Aan het eind van deze les: 

- Heb je een eerste kennismaking gehad van een Geïntegreerde schakeling
- Heb je een datasheet gevonden en bekeken van een IC
- Heb je een 8-stage (output) schuifregister gebruikt

---
layout: intro
---

## Wat is een IC?

Een geïntegreerde schakeling is een samenstel waarbij diverse elektronische componenten op een enkel stuk halfgeleidermateriaal worden geplaatst.

![1966](/IntegratedCircuit1966.jfif)

<!-- 
De afkorting IC komt van de Engelse term Integrated Circuit. Als het een grote IC betreft wordt deze ook wel microchip of chip genoemd.
-->

---

# DIP en 74HC-serie

Al snel werden ICs gestandaardiseerd in DIP-beuizing.

![NE555N](/Signetics_NE555N.jfif)

[TI Lab Shop IC](https://hu-hbo-ict.gitlab.io/turing-lab/ti-lab-shop/LA04.html)

<!--
DIP Dual in-line Package
-->

---

# Output schuifregister 74HC595

 8bit shift register:
 - Meer output pinnen voor je project (er zijn maar 3 GPIO pinnen nodig voor 8 extra pinnen)
 - Als je Arduino of microcontroller op afstand staat
 - 74HC595 ondersteund daisy chaining  

![Pin diagram](/595_pin_diagram.png)

---

# Serial in parallel out

De 74HC595 werkt op basis van Serial IN Parallel OUT protocol (SIPO).

[How shift registers work(Animation)](https://www.youtube.com/watch?v=6nsQuKBRyl4)

Voorbeeld van een 4 bit shift register.

<!--
De IC ontvangt seriele data van de microcontroller en stuurt de data door naar parallele pinnen. De data wordt verzonden naar data in via pulsen van 5V hoog en laag voltages met synchronisatie van het clock signaal. 5V is een digital waarde 1. 0V een digitale waarde 0. Clock is een constante hoog en laag signaal met een vastgestelde frequentie. Deze kan werken als een data shifter voor de registers.
-->

---

# 74HC595 datasheet

[74HC595 datasheet](https://www.ti.com/lit/ds/symlink/cd74hc595.pdf)

![Pin diagram](/595_pin_diagram.png)

| PINS 1-7, 15	| Q0 - Q7	| Output Pins |
| --- | --- | --- |
| PIN 8	| GND	| Ground, Vss |
| PIN 9	| Q7	| Serial Out |
| PIN 10 | MR	| Master Reclear, active low |
| PIN 11 | SH_CP | Shift register clock pin |
| PIN 12 | ST_CP | Storage register clock pin (latch pin) |
| PIN 13 | OE	| Output enable, active low |
| PIN 14 | DS	| Serial data input |
| PIN 16 | Vcc | Positive supply voltage |

<!--
MR Master Reclear en OE Output Enable gebruiken we niet, dit zorgt wel voor undefined behaviour tijdens het opstarten. Je kan er voor kiezen ook deze pinnen met je Arduino aan te sturen. De pinnen die actief laag zijn hebben een streep boven de Pin benaming. Q7' is geen output maar serial out om een volgende 74HC595 te daisy-chaining.
-->


---

# Binary

Voorbeeld is


---

# Arduino voorbeeld
