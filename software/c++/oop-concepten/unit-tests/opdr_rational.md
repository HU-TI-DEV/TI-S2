# Opdracht Rational Unit Test[](title-id) <!-- omit in toc -->

### Inhoud[](toc-id) <!-- omit in toc -->
- [Opdracht OO2.3 Catch2](#opdracht-oo23-catch2)
  - [Opdracht OO2.3C Test rational.hpp](#opdracht-oo23c-test-rationalhpp)


### Opdracht OO2.3 Catch2
Maak eerst [opdrachten OO2.3A en OO2.3B](./opdr_catch2.md). Pas daarna kun je deze - vervolg - opdracht doen.

#### Opdracht OO2.3C Test rational.hpp
Je gaat een catch2 test-file aanpassen die geschreven is voor de `rational.hpp` library voor rationele getallen (breuken).
- Gebruik de (library) file [rational.hpp](./rational.hpp).
- Gebruik de file [test-rational.cpp](./test_rational.cpp).
- Gebruik de `main.cpp` die onderaan dit bestaand staat.

- Als je de `test-rational.cpp` runt zie je dat er een aantal fouten zit in de library. 
  - Verbeter die fouten. 
  - Implementeer eerst een `operator<<` voor rationele getallen, die de beide getallen in een breuk (de teller en de noemer) print in vier posities. Dit doe je met hexadecimale getallen, voorloopnullen en `0x` ervoor.

```cpp
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
```
*main.cpp*