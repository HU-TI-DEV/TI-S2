# Geschiedenis C++[](title-id)

### Inhoud[](toc-id)

**v0.1.0 [](version-id)** Start document voor geschiedenis C++ door HU IICT[](author-id).

---
## Grondlegger C++
De taal C++ is vanaf 1979 ontwikkeld door **Bjarne Stroustrup** omdat hij de run-time snelheid van C wilde combineren met de Object Oriented features van Simula.

## C en C++
Oorspronkelijk werd C++ gerealiseerd als een pre-compiler: de uitvoer van de C++ compiler was een C programma, dat door een C compiler werd gecompileerd tot een executable (uitvoerbaar programma). Om niet een geheel nieuwe taal uit te moeten vinden en om het programmeurs met C ervaring makkelijk te maken C++ te gebruiken werd vrijwel de hele C taal (zoals die in 1979 in gebruik was) opgenomen in C++. Alle specifieke C++ eigenschappen kan je dus zien als uitbreidingen op C. Vandaar de naam C++: C, maar dan 1 stap verder. In latere jaren werd de relatie tussen C en C++ wat complexer, omdat aan beide talen nieuwe functies werden toegevoegd, die daarna (soms) ook door de andere taal werden overgenomen. Maar nog steeds is het zo dat de meeste (realistische) C programma’s door een C++ compiler als legaal C++ gecompileerd zullen worden.

### C++ standaard
Het heeft lang geduurd voor er een officiële C++ standaard was (C++98). Daarvoor was een bepaald boek van Stroustrup de ‘de facto’ standaard, maar iedere compiler implementeerde toch een iets andere versie van de taal. 
De eerste standaard in 2003 (C++03) bracht niet veel nieuws, eigenlijk alleen wat ‘bug fixes’. 

#### C++11, C++14 en C++17
De 2011 standaard (C++11) bracht heel veel nieuwe features en verschoof de aandacht van een voornamelijk OO taal naar andere, op templates gebaseerd programmeerstijlen. 
De 2014 en 2017 standaarden brachten (in vergelijking met de veranderingen in C++11) wel interessante nieuwe features, maar geen grote verschuiving. 

#### C++20 en C++23 en verder
De meest recente standaarden zijn C++20 (december 2020) en C++23 (mei 2023).
De relatief snelle opeenvolgingen van C++ standaarden wordt door sommigen verwelkomd omdat het de programmeurs nieuwe mogelijkheden biedt. Door anderen wordt het verafschuwd omdat het betekent dat ze om een programma dat deze functies gebruikt deze functies moeten leren, ook al willen ze die zelf niet gebruiken. In vergelijking met C++ is de taal C veel stabieler gebleven.

### Resource constrained
C en C++ zijn de belangrijkste talen voor het programmeren van applicaties die het uiterste vergen van de machine waar ze op draaien. Meestal betekent dit dat een C of C++ applicatie ‘resource constrained’ is: er is een resource, die zo goed mogelijk benut moet worden. Vaak is dit 
- CPU tijd, maar het kan ook 
- geheugen zijn, of 
- reactietijd. 
C en C++ bieden de programmeur vrijwel volledige controle over wat de computer - waar het programma op draait - precies doet.
1