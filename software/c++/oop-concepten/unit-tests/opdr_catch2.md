# Opdracht Catch2 Unit Test[](title-id)

### Inhoud[](toc-id)
- [Opdracht Catch2 Unit Test](#opdracht-catch2-unit-test)
    - [Inhoud](#inhoud)
    - [Opdracht OO2.3 Catch2](#opdracht-oo23-catch2)
      - [Opdracht OO2.3A Installeer Catch2](#opdracht-oo23a-installeer-catch2)
      - [Opdracht OO2.3B Test Catch2](#opdracht-oo23b-test-catch2)


### Opdracht OO2.3 Catch2
#### Opdracht OO2.3A Installeer Catch2
- Installeer, indien nodig, Catch2.
  - De meest eenvoudige Catch2 versie is de [single-header-version](https://github.com/catchorg/Catch2/blob/v2.x/docs/tutorial.md#top). 
  - Je kunt deze single-header versie ook installeren via [MSYS2](https://packages.msys2.org/base/mingw-w64-catch).
  - [Catch2 tutorial](https://github.com/catchorg/Catch2/blob/v2.x/docs/tutorial.md#top)
  
#### Opdracht OO2.3B Test Catch2
- Maak een folder aan voor deze opdracht met de volgende bestanden: (`xy.hpp`, `tests.cpp` en `main.cpp`); deze staan onderin dit bestand.
- Met deze bestanden kun je testen of je Catch2 installatie werkt. Er zitten GEEN fouten in de library of de geschreven tests.

```cpp
#ifndef XY_HPP
#define XY_HPP

class xy {
public:
   int x;
   int y; 
   
   xy( int x, int y ): 
      x( x ), y( y )
   {}
   
   xy():
      x( 0 ), y( 0 )
   {}
   
};

#endif
```
*xy.hpp*


```cpp
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
```
*main.cpp*


```c++
#include "ostream"
#include "xy.hpp"

#include "catch.hpp"

bool operator== (xy lhs, xy rhs)
{
    return (lhs.x == rhs.x) && (lhs.y == rhs.y);
}

std::ostream& operator<< (std::ostream& lhs, xy rhs)
{
    return lhs << "(" << rhs.x << "," << rhs.y << ")";
}

TEST_CASE ("constructors, two_parameters")
{
    xy v (3, 4);
    REQUIRE (v.x == 3);
    REQUIRE (v.y == 4);
}

TEST_CASE ("constructors, default")
{
    xy v;
    REQUIRE (v == xy (0, 0));
}
```
*tests.cpp*