# Bits[](title-id) <!-- omit in toc -->

## Inhoud[](toc-id) <!-- omit in toc -->
- [Bitoperatoren](#bitoperatoren)
  - [Bitsgewijs ‘and’](#bitsgewijs-and)
  - [Bitsgewijs ‘or’](#bitsgewijs-or)
  - [Bitsgewijs ‘xor’ (exclusive or)](#bitsgewijs-xor-exclusive-or)
  - [Bitsgewijs Inversie (‘not’)](#bitsgewijs-inversie-not)
  - [Bit shiften](#bit-shiften)
  - [Vrijgekomen plaatsen](#vrijgekomen-plaatsen)
- [Bit statements](#bit-statements)
  - [Bit setten](#bit-setten)
  - [Bit resetten](#bit-resetten)
  - [Bit inverteren](#bit-inverteren)
  - [Bit ophalen](#bit-ophalen)


Gegevens worden in het geheugen opslagen als bitjes. In C++ is het mogelijk om
op bitniveau te opereren door middel van **bitoperatoren**. Het op bitniveau opereren
hebben we als Technische Informatici nodig om hardware aan te sturen en uit te lezen. 

In dit hoofdstuk behandelen we bitoperatoren en bit statements (veelgebruikte combinaties van bitoperatoren).
In de voorbeelden in dit hoofdstuk zien we dat de variabelen van het datatype `uint8_t` zijn. Dit is omdat het aantal bitjes dat wordt gebruikt voor de meeste datatypes wisselt tussen de verschillende implementaties van C++. Voor `uint8_t` geldt wel dat het altijd uit slechts één byte bestaat<sup>[1](#uint8)</sup>.

De bitoperatoren werken ook op andere datatypes,
maar het kan zijn dat dezelfde code, afhankelijk van de compiler, een ander resultaat geeft!
Verder gebruiken we de `library bitset` en het datatype bitset. Deze gebruiken we om de bit-waarde makkelijk te printen<sup>[2](#bitprint)</sup>.

### bitstring, byte
Voordat we naar de bitoperatoren gaan is het nog belangrijk om te realiseren hoe we over reeksen van bitjes praten. Een reeks bitjes noemen we een *bitstring*. Een
bitstring van 8 bitjes noemen we een *byte*. 

### tellen
De bitjes van een bitstring nummeren van
rechts naar links waarbij we beginnen met tellen bij 0. 
Voorbeeld: als we de bitstring
1101 hebben, dan is het 0de bitje 1, het 1e bitje 0, het 2e bitje 1 en het 3e bitje 1.

<a name="uint8">1</a>: *uint8_t is een unsigned integer van 8 bits. In C++ hebben we ook de datatypes uint16_t, uint32_t en uint64_t. Dit zijn unsigned integers met respectievelijk 16, 32 en 64 bits. Daarnaast hebben we ook int8_t, int16_t, int32_t en int64_t. Dit zijn signed integers met respectievelijk 8, 16, 32 en 64 bits. Deze
grotere datatypes gebruiken we niet omdat dit de voorbeelden onduidelijker maakt.*

<a name="bitprint">2</a>: *De library bitset heeft ook andere handige functionaliteiten. Deze mogen tijdens deze cursus echter niet worden gebruikt. Zonder deze functionaliteiten kunnen we ons beter focussen op het begrijpen en toepassen van de bitoperatoren.*

## Bitoperatoren
We hebben verschillende operatoren die we kunnen gebruiken om bitsets te manipuleren.
In deze sectie behandelen we bitsgewijs ‘and’, bitsgewijs ‘or’, bitsgewijs
‘xor’, inversie en bit shiften.

### Bitsgewijs ‘and’
Voor de bitoperatie ‘and’ gebruiken we in C++ een enkele ampersand ( & ). 
In *codevoorbeeld 10.1* zien we het gebruik hiervan.

```cpp
#include <iostream>
#include <bitset>
using namespace std;

int main(){

  uint8_t value = 0x6b; // 01101011
  uint8_t mask = 0xf0; //  11110000
  uint8_t result = value & mask;

  cout << "value in bits: \t\t" << bitset<8>(value)<< endl;
  cout << "mask in bits: \t\t" << bitset<8>(mask)<< endl;
  cout << "and-result in bits: \t" << bitset<8>(result) << endl;

  //output:
  // value in bits: 01101011
  // mask in bits:  11110000
  // and-result:    01100000
}
```
*Codevoorbeeld 10.1 - Bit and*

### Bitsgewijs ‘or’
Voor de bitoperatie ‘or’ gebruiken we in C++ een enkele verticale balk ( | ). In *codevoorbeeld 10.2* zien we het gebruik hiervan.

```cpp
#include <iostream>
#include <bitset>
using namespace std;

int main(){
  uint8_t value = 0x6b; // 01101011
  uint8_t mask = 0xf0; //  11110000
  uint8_t result = value | mask;

  cout << "value in bits: \t\t" << bitset<8>(value) << endl;
  cout << "mask in bits: \t\t" << bitset<8>(mask) << endl;
  cout << "and-result in bits: \t" << bitset<8>(result) << endl;

  //output:
  // value in bits: 01101011
  // mask in bits:  11110000
  // or-result:     11111011
}
```
*Codevoorbeeld 10.2 - Bit or*

### Bitsgewijs ‘xor’ (exclusive or)
Voor de bitoperatie ‘exor’ gebruiken we in C++ een enkele dakje ( ˆ ). In *codevoorbeeld 10.3* zien we het gebruik hiervan.

```cpp
#include <iostream>
#include <bitset>
using namespace std;

int main(){
  uint8_t value = 0x6b; // 01101011
  uint8_t mask = 0xf0; //  11110000
  uint8_t result = value ^ mask;

  cout << "value in bits: \t\t" << bitset<8>(value) << endl;
  cout << "mask in bits: \t\t" << bitset<8>(mask) << endl;
  cout << "exor-result in bits: \t" << bitset<8>(result) << endl;

  //output:
  // value in bits: 01101011
  // mask in bits:  11110000
  // exor-result:   10011011
}
```
*Codevoorbeeld 10.3 - Bit xor*

### Bitsgewijs Inversie (‘not’)
Voor de inversie van alle bits gebruiken we in C++ een enkele tilde ( ˜ ). In codevoorbeeld
10.4 zien we het gebruik hiervan.

```cpp
#include <iostream>
#include <bitset>
using namespace std;

int main(){
  uint8_t value = 0x6b; // 01101011
  uint8_t result = ~value;

  cout << "value in bits: \t\t" << bitset<8>(value) << endl;
  cout << "inverse-result in bits: " << bitset<8>(result) << endl;

  //output:
  // value in bits:  01101011
  // inverse-result: 10010100
}
```
*Codevoorbeeld 10.4 - Bit inverse*

### Bit shiften
Bit shiften is het verschuiven van alle bits naar links of naar rechts. Met << kunnen
we een bitpatroon naar links schuiven en met >> kunnen we een bitpatroon naar rechts
schuiven. 
*Let op: bij cout en cin hebben << en >> een andere betekenis.*

```cpp
#include <iostream>
#include <bitset>
using namespace std;

int main(){
  uint8_t value = 0x6b; // 01101011
  uint8_t shift_left = value << 3;
  uint8_t shift_right = value >> 3;

  cout << "value in bits: \t\t" << bitset<8>(value) << endl;
  cout << "shift-left in bits: \t" << bitset<8>(shift_left) << endl;
  cout << "shift-right in bits: \t" << bitset<8>(shift_right) << endl;

  //output:
  // value in bits: 01101011
  // shift-left:    01011000
  // shift-right:   00001101
}
```
*Codevoorbeeld 10.5 - Bit shiften*

### Vrijgekomen plaatsen
Bij het shiften naar links (<<) krijgen de vrijgekomen plaatsen de waarde 0. Welke waarden de vrijgekomen plaatsen krijgen bij het shiften naar rechts (>>) hangt in C++ af van de compiler. 

In twee situaties weten we zeker dat de vrijgekomen plaatsen de waarde 0 krijgen:
- als de meeste linkse bit 0 is, en
- als de variabele van een unsigned datatype is.
Om te voorkomen dat we hierover moeten nadenken is het beste om bij het werken met bitoperatoren gebruik te maken van unsigned datatypes (zoals `uint8_t`).

## Bit statements
Bepaalde combinaties van bitoperatoren zul je vaker tegenkomen en gebruiken. In deze sectie behandelen we er vier: **bit setten**, **bit resetten**, **bit inverteren** en **bit ophalen**.

### Bit setten
In *codevoorbeeld 10.6* zien we drie manieren hoe we één enkele bit (het tweede bitje) in een bitstring kunnen setten. Een bit setten is de waarde van een bit op 1 zetten
ongeacht de huidige waarde.

```cpp
#include <iostream>
#include <bitset>
using namespace std;

int main(){
  uint8_t value = 0x6b; // 01101011
  uint8_t x = value | (1 << 2);
  uint8_t y = value | 0x04; // (1 << 2) is gelijk aan 0x04)
  uint8_t z = 0x6b; // 01101011
  z |= (1 << 2);

  cout << "value in bits: \t" << bitset<8>(value) << endl;
  cout << "x in bits: \t" << bitset<8>(x) << endl;
  cout << "y in bits: \t" << bitset<8>(y) << endl;
  cout << "z in bits: \t" << bitset<8>(z) << endl;

  //output:
  // value in bits: 01101011
  // x in bits:     01101111
  // y in bits:     01101111
  // z in bits:     01101111
}
```
*Codevoorbeeld 10.6 - Bit setten*

### Bit resetten
In *codevoorbeeld 10.7* zien we drie manieren hoe we één enkele bit (het derde bitje) in een bitstring kunnen resetten. Een bit resetten is een bit op 0 zetten ongeacht de huidige waarde.

```cpp
#include <iostream>
#include <bitset>
using namespace std;

int main(){
  uint8_t value = 0x6b; // 01101011
  uint8_t x = value & ~(1 << 3);
  uint8_t y = value & 0xF7; // ~(1 << 3) is gelijk aan 0xF7)
  uint8_t z = 0x6b; // 01101011
  z &= ~(1 << 3);

  cout << "value in bits: \t" << bitset<8>(value) << endl;
  cout << "x in bits: \t" << bitset<8>(x) << endl;
  cout << "y in bits: \t" << bitset<8>(y) << endl;
  cout << "z in bits: \t" << bitset<8>(z) << endl;

  //output:
  // value in bits: 01101011
  // x in bits:     01100011
  // y in bits:     01100011
  // z in bits:     01100011
}
```
*Codevoorbeeld 10.7 - Bit resetten*

### Bit inverteren
In *codevoorbeeld 10.8* zien we drie manieren hoe we één enkele bit (het derde bitje) in een bitstring kunnen inverteren.

```cpp
#include <iostream>
#include <bitset>
using namespace std;

int main(){
  uint8_t value = 0x6b; // 01101011
  // method 1:
  uint8_t x = value ^ (1 << 3);
  // method 2:
  uint8_t y = value ^ 0x08; // (1 << 3) is gelijk aan 0x08)
  // method 3:
  uint8_t z = 0x6b; // 01101011
  z ^= (1 << 3);

  cout << "value in bits: \t" << bitset<8>(value) << endl;
  cout << "x in bits: \t" << bitset<8>(x) << endl;
  cout << "y in bits: \t" << bitset<8>(y) << endl;
  cout << "z in bits: \t" << bitset<8>(z) << endl;

  //output:
  // value in bits: 01101011
  // x in bits:     01100011
  // y in bits:     01100011
  // z in bits:     01100011
}
```
*Codevoorbeeld 10.8 - Bit inverteren*

### Bit ophalen
In *codevoorbeeld 10.9* zien we twee manieren hoe we de waarde van één enkele bit (het derde bitje) uit een bitstring kunnen ophalen en in een variabele kunnen stoppen.

```cpp
#include <iostream>
#include <bitset>
using namespace std;

int main(){
  uint8_t value = 0x6b; // 01101011
  
  // method 1:
  int x = 0;
  if(value & (1 << 3)){
  x = 1;
  }
  
  // method 2:
  int y = (value >> 3) & 1;
  cout << "value in bits: \t" << bitset<8>(value) << endl;
  cout << "x: \t" << x << endl;
  cout << "y: \t" << y << endl;
  
  //output:
  // value in bits: 01101011
  // x: 1
  // y: 1
}
```
*Codevoorbeeld 10.9 - Bit ophalen*