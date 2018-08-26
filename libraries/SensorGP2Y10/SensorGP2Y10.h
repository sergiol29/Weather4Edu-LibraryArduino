/*
 * SensorGP2Y10.h
 *
 *  Created on: 2018. 07. 19.
 *      Author: Sergio López Ballesteros
 *      Version : 0.1
 */

#ifndef SENSORGP2Y10_H_
#define SENSORGP2Y10_H_
#include <Arduino.h>

class SensorGP2Y10 {
  private:
    int portAnalogSensor;
    int portDigitalSensor;
    void initializeSensor();
  public:
	   SensorGP2Y10(int portAnalog, int portDigital); /* Constructor */
     float getValue(); /* Get value sensor */
     float calcVoltage(); /* Get voltage sensor */
     float dustDensity(); /* Dust Density */
     float ppm(); /* Concentration PPM (dust particles in parts per million) */
};

#endif /* */
