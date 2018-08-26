/*
 * SensorMLX90614.h
 *
 *  Created on: 2018. 04. 12.
 *      Author: Sergio López Ballesteros
 *      Version : 0.1
 */

#ifndef SENSORMLX90614_H_
#define SENSORMLX90614_H_
#include <Arduino.h>
//#include <Wire.h>
#include <Adafruit_MLX90614.h>

class SensorMLX90614 {
  private:
	   Adafruit_MLX90614 mlx;
     void initializeSensor();
  public:
	   SensorMLX90614(); /* Constructor */
     float getValueAmbient(); /* Get value sensor */
     float getValueObject(); /* Get value sensor */
};

#endif /* */
