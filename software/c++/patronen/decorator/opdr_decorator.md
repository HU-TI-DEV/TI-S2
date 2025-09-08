# Opdrachten decorator C++[](title-id) <!-- omit in toc -->

### Inhoud[](toc-id) <!-- omit in toc -->
- [Opdrachten decorator C++](#opdrachten-decorator-c)
    - [Inhoud](#inhoud)
  - [Opdracht OO5.3 — AND decorator](#opdracht-oo53--and-decorator)
  - [Opdracht OO5.4. Links-rechts Knipperen met kitt](#opdracht-oo54-links-rechts-knipperen-met-kitt)
  - [Opdracht OO5.5. Idem met blink()](#opdracht-oo55-idem-met-blink)


## Opdracht OO5.3 — AND decorator
1. Schrijf een twee-input AND decorator voor de `pin_in` klasse. 
   - De constructor van deze decorator heeft twee `pin_in`’s als parameters. 
   - De `get()` van de decorator geeft 1 terug als de `get()`’s van beide responders pin_in’s 1 teruggeven (anders geeft hij 0 terug).
2. Demonstreer deze decorator.

## Opdracht OO5.4. Links-rechts Knipperen met kitt
Schrijf een programma dat zorgt dat de `kitt()` functie op 8 LEDs het volgende patroon laat zien:

```console
XXXX----
----XXXX
XXXX----
----XXXX
etc.
```

Doe dit
- door de 8 pin objecten tot 2 groepjes te combineren via de bestaande `all()` decorator en 
- door van die groepjes een *poort* te maken.

## Opdracht OO5.5. Idem met blink()
Schrijf een `pin_out_invert` decorator.
Bereik hetzelfde als in de vorige opgave, maar nu door `blink()` te gebruiken i.p.v. `kitt()`.

Doe dit 
- door de helft van de 8 pin objecten te decoreren met een `pin_out_invert()` 
- en dan het geheel te combineren met `all()`.