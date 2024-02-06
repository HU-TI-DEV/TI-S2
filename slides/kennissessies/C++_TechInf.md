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

# Kennissessie 01

## C++ en Technische Informatica

<subtitle><b>2023-2024</b><br>
TI Semester 2
</subtitle>

---

# Slidev

# 1 Introductie

Vandaag maken we een start met **programmeren in C++**.
Ook installeren we de benodigde **ontwikkelomgeving**.

Inhoud zie: 
[Introductie C++](../../software/c++/README.md#introductie-c)

# 2 Programmeren bij TI

Bestudeer de informatie in: [Introductie C++](../../software/c++/README.md#introductie-c).

Beantwoord de volgende vragen:

- Wat maakt programmeren bij TI anders dan bij andere studierichtingen?
- Waarom leer je C++ bij Technische Informatica?

---

# 3 Installatie Game VSC

Inhoud zie: 
[Installatie VSC ontwikkelomgeving](../../software/inrichten-ontwikkelomgeving/visualstudiocode.md)

Let op: de aanwijzingen in het document staan nog niet allemaal goed. Soms staan ze er dubbel in. Misschien is er een stap vergeten.
Voor elke **verbetering** ontvang je een punt.

*Installeer de benodigde ontwikkelomgeving.*
Je speelt de game in teams tegen elkaar.
Het doel van de game is om zo snel mogelijk met alle leden van de groep de ontwikkelomgeving geinstalleerd te krijgen; het lastige is dat op elk moment alle groepsleden even ver in het installatieproces moeten zijn.
Tijdens de game, worden er een paar 'meetmomenten'
uitgevoerd. Tijdens die meetmomenten geldt: de groep krijgt
- pluspunten: voor elke stap die alle teamleden hebben uitgevoerd in het installatieproces (synchronisatiepunten).
- minpunten: als teamleden 'uit de pas lopen'. Hoe groter het verschil is tussen de teamleden, hoe meer puntenaftrek de groep krijgt.
  
# 4 Installatie Arduino IDE + Blink

Opdracht:
De volgende opdracht voer je uit met je team. De bedoeling is dat iedereen in je team een Arduino UNO kan laten knipperen. 
Je gebruikt hiervoor:
- [de Arduino IDE](https://docs.arduino.cc/learn/starting-guide/the-arduino-software-ide/), 
- een Arduino UNO (een per groepje is genoeg)
- een C++ programma.

![Selecteer blink in Arduino IDE](image.png)

