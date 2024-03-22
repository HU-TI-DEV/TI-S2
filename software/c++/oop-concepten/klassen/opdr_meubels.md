# Opdrachten Classes C++[](title-id)

### Inhoud[](toc-id)
- [Opdrachten Classes C++](#opdrachten-classes-c)
    - [Inhoud](#inhoud)
    - [Opdracht OO1.4A Meubels code](#opdracht-oo14a-meubels-code)
    - [Opdracht OO1.4B Meubels klassendiagram](#opdracht-oo14b-meubels-klassendiagram)


### Opdracht OO1.4A Meubels code

1. Maak een project aan met de klassen: `stool`, `table` en `furniture`. 
   - Stool heeft als member variabelen: *n_legs* en *n_seats*. 
   - Table heeft als member variabelen: *n_legs*, *length* en *width*. 
   - De constructors krijgen de aantallen mee en slaan die op. 
   - De member variabelen zijn allemaal private.

2. Furniture bestaat uit 4 variabelen van het type *stool* en en 1 variabele van het type *table*. 
   - De constructor van Furniture initialiseert de meubelen met redelijke waarden. 
   - De member variabelen van Furniture zijn ook private.
  
3. Furniture heeft de methode *makeMoreHipster()*.
   - Deze functie haalt van alle 4 de stoelen één poot af en geeft de tafel deze 4 poten. 
   - Schrijf deze functie en de benodigde functies bij *stool* en *table*.
  
4. Schrijf de *main* functie. Deze 
   - maakt een *Furniture* aan, 
   - print zijn eigenschappen, 
   - roept zijn *makeMoreHipster()* aan en 
   - print weer de eigenschappen. 
   
   Om dit te kunnen doen moet je print functies toevoegen aan alle klassen.

   ### Opdracht OO1.4B Meubels klassendiagram
5. Teken een **UML-diagram** met *stool*, *table* en *furniture*.