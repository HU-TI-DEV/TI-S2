![logo](.svg) [](logo-id)

# Integer[](title-id)

### Inhoud[](toc-id)

- [Integer](#integer)
    - [Inhoud](#inhoud)
  - [Integer (int)](#integer-int)
  - [Referenties](#referenties)

---

**v0.1.0 [](version-id)** Start document voor C++ data-types door HU IICT[](author-id).

---

## Integer (int)

In het datatype integer kunnen we gehele getallen opslaan. De code in onderstaande codevoorbeelden laten het **declareren**, **initialiseren** en enkele **bewerkingen** zien voor integer variabelen.

In onderstaand codevoorbeeld zie je hoe de variabele number een type krijgt (declaratie) en een waarde krijgt (initialisatie).

```c++
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

## Referenties

- Integer (<https://en.wikipedia.org/wiki/Integer>)