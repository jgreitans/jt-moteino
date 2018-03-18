#include <OneWire.h>
#include <DallasTemperature.h>

#define ONEWIRE_PIN 4
#define LED 9

bool sensorFound = false;
OneWire bus(ONEWIRE_PIN);
DallasTemperature sensors(&bus);
DeviceAddress sensor;

void blink(int times = 1);

void setup() {
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
  Serial.begin(115200);
  sensors.begin();

  sensorFound = sensors.getAddress(sensor, 0);
  if (sensorFound) {
    sensors.setResolution(sensor, 9);
    blink(3);
  } else {
    Serial.println("Sensor not found!");
  }
}

void loop() {
  if (!sensorFound) {
    return;
  }
  char ch = Serial.read();
  if (ch == 't') {
    sensors.requestTemperatures();
    Serial.println(sensors.getTempC(sensor));
    blink();
  }
}


void blink(int times) {
  for (int i = 0; i < times; i++) {
    digitalWrite(LED, HIGH);
    delay(250);
    digitalWrite(LED, LOW);
    delay(250);
  }
}

