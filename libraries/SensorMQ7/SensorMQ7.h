/*
 * SensorMQ7.h
 *
 *  Created on: 2018. 04. 12.
 *      Author: Sergio López Ballesteros
 *      Version : 0.1
 */

#ifndef SENSORMQ7_H_
#define SENSORMQ7_H_
#include <Arduino.h>

class SensorMQ7 {
  private:
     int portSensor;
  public:
	   SensorMQ7(int port); /* Constructor */
     float getValue(); /* Get value sensor */
     float getVoltage(); /* Get value sensor */
     float getCO2PPM(); /* Get value ppm CO2 */
};

#endif /* */
