# Opdrachten Functies, basis [](title-id)

### Inhoud[](toc-id)
- [Opdrachten Functies, basis ](#opdrachten-functies-basis-)
    - [Inhoud](#inhoud)
    - [Opdracht 2.5 Tellen](#opdracht-25-tellen)
    - [Opdracht 2.10 Vector controle](#opdracht-210-vector-controle)


### Opdracht 2.5 Tellen
Schrijf een functie die berekent hoe vaak een geheel getal x in een integer-vector voorkomt. 

De functie heeft de vorm:
```c++
int count(const vector<int> & numbers, const int x) {
    ...
    ...
}
```

Een `main` functie kan deze `count`-functie aanroepen. Bijvoorbeeld:
```c++
int main(){
    vector<int> n = {37,4,9,4,9,37,3,5,0,4,1};
    int number_of_fours = count(n, 4);
    cout << "Number of fours: " << number_of_fours << "\n";
}
```
### Opdracht 2.10 Vector controle
 
Schrijf een functie, die bepaalt of een gegeven integer-vector met alleen 1’en en 0’en aan
de volgende eisen voldoet:
- het aantal enen is groter dan aan het aantal nullen;
- er mogen niet meer dan 12 nullen zijn.

Bedenk zelf wat het return type van deze functie moet zijn. Gebruik in je programma de
functie `count()` die je hebt geschreven bij opdracht 2.5.