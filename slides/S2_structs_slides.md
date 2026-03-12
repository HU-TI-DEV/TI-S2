
# C++ Structs — Slides

**TI-S2 • Software (C++)**  
Gera Pronk

Bronnen:
- [structs](https://github.com/HU-TI-DEV/TI-S2/blob/main/programma/lesprogramma/programma-cpp-structs.md)
- Content laten mixen tot ruwe slides: CoPilot

---

# 🧩 Introductie
- Structs: je eigen datatypes bouwen

---

# 🏗️ C++ Structs — Wat is een struct?
- Een struct groepeert meerdere variabelen tot één logisch geheel
- Je kunt complexere datatypen maken
- Een struct is vergelijkbaar met een Python dataclass
- Voor ons is het ook de voorbereiding op het werken met klassen

---

Voor de Python liefhebbers - let niet op grammatica en spelling 
| Eigenschap              | C++ struct                           | Python class                         | Python dataclass                               | Python namedtuple                       |
|-------------------------|---------------------------------------|---------------------------------------|------------------------------------------------|-------------------------------------------|
| Doel                    | Groeperen van variabelen tot datatype | Flexibel, zelf gedefinieerd datatype  | Struct-achtig datatype met auto-gegenereerde functies | Lichtgewicht, immutable data-container |
| Standaard mutability    | Mutable                               | Mutable                               | Mutable (optioneel immutable met `frozen=True`) | **Immutable**                           |
| Syntax boilerplate      | Laag                                  | Hoog (`__init__` zelf schrijven)       | **Laag** (auto `__init__`, `__repr__`, etc.)    | Zeer laag                                 |
| Field definitie         | Binnen de struct                     | In `__init__` of class body           | Class body met type hints                      | Lijst van veldnamen                       |
| Type hints / checking   | Compile time                          | Optioneel, geen compile time check    | Ideaal voor type hints                         | Mogelijk maar beperkt                     |
| Gedrag als value type   | Kopie bij toewijzing                  | Reference type                        | Reference type                                 | Value achtig (immutable + comparable)     |
| Comparison              | Zelf implementeren                    | Zelf implementeren                    | Automatisch (`__eq__`)                         | Automatisch                               |
| Use case                | Compact modelleren van data           | Objecten met veel gedrag              | Struct-achtige objecten zonder boilerplate     | Kleine, read‑only records                 |
| Meest vergelijkbaar met C++ struct | -                          | Lijkt erop maar meer OOP-achtig       | **Beste Python‑equivalent**                    | Alternatief maar immutable                |
---

### Voorbeeld van een struct voor het uitlezen van een sensor

```cpp
struct SensorData {
    int temperature;
    float humidity;
    bool valid;
};
```
## struct - members
temperature, humidity en valid worden *members* genoemd
---

# 📦 Structs gebruiken
```cpp
SensorData s1;
s1.temperature = 22;
s1.humidity = 55.2;
s1.valid = true;
// of 
SensorData s2 = {22, 55.2, true};
// of
struct SensorData s3 = {.temperature = 22, .humidity = 55.2, .valid = true}
```
---

### De volgorde bij initialisatie is belangrijk
Probeer de volgende code uit:
```cpp
SensorData s4 = {55.2, true, 22};
```
Wat valt je op?
---

Zie ook:
```cpp
#include <iostream>
#include <bitset>
using namespace std;

struct SensorData{
    int temperature;
    float humidity;
    bool valid;
}; // ; !
int main(){
    SensorData s2 = {22, 55.2, true};
    cout << "sensordata s2 is: " ;
    cout << s2.temperature << ", " << s2.humidity << ", " << s2.valid << "\n";
    
    struct SensorData s3 = {.temperature = 22, .humidity = 55.2, .valid = true};
    cout << "sensordata s3 is: " ;
    cout << s3.temperature << ", " << s3.humidity << ", " << s3.valid << "\n";
    
    /* What happens beneath?
    SensorData s4 = {55.2, true, 22};
    cout << "sensordata s4 is: ";
    cout << s4.temperature << ", " << s4.humidity << ", " << s4.valid;
    */
}
```

---

# 🔄 Structs doorgeven
```cpp
void update(SensorData& d) {
    d.valid = true;
}
```

---

# 🧪 Oefening Structs

Maak een struct `Student` met:
- string name
- int age
- float grade

Schrijf een functie die de grade met +0.5 verhoogt.
---

# 📝 Samenvatting
- Structs → logische datatypes
- 