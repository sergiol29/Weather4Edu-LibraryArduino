/*
 * SensorSW420.cpp
 *
 *  Created on: 2018. 04. 12.
 *      Author: Sergio López Ballesteros
 *      Version : 0.1
 */

#include "SensorSW420.h"

/* Constructor */
SensorSW420::SensorSW420(int port) : portSensor(port) {}

/* Get value sensor SW420 */
long SensorSW420::getValue() {
  long value = TP_init();
  return value;
}

/* PRIVATE METHODS */
long SensorSW420::TP_init() {
  delay(10);
  long val = pulseIn(portSensor, HIGH);  //wait for the pin to get HIGH and returns measurement
  return val;
}
