/*
 * SensorBMP280.h
 *
 *  Created on: 2018. 08. 02.
 *      Author: Sergio López Ballesteros
 *      Version : 0.1
 */

#ifndef SENSORBMP280_H_
#define SENSORBMP280_H_
//#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>

class SensorBMP280 {
  private:
     Adafruit_BMP280 bmp;
     bool runBegin = false;
     void initializeSensor();
  public:
	   SensorBMP280(); /* Constructor */
     float getValuePressure(); /* Get value sensor */
     float getValueTemperature(); /* Get value sensor */
     float getValueAltitude(); /* Get value sensor */
};

#endif /* */
