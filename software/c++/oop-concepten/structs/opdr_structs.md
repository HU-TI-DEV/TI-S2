# Opdrachten Structs C++[](title-id)

### Inhoud[](toc-id)

### Opdracht 4.3 Voorwerpen
Gegeven is de struct-definitie:

```c++
struct furniture {
    int number = 0;
    string name = "";
    float weight = 0.0;
    float length = 0.0;
};
```

Schrijf een programma dat de gebruiker vraagt om de gegevens van een meubelstuk. Stop
deze gegevens in een struct furniture en druk de gegevens vervolgens af. 
Een voorbeeld van de interactie is:
```
nummer: 5
naam: stoel
gewicht: 4.5
lengte: 90
stoel heeft nummer 5, weegt 4.5 kilo en is 90 cm.
```

### Opdracht 4.4 - Priority queue.
Een priority queue is een datastructuur die qua werking erg lijkt op een vector, maar
als verschil heeft dat enkel het eerste element bereikbaar is. De priority queue werkt
vanuit het first-in-first-out principe. In de onderstaande code (zie volgende pagina) is een
main-file te zien die gebruikt maakt van een priority queue en de source-file (queue.cpp)
van een implementatie van een priority queue. Schrijf de header-file van de priority queue.
In de header staat onder andere de definitie van de struct Queue.