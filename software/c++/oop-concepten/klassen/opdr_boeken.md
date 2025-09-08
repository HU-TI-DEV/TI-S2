# Opdrachten Classes C++[](title-id) <!-- omit in toc -->

### Inhoud[](toc-id) <!-- omit in toc -->
- [Opdracht OO1.2 Boeken](#opdracht-oo12-boeken)
- [Opdracht OO1.3 Boeken Main](#opdracht-oo13-boeken-main)


### Opdracht OO1.2 Boeken
Onderstaand zie je de code van de `class` book. De code is verdeeld over een .hpp bestand en een .cpp bestand. 

Lees de code en beantwoord de volgende vragen:
- 1 Wat doet de constructor van de klasse *book*?
- 2 Hoe noemen we de tekst tussen de: (dubbelepunt) en de \{ (krulhaak) bij de constructor?
- 3 Welke functies van de klasse *book* zijn van buitenaf toegankelijk?
- 4 Waarom denk je dat de schrijver van deze code ervoor heeft gekozen sommige functies private te maken?
- 5 Waarom staat er in de .cpp voor elke functie “`book::`”?

```c++
#ifndef BOOK_HPP
#define BOOK_HPP

#include <iostream>

class book {
private:
  std::string text;
  std::string author;
  std::string title;
  void print_text();
  void print_author();
  void print_title();
public:
  book(const std::string& text, 
    const std::string& author,
    const std::string& title) :
    text(text), author(author), title(title) {
   }
  void print();
 };

#endif // BOOK_HPP
```
*book.hpp*

```c++
#include <iostream>
#include "book.hpp"

void book::print() {
  print_title();
  print_author();
  print_text();
}
void book::print_text() {
  std::cout << text << "\n";
}
void book::print_title() {
  std::cout << title << "\n";
}
void book::print_author() {
  std::cout << author << "\n";
}
```
*book.cpp*

### Opdracht OO1.3 Boeken Main
Maak een project aan met:
- een `book.cpp`, `book.hpp` en een `main.cpp`

waarin de main functie 
- een book aanmaakt en deze print.

