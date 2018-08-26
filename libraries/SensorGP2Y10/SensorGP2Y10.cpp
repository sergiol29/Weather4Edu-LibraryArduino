/*
 * SensorGP2Y10.cpp
 *
 *  Created on: 2018. 07. 19.
 *      Author: Sergio López Ballesteros
 *      Version : 0.1
 */

#include "SensorGP2Y10.h"

/* Const by calculates */
const unsigned int samplingTime = 280;
const unsigned int deltaTime = 40;
const unsigned int sleepTime = 9680;

/* Constructor */
SensorGP2Y10::SensorGP2Y10(int portAnalog, int portDigital) {
  portAnalogSensor = portAnalog;
  portDigitalSensor = portDigital;
  initializeSensor();
}

float SensorGP2Y10::getValue() {
  return analogRead(portAnalogSensor);
}

/* Get value sensor GP2Y10 */
float SensorGP2Y10::calcVoltage() {
  float voMeasured = getValue();
  float calcVoltage = voMeasured * ( 5.0 / 1024 ); /* Calculate mV (Voltage)*/

  return calcVoltage; /* Return calcule */
}

float SensorGP2Y10::dustDensity() {
  float dustDensity = 0.17 * calcVoltage() - 0.1; 

  if ( dustDensity < 0) {
    dustDensity = 0.00;
  } else if ( dustDensity > 0.5) {
    dustDensity = 0.5;
  }

  return dustDensity;
}

float SensorGP2Y10::ppm() {
  float ppm = ( calcVoltage() - 0.0356 ) * 120000;
  
  if( ppm < 0 ) {
    ppm = 0;
  }
  
  return ppm;
}

/* PRIVATE METHODS */
void SensorGP2Y10::initializeSensor() {
  digitalWrite(portDigitalSensor, LOW);
  delayMicroseconds(samplingTime);

  analogRead(portAnalogSensor);

  delayMicroseconds(deltaTime);
  digitalWrite(portDigitalSensor, HIGH);
  delayMicroseconds(sleepTime);
}