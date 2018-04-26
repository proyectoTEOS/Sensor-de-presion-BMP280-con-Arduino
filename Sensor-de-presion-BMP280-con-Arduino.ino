/*
  Created by TEOS
  Domotic with Arduino https://goo.gl/btZpjs
  YouTube https://goo.gl/k7TUSZ
  Instagram https://goo.gl/zEIjia
  Facebook https://goo.gl/eivraR
  Twitter https://goo.gl/du5Wgn
  Github https://goo.gl/Xl5IiS
  Google Plus https://goo.gl/gBnUdh
  WEB https://goo.gl/jtiYJy
*/

#include "SparkFunBME280.h" //https://github.com/sparkfun/SparkFun_BME280_Arduino_Library
#include "Wire.h"

String resultSerialT;

BME280 pressureT;

void setup() {
  Serial.begin(9600);
  pressureT.settings.commInterface = I2C_MODE;
  pressureT.settings.I2CAddress = 0x76;
  pressureT.settings.runMode = 3;
  pressureT.settings.tStandby = 0;
  pressureT.settings.filter = 4;
  pressureT.settings.tempOverSample = 5 ;
  pressureT.settings.pressOverSample = 5;
  pressureT.settings.humidOverSample = 5;
  delay(10);
  pressureT.begin();
}

void loop() {
  resultSerialT = "Temperatura: " + String(pressureT.readTempC(), 2) + "°C || Presion: " + String(pressureT.readFloatPressure(), 2) + " Pa";
  Serial.println(resultSerialT);
  delay(1000);
}
