/*
 * SensorGUVAS12D.h
 *
 *  Created on: 2018. 04. 12.
 *      Author: Sergio López Ballesteros
 *      Version : 0.1
 */

#ifndef SENSORGUVAS12D_H_
#define SENSORGUVAS12D_H_
#include <Arduino.h>

class SensorGUVAS12D {
  private:
    int portSensor;
  public:
     SensorGUVAS12D(int port); /* Constructor */
     float getValue(); /* Get value sensor */
     float getVoltage(); /* Get value sensor */
     int getUV(); /* Get value sensor */
};

#endif /* */
