# Booleans [](title-id)

### Inhoud[](toc-id)

Het boolean datatype kan maar twee verschillende waardes hebben: *true* of *false*. 
In onderstaand codevoorbeeld zien we hoe we met de boolean omgaan in C++.

### bool
Met het sleutelwoord bool geven we aan dat een variabele van het datatype boolean is.

```c++
#include <iostream>
using namespace std;

int main() {
    bool b = true;
    bool c = false;
    cout << "b: " << b << "\n";
    cout << "c: " << c << "\n";
    // b: 1
    // c: 0
}
```
Codevoorbeeld Booleans