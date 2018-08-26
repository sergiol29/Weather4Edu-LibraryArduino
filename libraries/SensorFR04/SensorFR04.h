/*
 * SensorFR04.h
 *
 *  Created on: 2018. 04. 12.
 *      Author: Sergio López Ballesteros
 *      Version : 0.1
 */

#ifndef SENSORFR04_H_
#define SENSORFR04_H_
#include <Arduino.h>

class SensorFR04 {
  private:
     int portSensor;
  public:
	   SensorFR04(int port); /* Constructor */
     float getValue(); /* Get value sensor */
};

#endif /* */
