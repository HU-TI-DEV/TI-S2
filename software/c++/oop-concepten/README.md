# Object Oriented concepten C++[](title-id)

### Inhoud[](toc-id)

- [Object Oriented concepten C++](#object-oriented-concepten-c)
    - [Inhoud](#inhoud)
  - [Introductie](#introductie)
    - [Onderwerpen](#onderwerpen)
    - [Wanneer gebruik je C++?](#wanneer-gebruik-je-c)
    - [Toepassingsgebied C++](#toepassingsgebied-c)
    - [Geen interpreter](#geen-interpreter)

---

**v0.1.0 [](version-id)** Start document voor OO programming concepten C++ door HU IICT[](author-id).

---

## Introductie

### Onderwerpen
In dit onderdeel worden 
- de beginselen van het Object Oriented (OO) programmeren in C++ behandeld, en een aantal bijbehorende aspecten van software engineering, zoals 
- het gebruik van UML diagrammen voor klassen, 
- het testen op unit niveau met Catch2, en 
- het documenteren van interfaces met Doxygen. 
  
Er wordt van uitgegaan dat de student eerder ervaring heeft opgedaan met C++ (procedureel programmeren) en Python.

### Wanneer gebruik je C++? 
De programmeertaal C++ wordt gebruikt voor **toepassingen waar de run-time snelheid (en soms ook het gebruik van andere resources, bijvoorbeeld geheugen) van doorslaggevend belang is**. Dergelijke toepassingen kun je vinden bij ‘grootverbruikers’ van computertijd zoals Google, bij flitshandelaren - waar een milliseconde het verschil tussen winst en verlies kan betekenen, en bij besturingssystemen - zoals Windows en Linux - en in gadgets.

### Toepassingsgebied C++
Het toepassingsgebied van C++ valt voor een groot deel samen met dat van C. Dat is niet toevallig: 
C++ is een poging om aan C een aantal moderne concepten toe te voegen (vooral Object Oriëntatie, Abstracte Data Types, templates, en excepties) zonder concessies te doen aan de performance (snelheid en omvang van een applicatie).

### Geen interpreter
Talen zoals Python, C# en Java hebben een interpreter nodig om programmacode uit te voeren. C++ is in dat opzicht een lastigere taal om in te programmeren omdat de programmeur zelf verantwoordelijk is voor veel details met betrekking tot *geheugenmanagement*. C++ is bedoeld voor toepassingen waarbij de voordelen (performance) zwaarder wegen dan deze nadelen (lastiger te programmeren).