# Functienamen[](title-id) <!-- omit in toc -->

### Inhoud[](toc-id) <!-- omit in toc -->
- [Functienamen en overloading](#functienamen-en-overloading)

## Functienamen en overloading
Functies mogen dezelfde naam hebben, maar enkel als de compiler op basis van de datatypes
van de parameters kan bepalen welke functie wordt bedoeld. Dit heet *function overloading*.

In codevoorbeeld 8.5 zien we 4 functies met dezelfde naam.

```cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Adds 2 to x
void addTwo(int & x){
    x += 2;
}

// Adds 2 to every element of v
void addTwo(vector<int> & v){
    for(unsigned int i=0; i<v.size(); i++){
    v[i] += 2;
    }
}

// adds two variables together
int addTwo(const int & x,const int & y){
    return x + y;
}

// adds a 2 at the end of s. Returns it as a new string.
string addTwo(const string & s){
    return s + '2';
}

int main(){
    int z = 3;
    int p = 8;
    string text = "Prachtige woorden";
    vector<int> n = {5,2,7,3,9};

    addTwo(z);
    int result = addTwo(z,p);
    text = addTwo(text);
    addTwo(n);

    cout << "z: " << z << "\n";
    cout << "result: " << result << "\n";
    cout << "text: " << text << "\n";
    cout << "n: " << n[0];
    for(unsigned int i=1; i<n.size(); i++){
        cout << ", " << n[i];
    }
    cout << "\n";

    // output:
    // z: 5
    // result: 13
    // text: Prachtige woorden2
    // n: 7, 4, 9, 5, 11
}
```
*Codevoorbeeld 8.4 Functienaam addTwo*