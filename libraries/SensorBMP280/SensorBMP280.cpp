/*
 * SensorBMP280.cpp
 *
 *  Created on: 2018. 08. 02.
 *      Author: Sergio López Ballesteros
 *      Version : 0.1
 */

#include "SensorBMP280.h"

/* Constructor */
SensorBMP280::SensorBMP280() { }

/* Get value sensor BMP280 */
float SensorBMP280::getValuePressure() {
  if (!runBegin) {
    initializeSensor();
  }

  return bmp.readPressure() / 100;
}

/* Get value sensor BMP280 */
float SensorBMP280::getValueTemperature() {
  if (!runBegin) {
    initializeSensor();
  }

  return bmp.readTemperature();
}

/* Get value sensor BMP280 */
float SensorBMP280::getValueAltitude() {
  if (!runBegin) {
    initializeSensor();
  }

  return bmp.readAltitude();
}

/* PRIVATE METHODS */
void SensorBMP280::initializeSensor() {
  bmp.begin(0x76); /* 0x76 direction sensor */
  runBegin = true;
}
