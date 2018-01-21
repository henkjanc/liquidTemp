#include <Arduino.h>
#include <TM1637Display.h>
#include <OneWire.h>
#include <DallasTemperature.h>

// Module connection pins (Digital Pins)
#define DISPLAY_CLK 2
#define DISPLAY_DIO 1

#define ONE_WIRE_BUS 4

TM1637Display     display(DISPLAY_CLK, DISPLAY_DIO);
OneWire           oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup() {
  // put your setup code here, to run once:
  display.setBrightness(0x0F);
  sensors.begin();
}

void loop() {
  sensors.requestTemperatures(); // Send the command to get temperatures
  float temp = sensors.getTempCByIndex(0);
  // put your main code here, to run repeatedly:
  display.showNumberDec((int) (temp * 100.0), true);
}
