![logo](.svg) [](logo-id)

# Integer[](title-id) <!-- omit in toc -->

### Inhoud[](toc-id) <!-- omit in toc -->

- [Integer (int)](#integer-int)
- [Gebroken getallen](#gebroken-getallen)
- [Referenties](#referenties)

---

**v0.1.0 [](version-id)** Start document voor C++ data-types door HU IICT[](author-id).

---

## Integer (int)

In het datatype integer kunnen we gehele getallen opslaan. De code in onderstaande codevoorbeelden laten het **declareren**, **initialiseren** en enkele **bewerkingen** zien voor integer variabelen.

In onderstaand codevoorbeeld zie je hoe de variabele number een type krijgt (declaratie) en een waarde krijgt (initialisatie).

```cpp
#include <iostream>
using namespace std;
int main(){
   int number = 6; // number krijgt hier type int en waarde 6
   number = number + 1;
   number = number * 2;
   cout << "number: " << number << "\n";
   // number: 14
   int x = 8 - 4; // x krijgt hier type int en waarde 8-4
   cout << "x: " << x << "\n";
   // x: 4
}
```
*Codevoorbeeld 3.1 Integers*

```cpp
#include <iostream>
using namespace std;
int main(){
   int y = 4.9;
   cout << "y: " << y << "\n";
   // y: 4

   z = 21;
   int result1 = z / 3;
   int result2 = z / 6;
   cout << "result1: " << result1 << "\n";
   cout << "result2: " << result2 << "\n";
   // result1: 7
   // result2: 3
}
```
*Codevoorbeeld 3.2 Integers en gebroken getallen*

## Gebroken getallen
Kijk naar codevoorbeeld 3.2:
Als de variabele y wordt afgedrukt zien we dat het de waarde 4 heeft. Dit terwijl y wordt geïnitialiseerd met de waarde 4,9. Dit komt omdat y van het type integer is en dus enkel gehele getallen kan bevatten. Als oplossing gooit C++ alles achter de komma weg en stopt enkel de waarde 4 in y.

Dit zelfde zien we ook gebeuren met de variabele result2. Van z=6 verwachten we dat de uitkomst 3,5 is, maar result2 is van het type integer. Dus alles na de komma wordt genegeerd en result2 krijgt de waarde 3. Als we willen dat result2 wel gebroken
getallen kan bevatten, dan moeten we result2 een ander type maken (bijvoorbeeld een [float](../float/README.md)).

## Referenties

- Integer (<https://en.wikipedia.org/wiki/Integer>)
