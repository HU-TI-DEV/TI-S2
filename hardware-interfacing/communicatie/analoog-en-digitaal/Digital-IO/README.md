![logo](../img/Kennline_NTC.png) [](logo-id)

# Digital I/O [](title-id)

### Inhoud[](toc-id)

- [Digital I/O](#digital-io)
  - [Inhoud](#inhoud)
  - [Basis principe](#basis-principe)
  - [De schakeling](#de-schakeling)
  - [Arduino voorbeeld code](#arduino-voorbeeld-code)
  - [Referenties](#referenties)

---

### Basis principe

Als een deur schakelaar sluit, of als we een lampje willen aan/uitzetten, dan hebben we met digitale signalen te maken.
Deze zijn of 'aan' of 'uit'. (Tegenover digitale kunnen analoge signalen ook tussenstanden innemen.)

### Button

Als je een button (knop) indrukt dan wordt gewoon een contact gesloten.
Dit kunnen we met een Digital-I/O Pin meten en wandelen in een 0 of 1.

### LED

Een LED (Light Emitting Diode) kunnen we met een digitaal signaal aan- of uitzetten. Daarbij moeten we opletten dat er niet teveel stroom door de LED gaat. Als het goed is weten we dit principe nog van de Orientatie op Technische Informatica.

### De schakeling

We tonen in dit voorbeeld een LED en een Button.

![LED-Button breadboard schakeling](LED-Button_bb.png)

## Arduino voorbeeld code

De voorbeeld code leest de toestand van de Button. Zolang deze is ingedrukt laat de code de LED knipperen.

```arduino
// LED-Button.ino - Digital Input/Output example - 2024-02-12-hp
// Tested on Arduino Uno
// [+5V]---[=1kOhm=]---[LED]---[D0]
// [GND]---[Button]---[D1]

const int delaytime_ms = 500;  // delay 1000ms = 1s, 500ms = 0.5s
const int pinLED = 2;         // Pin 2 - Digital Output
const int pinButton = 3;      // Pin 3 - Digital Input

int stateLED = 1;  // start state: LED off

void setup() {
  pinMode(pinButton, INPUT_PULLUP);
  pinMode(pinLED, OUTPUT);
  digitalWrite(pinLED, stateLED);  // LED off
}

void loop() {
  if (digitalRead(pinButton) == LOW) {
    stateLED = 1 - stateLED;         // reverse LED status
    digitalWrite(pinLED, stateLED);  // LED off
    delay(delaytime_ms);
  }
}

// EOF
```
[Arduino bestand](LED-Button/LED-Button.ino) 

## Referenties

LED Datasheet

- [5mm-LED-Datasheet](5mm-LED-Datasheet.pdf)