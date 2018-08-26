/*
 * SensorDHT11.cpp
 *
 *  Created on: 2018. 04. 12.
 *      Author: Sergio López Ballesteros
 *      Version : 0.1
 */

#include "SensorDHT11.h"
#include <DHT11.h>

/* Constructor */
SensorDHT11::SensorDHT11(int port) : sensor(port) { }

/* Get value sensor DHT11 */
float SensorDHT11::getTemperature() {
  float temperature, humidity;
  sensor.read(humidity, temperature);
  return temperature;
}

float SensorDHT11::getHumidity() {
  float temperature, humidity;
  sensor.read(humidity, temperature);
  return humidity;
}
