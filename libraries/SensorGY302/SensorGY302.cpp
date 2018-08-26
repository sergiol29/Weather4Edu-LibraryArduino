/*
 * SensorGY302.cpp
 *
 *  Created on: 2018. 04. 12.
 *      Author: Sergio López Ballesteros
 *      Version : 0.1
 */

#include "SensorGY302.h"

/* Constructor */
SensorGY302::SensorGY302() { }

/* Get value sensor GY302 */
int SensorGY302::getValue() {
  if (!runBegin) {
    initializeSensor();
  }
  return lightMeter.readLightLevel();
}

/* PRIVATE METHODS */
void SensorGY302::initializeSensor() {
  lightMeter.begin(); /* 0x23 direction sensor */
  runBegin = true;
}
