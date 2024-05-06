# Opdracht OO Programming concepten [](title-id)

### Inhoud[](toc-id)
- [Opdracht OO Programming concepten ](#opdracht-oo-programming-concepten-)
    - [Inhoud](#inhoud)
    - [Opdracht OO3.6 Kassysteem](#opdracht-oo36-kassysteem)
      - [Ontwerp klassen](#ontwerp-klassen)
      - [Ontwerp relaties](#ontwerp-relaties)
      - [Maak een klassediagram](#maak-een-klassediagram)
      - [Review](#review)
      - [Implementatie](#implementatie)
      - [Documenteer](#documenteer)
      - [Test](#test)
    - [Extra uitdaging - hardware](#extra-uitdaging---hardware)
    - [Extra uitdaging - interfaces](#extra-uitdaging---interfaces)

### Opdracht OO3.6 Kassysteem
*Dit is een grote opdracht! Doe deze opdracht alleen als je niet achterloopt met de andere C++ opdrachten en OO1.2 t/m OO1.6 al gemaakt hebt.*
Verdiep je vooraf in [overerving](./README.md) en [virtual en abstract](./virtual-abstract.md).

#### Ontwerp klassen
Begin eerst met **ontwerpen** (dus schrijf nog geen code).
1. Ontwerp een klasse `Plant`. 
2. Zorg dat de klasse `Plant` meerdere *attributen* heeft. Bedenk zelf welke.
3. Zorg dat de klasse `Plant` meerdere *methoden* heeft. Bedenk zelf welke.

4. Ontwerp een klasse `Kas`.
5. De `Kas` heeft bepaalde eigenschappen zoals temperatuur, luchtvochtigheid, etc.. 
6. Denk na over welke *functies* je wilt aanbieden in jouw systeem en hoe. Bepaal de interface.
*Lees meer over interfaces in [header-sourcefiles](../header-sourcefiles/README.md).*

#### Ontwerp relaties
7. Bepaal de relaties tussen `Plant` en `Kas`. Mogelijk heb je extra klassen nodig; bijvoorbeeld voor sensoren.

#### Maak een klassediagram
8. Maak een **UML diagram** van de klassen die je gebruikt, inclusief relaties en mogelijke aantallen.

#### Review
9. Vraag een **collegiale review** aan een klasgenoot die even ver is. Het review is op basis van je ontwerp. 
10. Verwerk de feedback.
11.  Geef een collegiale review aan dezelfde klasgenoot terug: geef feedback op het ontwerp van de ander.
Let op: Het is niet de bedoeling dat je elkaars keuzes overneemt. 
Het review moet helpen om je ontwerp te kunnen verbeteren en eventueel uit te breiden.

#### Implementatie
Pas nu ga je code schrijven.
12. Implementeer de klassen `Plant` en `Kas` in C++. Maak gebruik van .hpp en .cpp files.
13. Implementeer de extra klassen die je nodig hebt.

#### Documenteer
14. Documenteer je code met [Doxygen](../doxygen/README.md).

#### Test
15.  Schrijf *unit tests*. Je kunt hiervoor [Catch2](https://github.com/catchorg/Catch2) gebruiken, of Google Test [GTest](https://google.github.io/googletest/). 

### Extra uitdaging - hardware
16.  Hoe kun je *hardware* in je Kas Systeem verwerken? Maak je hier klassen van?
Overleg dit met anderen en breid zonodig je ontwerp uit.
Werk elke keer je ontwerp bij (versiebeheer).

### Extra uitdaging - interfaces
17.  Maak gebruik van *abstracte klassen* en *interfaces*. 
Je kunt bijvoorbeeld een abstracte interface `IVochtSensor` maken die de basis is voor een gesimuleerde VochtSensor en voor een hardware VochtSensor.