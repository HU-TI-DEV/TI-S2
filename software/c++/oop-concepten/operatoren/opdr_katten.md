# Opdrachten Operatoren C++[](title-id) <!-- omit in toc -->

### Inhoud[](toc-id) <!-- omit in toc -->
- [Opdracht OO2.1 Katten](#opdracht-oo21-katten)


*Deze opdracht kan nog veranderen!*
### Opdracht OO2.1 Katten
**Lees** onderstaande code met de class *cat* en de `main` functie die deze class gebruikt. Probeer de code te begrijpen, zonder deze uit te voeren.
 
- Wat zijn de waarden van de attributen `*pianocat*, *ceilingcat* en *happycat* na het uitvoeren van de code?

```cpp
#include "cat.hpp"

int main(int argc, char** argv) {
  cat pianocat(230, 10, 6, 1);
  cat ceilingcat;
  cat happycat = pianocat + ceilingcat;
  pianocat *= ceilingcat;
}
```
*main.cpp*


```cpp
#ifndef CAT_HPP
#define CAT_HPP

#include <algorithm> // std::min
#include <cstdint> // uint8_t

class cat {
private:
  int n_lives;
  // color of the cat:
  uint8_t red;
  uint8_t green;
  uint8_t blue;
public:
  cat(uint8_t red, uint8_t green, uint8_t blue, int n_lives = 9) :
      n_lives(n_lives), red(red), green(green), blue(blue) {
  }
  cat() :
      n_lives(9), red(7), green(4), blue(5) {
  }
  cat operator+(const cat& rhs) const {
      return cat( (red + rhs.red) / 2, 
                  (green + rhs.green) / 2,
                  (blue + rhs.blue) / 2, 
                  n_lives + rhs.n_lives);
  }
cat& operator*=(const cat& rhs) {
      red = std::min(red * rhs.red , 255);
      green = std::min(green * rhs.green, 255);
      blue = std::min(blue * rhs.blue , 255);
      n_lives *= rhs.n_lives;
      return *this;
  }
};
#endif // CAT_HPP
```
*cat.hpp*