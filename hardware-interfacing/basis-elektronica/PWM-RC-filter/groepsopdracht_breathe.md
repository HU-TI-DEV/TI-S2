### Teamopdracht: Breathe (ademhalingseffect)

#### Beschrijving
Veel elektronica onderdelen hebben een LED om bijvoorbeeld de status aan te geven. In het begin waren deze vaak van rood licht. Weet je waarom?
Tegenwoordig hebben veel apparaten een 'Breathe LED animatie' (ademhalingseffect) om bijvoorbeeld de status van het opladen aan te geven. PWM is uitermate geschikt om dergelijke aansturing te maken. Maak met behulp van een RGB led een 'breath' applicatie met je team. Een RGB LED heeft 3 LEDs in één verpakking. Het lange pootje is de kathode (voor de zekerheid kijk je natuurlijk even in de datasheet). Sluit voor alle LEDs een voorschakelweerstaand aan!

### Breathe template

```cpp
// Practicum: PWM Breathe LED Animatie
// Hardware: RGB LED met gemeenschappelijke kathode (4 pin LED)
// Common kathode is de langste pin! Vergeet de weerstandjes niet.
// Let op! Er bestaan ook RGB LEDs met een common anode!

// Pins voor RGB LED
const int RED_PIN = 9;
const int GREEN_PIN = 10;
const int BLUE_PIN = 11;

class BreatheLED {
public:
    BreatheLED(int redPin, int greenPin, int bluePin);
    void begin();
    void update(); // PWM-aanpassing voor de ademhalingseffect

private:
    int _redPin, _greenPin, _bluePin;
    float _brightness;
    int _direction;
};

BreatheLED::BreatheLED(int redPin, int greenPin, int bluePin)
    : _redPin(redPin), _greenPin(greenPin), _bluePin(bluePin), _brightness(0), _direction(1) {}

void BreatheLED::begin() {
    pinMode(_redPin, OUTPUT);
    pinMode(_greenPin, OUTPUT);
    pinMode(_bluePin, OUTPUT);
}

void BreatheLED::update() {
    //implementeer deze functie
}

BreatheLED led(RED_PIN, GREEN_PIN, BLUE_PIN);

void setup() {
    led.begin();
}

void loop() {
    led.update();
    delay(10); // Aanpasbare snelheid van de animatie
}

```