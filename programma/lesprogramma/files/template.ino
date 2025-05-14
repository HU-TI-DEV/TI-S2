enum State {
  GREEN,
  YELLOW_TO_RED
};

class TrafficLight {
private:
  const int greenPin = 11;
  const int yellowPin = 12;
  const int buttonA = 2;
  State currentState;
  unsigned long lastUpdate;

public:
  TrafficLight() {
    pinMode(greenPin, OUTPUT);
    pinMode(yellowPin, OUTPUT);
    currentState = GREEN;
    lastUpdate = 0;
    // Start met groen licht
    digitalWrite(greenPin, HIGH);
    digitalWrite(yellowPin, LOW);
  }

  void update(unsigned long now) {
    bool buttonAPressed = !digitalRead(buttonA);
    switch (currentState) {
      case GREEN:
        if (buttonAPressed) {
          currentState = YELLOW_TO_RED;
          digitalWrite(greenPin, LOW);
          digitalWrite(yellowPin, HIGH);
          lastUpdate = now;
        }
        break;
      case YELLOW_TO_RED:
        if (now - lastUpdate >= 2000) {  // 2 seconden geel
          currentState = GREEN;
          digitalWrite(yellowPin, LOW);
          digitalWrite(greenPin, HIGH);
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