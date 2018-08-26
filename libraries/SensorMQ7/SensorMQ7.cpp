/*
 * SensorMQ7.cpp
 *
 *  Created on: 2018. 04. 14.
 *      Author: Sergio López Ballesteros
 *      Version : 0.1
 */

#include "SensorMQ7.h"

/* Number of read */
const int numRead = 10;

/* Constructor */
SensorMQ7::SensorMQ7(int port) : portSensor(port) {}

/* Get value sensor MQ7 */
float SensorMQ7::getValue() {
  int adc_MQ = 0.0;

  for (int i = 0; i <= numRead; ++i) {
    adc_MQ += analogRead(portSensor); /* Realizamos varias lecturas para obtener una media */
    delay(5); /* Delay 5 ms between reads */
  }

  return adc_MQ / numRead; /* Devolvemos la media de las lecturas */
}

float SensorMQ7::getVoltage() {
  float mV = getValue() * (5.0 / 1024.0); /* Calculate mV (Voltage)*/
  return mV;
}

float SensorMQ7::getCO2PPM() {
   int sensorValue = analogRead(portSensor);
   float sensor_volt = sensorValue * (5.0 / 1023.0);
   float ratio = (5.0 - sensor_volt) / sensor_volt;
   return (float)(19.32 * pow(ratio, -0.64));
}
