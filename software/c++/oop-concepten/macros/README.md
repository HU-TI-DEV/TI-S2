# Macro’s [](title-id) <!-- omit in toc -->

### Inhoud[](toc-id) <!-- omit in toc -->
- [Macro’s](#macros)
  - [Best practices Macro's](#best-practices-macros)


### Macro’s
In C was het lang de gewoonte om vaste getallen als `#define` macro te declareren, en deze mogelijkheid bestaat ook nog in C++. Macro’s zijn echter vervelende dingen: 
- ze zijn een letterlijke (tekstuele) vervanging, 
- en houden zich niet aan de normale zichtbaarheidsregels: je kunt in een functie geen lokale macro definiëren. 

In onderstaande code gaat dit (daardoor) mis.
```cpp
#define ARRAY_SIZE 100
int array[ ARRAY_SIZE ];

void f(){ 
  #undef ARRAY_SIZE     // Hier verandert de globale ARRAY_SIZE 
  #define ARRAY_SIZE 20 // er bestaat geen lokale ARRAY_SIZE; ARRAY_SIZE wordt globaal veranderd
  char my_array[ ARRAY_SIZE ];
  . . .
}

for( unsigned int i = 0; i < ARRAY_SIZE; i++ ){ // wrong ARRAY_SIZE
    array[ i ] = 0;
}
```
*Codevoorbeeld 05-12 - Oude C stijl: gebruik van macro’s als constanten*

#### Best practices Macro's
Om het wat afwijkende karakter van macro’s aan te geven is het een gewoonte macro namen in *HOOFDLETTERS* te schrijven.
In C++ wordt in zo’n geval een `const declaratie` gebruikt: een variabele die bij zijn declaratie een waarde krijgt, die daarna niet meer veranderd kan worden. Zo’n const variabele houdt zich wel aan de zichtbaarheidsregels, net als iedere andere variabele.
*N.B. C kent tegenwoordig ook const, maar het gebruik van #define voor dit doel is nooit helemaal verdwenen.*

```cpp
const unsigned int array_size = 1000; 

int array[ array_size ];

void f(){
  const int array_size = 20;
  char my_array[ array_size ];
  . . .
}

for( unsigned int i = 0; i < array_size; i++ ){
  array[ i ] = 0;
}
```
*Codevoorbeeld 05-13 - C++ stijl: gebruik const voor constante waarden*