/*
 * SensorFR04.cpp
 *
 *  Created on: 2018. 04. 14.
 *      Author: Sergio López Ballesteros
 *      Version : 0.1
 */

#include "SensorFR04.h"

/* Number of read */
const int numRead = 10;

/* Constructor */
SensorFR04::SensorFR04(int port) : portSensor(port) { }


/* Get value sensor FR04 */
float SensorFR04::getValue() {
  int adc_FR = 0;
  for (int i = 0; i <= numRead; ++i) {
    adc_FR += analogRead(portSensor); /* Realizamos varias lecturas para obtener una media */
    delay(5); /* Delay 5 ms between reads */
  }

  return adc_FR / numRead; /* Devolvemos la media de las lecturas */
}
