# Basis <!-- omit in toc -->

### Inhoud[](toc-id) <!-- omit in toc -->
- [Basis](#basis)
  - [Codevoorbeelden - functies](#codevoorbeelden---functies)
  - [Datatypen functies](#datatypen-functies)
  - [{ }](#-)
  - [Main](#main)
  - [Returnwaarde main](#returnwaarde-main)
  - [Zo min mogelijk code in main](#zo-min-mogelijk-code-in-main)
  - [Returnwaarde main in scripts](#returnwaarde-main-in-scripts)
  - [Void](#void)

---

## Basis

Een functie is een verzameling coderegels die we een *naam* geven. De code van de functie noemen we de *body*.

We kunnen de functie iets meegeven via *parameters* en iets terugvragen via de *returnwaarde*.

In C++ moeten we bij elke variabele het datatype aangeven. Dit geldt ook voor functies.
De datatypes van zowel de return-waarde als de parameters moeten worden gespecificeerd. 

### Codevoorbeelden - functies

In codevoorbeelden 8.1, 8.2, 8.3 en 8.4 zien we enkele C++ functies en hoe deze functies worden aangeroepen.

```cpp
#include <iostream>
#include <string>
using namespace std;

int add(int num1, int num2){
    int total = num1 + num2;
    return total;
}

float power(float base, int exponent){
    float result = base;
    for(int i=0; i<exponent-1; i++){
        result *= base;
    }
    return result;
}

int main(){
    int sum = add(3,5); // functie aanroep
    float p = power(2,4); // functie aanroep
    cout << "sum: " << sum << "\n";
    cout << "p: " << p << "\n";

    //output
    // sum: 8
    // p: 16
}
```

*Codevoorbeeld 8.1 Functies add en power met integers en floats* 

```cpp
#include <iostream>
#include <string>
using namespace std;

// functie met bool als returnwaarde
bool biggerThan5(float number){
    return number > 5;
}

// functie zonder returnwaarde
void printAnswerUltimateQuestion(){
    cout << "The Answer to the Ultimate Question is: " << 42 << "\n";
}

int main(){
    bool bt5 = biggerThan5(3);
    printAnswerUltimateQuestion();
    cout << "bt5: " << bt5 << "\n";

    //output
    // The Answer to the Ultimate Question is: 42
    // bt5: 0
}
```

*Codevoorbeeld 8.2 Functies met bool en void*

```cpp
#include <iostream>
#include <string>
using namespace std;

// functie met string als returnwaarde
string getAnimal(){
    return "Dog";
}

// functie met char als returnwaarde
char getFirstLetterAnimal(){
    string an = getAnimal();
    return an[0];
}

int main(){
    string beast = getAnimal();
    char b = getFirstLetterAnimal();
    cout << "beast: " << beast << "\n";
    cout << "b: " << b << "\n";
    //output
    // beast: Dog
    // b: D
}
```

*Codevoorbeeld 8.3 Functies met string en char*

```cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> add1(vector<int> v){
    for(unsigned int i =0; i<v.size(); i++){
        v[i] += 1;
    }
    return v;
}

void printNumbers(vector<int> n){
    for(unsigned int i=0; i<n.size(); i++){
        cout << n[i] << ", ";
    }
    cout << "\n";
}

int main(){
    vector<int> zeros(4,0); // a vector with 4 zero's.
    vector<int> ones = add1(zeros);
    printNumbers(zeros);
    printNumbers(ones);

    //output
    // 0,0,0,0,
    // 1,1,1,1,
}
```

*Codevoorbeeld 8.4 Functies met vectoren*

### Datatypen functies

Het datatype van de return-waarde zetten we voor de naam van de functie. Het datatype van een parameter zetten we voor de naam van de parameter.

### { }

Net als met if/else-statements en loops geven we met krulhaken ({ en }) aan wat de body is van een functie.

### Main

We zien in de codevoorbeelden dat main() ook een functie is met als return type int.
De functie main() is speciaal, omdat het de functie is die door het programma altijd als
eerste wordt aangeroepen. 

### Returnwaarde main

De main()-functie geeft meestal als return-waarde 0 terug. Hiermee wordt aangegeven dat alles succesvol is uitgevoerd. 'return 0;' mag bij main() worden weggelaten. Als de return-opdracht ontbreekt wordt door de compiler 'return 0;' toegevoegd.

### Zo min mogelijk code in main

Het is gebruikelijk en het wordt gezien als goede programmeerstijl om zo min mogelijk code in de main()-functie te zetten. In de body van de main()-functie worden voornamelijk andere functies aangeroepen die het echte werk doen. Hiermee geeft de main()-functie een overzicht van je programma

### Returnwaarde main in scripts

Als het programma wordt gebruikt in een script (.sh[linux] of .bat[Windows]) dan kan het programma het script informeren of het programma goed is verlopen. Maar je kunt ook allerlei andere returnwaardes definiëren (bijvoorbeeld als je geen connectie kunt krijgen met het internet).

### Void

Een functie met return-type *void* heeft geen return-waarde.
