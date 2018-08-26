/*
 * SensorSW420.h
 *
 *  Created on: 2018. 04. 12.
 *      Author: Sergio López Ballesteros
 *      Version : 0.1
 */

#ifndef SENSORSW420_H_
#define SENSORSW420_H_
#include <Arduino.h>

class SensorSW420 {
  private:
	   int portLed = 13;
     int portSensor;
     long TP_init();
  public:
	   SensorSW420(int port); /* Constructor */
     long getValue(); /* Get value sensor */
};

#endif /* */
