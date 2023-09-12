//1-Wire Arduino sketch for BS18B20 waterproof temperature sensor

#include <OneWire.h>
#include <DallasTemperature.h>

float temp = 0.0;
int oneWireBus = 12;
OneWire oneWire(oneWireBus);
DallasTemperature sensors(&oneWire);

void setup() {
  Serial.begin(9600);
  Serial.println("1-Wire Arduino sketch for BS18B20 waterproof temperature sensor");
  sensors.begin();
}

void loop() {
  sensors.requestTemperatures();
  temp = sensors.getTempCByIndex(0);

  Serial.print("Temperature reading: ");
  Serial.println(temp);

  delay(5000);
}
