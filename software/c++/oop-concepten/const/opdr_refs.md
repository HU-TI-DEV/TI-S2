# Opdracht Refs C++[](title-id) <!-- omit in toc -->

### Inhoud[](toc-id) <!-- omit in toc -->
- [Opdracht OO3.2 References en overerving](#opdracht-oo32-references-en-overerving)

### Opdracht OO3.2 References en overerving
Geef van de onderstaande code aan 
- of de regels met een getal in het commentaar een error opleveren of niet, 
- en waarom (niet).


```c++
class vehicle {
  ...
};

class car : public vehicle {
  ...
};

class train : public vehicle {
  ...
};

class intercity : public train {
  ...
};

void travel(vehicle& v);
void ovchipkaart(train& t);
void file(car& c);
car batmobiel;
intercity utr_amst;
train ICE;

file(batmobiel);              // 1
ovchipkaart(utr_amst);        // 2
file(ICE)                     // 3
ovchipkaart(batmobiel)        // 4
travel(utr_amst)              // 5
travel(batmobiel)             // 6
intercity& ref7 = utr_amst;   // 7
car& ref8 = utr_amst;         // 8
train& ref9 = utr_amst;       // 9
train& ref10 = batmobiel;     // 10
intercity& ref11 = batmobiel; // 11
intercity& ref12 = ICE;       // 12
```
*Overerving, parameters en references*