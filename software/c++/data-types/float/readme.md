
# Float [](title-id)

### Inhoud[](toc-id)
- [Float ](#float-)
    - [Inhoud](#inhoud)
    - [float](#float)
    - [Float](#float-1)
    - [Output](#output)
    - [Delen](#delen)


### float
Om gebroken getallen op te slaan kunnen we het datatype float gebruiken. In codevoorbeelden
3.3 en 3.4 zien we het declareren (de variabelen aanmaken)en initialiseren, 
(de variabelen een waarde geven) en het bewerken van float variabelen.

```c++
#include <iostream>
using namespace std;

int main(){
    float number = 6;
    number = number + 1;
    number = number * 2;
    cout << "number: " << number << "\n";
    // number: 14
    float y = 4.9;
    cout << "y: " << y << "\n";
    // y: 4.9
}
```
*Codevoorbeeld 3.3 Floats*

### Float
Met het sleutelwoord float geven we aan dat een variabele van het datatype float is.

### Output
We zien dat variabelen met het float datatype wel gebroken getallen kunnen bevatten.
In *codevoorbeeld 3.3* krijgt variabele y nu wel de waarde 4,9.

```c++
#include <iostream>
using namespace std;

int main(){
   int z = 14;
   float result1 = z / 2;
   float result2 = z / 5.0;
   cout << "result1: " << result1 << "\n";
   cout << "result2: " << result2 << "\n";
   // result1: 7
   // result2: 2.8
   float div1 = 100 / 8; //dividing two integers!
   float div2 = 100 / 8.0; //dividing an integer by a float
   float div3 = float(100) / 8; //dividing a float by an integer!
   float div4 = 100.0 / float(8); // dividing two floats
   cout << "div1: " << div1 << "\n";
   cout << "div2: " << div2 << "\n";
   cout << "div3: " << div3 << "\n";
   cout << "div4: " << div4 << "\n";
   // div1: 12
   // div2: 12.5
   // div3: 12.5
   // div4: 12.5
}
```
*Codevoorbeeld 3.4 Floats en delen*

### Delen

In *codevoorbeeld 3.4* zien we in variabele *div1*  een interessant resultaat: 100=8 zou
12,5 moeten opleveren, maar als we *div1* uitprinten blijkt 12 de waarde van de variabele
te zijn. Dit komt doordat zowel het getal 100 als het getal 8 een integer is. C++ berekent
daarom de integer-waarde. Dit noemen we **gehele deling**. Als één of beide getallen een
float is zal de uitkomst wel van het datatype float zijn. 

Van een integer kunnen we een
float maken door middel van de functie float(). Een andere oplossing is om van het
getal een kommagetal te maken. In *codevoorbeeld 3.4* zien deze oplossingen bij *div2* ,
*div3* en *div4*.