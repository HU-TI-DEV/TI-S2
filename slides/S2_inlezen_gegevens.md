---
title: "C++ Inlezen gegevens - slides"
course: "TI-S2 • Software (C++)"
author: Gera Pronk
sources:
  - text: "inlezen gegevens"
    url: "https://github.com/HU-TI-DEV/TI-S2/slides/S2_inlezen_gegevens.md"
  - "Content laten mixen tot ruwe slides: CoPilot"
---
# Inlezen van gegevens in C++

**TI-S2 • Software (C++)**  
Gera Pronk

- Waarom input?
- `cin` gebruiken
- Spaties & meerdere variabelen
- Hele regels lezen met `getline`
- Veelgemaakte valkuilen & tips  
(Bron: HU TI-S2 “Inlezen van gegevens”) 
(Bron: CoPilot)
---

## Waarom input?

Programma’s worden nuttig zodra ze **gebruikersinvoer** verwerken: 
toetsenbord → variabelen → berekening/actie.  
We focussen op **console-invoer** in C++.

---

## `cin` in één slide

- Uitvoer: `cout << ...`
- Invoer: `cin >> variable;`
- Denk aan de pijltjesrichting: toetsenbord ⇒ variabele (`>>`)

**Voorbeeld:**

```cpp
#include <iostream>
using namespace std;

int main() {
    int n_tables;
    cout << "Enter number of tables in the room: ";
    cin >> n_tables;
    int total_legs = n_tables * 4;
    cout << "There are " << total_legs << " table legs.";
}
```

---

## Vereiste header

Gebruik `#include <iostream>` voor zowel `cout` als `cin`.  
Soms zie je ook `#include <string>` wanneer je met strings werkt.

---

## Spaties scheiden invoer

`cin` splitst automatisch op **spaties** en **enters**. 
Handig om **meerdere waarden** achter elkaar te lezen.

**Voorbeeld:**

```cpp
#include <iostream>
using namespace std;

int main() {
    float price;
    int quantity;
    cout << "Enter price and quantity: ";
    cin >> price >> quantity;
    float total_price = price * quantity;
    cout << "Total price: " << total_price << "";
}
```
---

## Oefening
- Wat gebeurt er als je bovenstaande code runt en 5,3 invoert?
- Idem voor 5.36?
- Is er verschil tussen het invoeren van: 7 3,78 en 7 3.78?

---

## Wanneer `cin` onhandig wordt

- Bij **zinnen** of velden met **spaties** (namen, titels, adressen).
- `cin >> s` stopt bij eerste spatie → rest gaat verloren.

Oplossing: **`getline`** voor volledige regels.

---

## `getline(cin, stringVar)`

**Voorbeeld:**

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string sentence;
    cout << "Enter a sentence:";
    getline(cin, sentence);

    int count = 0;
    for (unsigned int i = 0; i < sentence.size(); i++) {
        if (sentence[i] == ' ') { count++; }
    }
    cout << "The sentence contains " << count << " spaces";
}
```

---

## Belangrijke valkuil: `cin` + `getline`

- Na `cin >> x;` blijft er vaak een **newline (``)** in de buffer.
- `getline` leest dan **een lege regel**.

**Oplossing:**
Negeer alle karakters tot de volgende newline.
Specifieker: negeer het maximum aantal mogelijke karakters tot de newline.
(We gaan nu niet dieper in op `numeric_limits`.)
```cpp
cin.ignore(numeric_limits<streamsize>::max(), '\n');
```
Of: 
Negeer álle karakters in de stream.
```cpp
cin.ignore(numeric_limits<std::streamsize>::max());
```
---

## cin.fail() en cin.clear()
- Je kunt na een inleesactie `cin.fail()` gebruiken om te controleren of de invoer 'goed' was.
- Als een inleesactie verkeerd is gegaan, wordt er een foutstatus gezet.
- Je kunt met `cin.clear()` de foutstatus ongedaan maken.

---

## Robuust inlezen: validatie

```cpp
#include <iostream>
#include <limits>
using namespace std;

int main() {
    int n;
    cout << "Enter an integer: ";
    while (!(cin >> n)) { 
        cout << "Not an integer. Try again: ";
        cin.clear();

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << "You entered: " << n << "";
}
```

---

## Snelle checklist

- `#include <iostream>` (en `<string>` bij strings)
- Tokens → `cin >> a >> b;`  
- Hele regel → `getline(cin, s);`  
- Na `cin >>` vóór `getline` → `cin.ignore(...)`
- Valideer invoer met `cin.fail()`