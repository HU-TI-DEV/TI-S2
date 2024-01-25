# Opdrachten Files input/output C++[](title-id)

### Inhoud[](toc-id)
- [Opdrachten Files input/output C++](#opdrachten-files-inputoutput-c)
    - [Inhoud](#inhoud)
    - [Opdracht 4.5 Compression](#opdracht-45-compression)


### Opdracht 4.5 Compression
Schrijf een compress-programma, dat uit een gegeven bestand een nieuwe bestand maakt, waarbij 
- van iedere regel alle **spaties en tabs** aan het begin van de regel zijn verwijderd.
- Verder zijn alle **lege regels** verwijderd (een lege regel bevat `\n` , eventueel voorafgegaan
door spaties en tabs(`\t`)). 

De compress-functie heeft de volgende definitie:
```c++
void compress(string src_filename, string dest_filename){
  ...
  ...
}
```