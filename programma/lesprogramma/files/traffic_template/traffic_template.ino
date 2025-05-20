enum State {
  GREEN,
  YELLOW_COMING_FROM_GREEN
};

class TrafficLight {
private:
  const int greenPin = 11;
  const int yellowPin = 12;
  const int buttonA = 2;
  State currentState;
  unsigned long lastUpdate;

  void setGreen() {
    digitalWrite(greenPin, LOW);
    digitalWrite(yellowPin, HIGH);
  }

  void setYellow() {
    digitalWrite(yellowPin, LOW);
    digitalWrite(greenPin, HIGH);
  }

public:
  TrafficLight()
    : currentState(GREEN), lastUpdate(0) {
    pinMode(greenPin, OUTPUT);
    pinMode(yellowPin, OUTPUT);
    pinMode(buttonA,INPUT_PULLUP);
    setGreen();
  }

  void update(unsigned long now) {
    bool buttonAPressed = !digitalRead(buttonA);
    switch (currentState) {
      case GREEN:
        if (buttonAPressed) {
          currentState = YELLOW_COMING_FROM_GREEN;
          setYellow();
          lastUpdate = now;
        }
        break;
      case YELLOW_COMING_FROM_GREEN:
        if (now - lastUpdate >= 2000) {
          currentState = GREEN;
          setGreen();
        }
        break;
    }
  }
};

TrafficLight trafficLight;

void setup() {
}

void loop() {
  trafficLight.update(millis());
}
