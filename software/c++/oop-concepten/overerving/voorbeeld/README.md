
# Cpp uitwerking overerving[](title-id) <!-- omit in toc -->

### Inhoud[](toc-id) <!-- omit in toc -->
- [Voorbeeld overerving](#voorbeeld-overerving)

Zie ook: [Overerving](./README.md)

# Voorbeeld overerving

Omdat het lesmateriaal over [overerving](../README.md) niet een volledig uitgewerkt voorbeeld heeft is dit een demonstratie [zonder overerving](./overerving1.cpp) en een klasse [met overerving](./overerving2.cpp). Het is een demonstratie hoe je een klasse van verschillende elektronica componenten kan maken.

Heb je dit goed in de vingers maak dan de opdracht [Kas Systeem](../opdr_kassysteem.md) *ter oefening en vermaak*.

VS Code formatter settings:
```bash 
C_Cpp: Clang_format_fallback Style

{ BasedOnStyle: LLVM, UseTab: Never, IndentWidth: 4, TabWidth: 4, BreakBeforeBraces: Stroustrup, AllowShortIfStatementsOnASingleLine: false, IndentCaseLabels: false, ColumnLimit: 0, AccessModifierOffset: -4, NamespaceIndentation: All, FixNamespaceComments: false }
```

Test log (MacOS):
```bash
hp@hagens-mbp test % g++ -o o1 overerving1.cpp 
hp@hagens-mbp test % g++ -o o2 overerving2.cpp
hp@hagens-mbp test % ./o1
Overerving: Electronika
LED        with pincount 2 and color yellow
Transistor with pincount 3 and  type BC308C
hp@hagens-mbp test % ./o2
Overerving: Electronika
LED        with color yellow
component  with pincount 2 and typecode 1
Transistor with  type BC308C
component  with pincount 3 and typecode 2
hp@hagens-mbp test % 
```