/*
 * SensorGUVAS12D.cpp
 *
 *  Created on: 2018. 04. 12.
 *      Author: Sergio López Ballesteros
 *      Version : 0.1
 */

#include "SensorGUVAS12D.h"
const int numberUV = 12;
const int UV[numberUV] = {50, 227, 318, 408, 503, 606, 696, 795, 881, 976, 1079, 1170}; // De 1 a 11
const int variation = 10;
const int numRead = 10;

/* Constructor */
SensorGUVAS12D::SensorGUVAS12D(int port) : portSensor(port) {}

/* Get value sensor GUVAS12D */
float SensorGUVAS12D::getValue() {
  int adc_GUVA = 0.0;
  for (int i = 0; i <= numRead; ++i) {
    adc_GUVA += analogRead(portSensor); /* Realizamos varias lecturas para obtener una media */
    delay(5); /* Delay 5 ms between reads */
  }

  return adc_GUVA / numRead; /* Devolvemos la media de las lecturas */
}

/* Get value sensor GUVAS12D */
float SensorGUVAS12D::getVoltage() {
  float mV = getValue() * (5.0 / 1024.0); /* Calculate mV (Voltage)*/
  return mV;
}

int SensorGUVAS12D::getUV() {
  int valUV = 0;
  /* Get value analog sensor */
  int valueSensor = getValue();

  /* Calculate value UV */
  for( int i = 0; i < numberUV; ++i ) {
    if ( valueSensor + variation > UV[i] ) {
      valUV++;
    } else {
      break;
    }
  }

  return valUV;
}
