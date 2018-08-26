/*
 * SensorDHT11.h
 *
 *  Created on: 2018. 04. 12.
 *      Author: Sergio López Ballesteros
 *      Version : 0.1
 */

#ifndef SENSORDHT11_H_
#define SENSORDHT11_H_
#include <Arduino.h>
#include <DHT11.h>

class SensorDHT11 {
  private:
	   DHT11 sensor; /* Object librarie DHT11 */
  public:
	   SensorDHT11(int port); /* Constructor */
     float getTemperature(); /* Get value sensor */
     float getHumidity();
};

#endif /* */
