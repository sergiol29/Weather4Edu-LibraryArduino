/*
 * SensorGY302.h
 *
 *  Created on: 2018. 08. 06.
 *      Author: Sergio López Ballesteros
 *      Version : 0.1
 */

#ifndef SENSORGY302_H_
#define SENSORGY302_H_
#include <Arduino.h>
//#include <Wire.h>
#include <BH1750.h>

class SensorGY302 {
  private:
    BH1750 lightMeter;
    bool runBegin = false;
    void initializeSensor();
  public:
	   SensorGY302(); /* Constructor */
     int getValue(); /* Get value sensor */
};

#endif /* */
