/*
 * SensorMLX90614.cpp
 *
 *  Created on: 2018. 04. 12.
 *      Author: Sergio López Ballesteros
 *      Version : 0.1
 */

#include "SensorMLX90614.h"

/* Number of read */
const int numRead = 10;

/* Constructor */
SensorMLX90614::SensorMLX90614() : mlx(Adafruit_MLX90614(0x5A)) {
  //this->mlx = Adafruit_MLX90614(0x5A); /* 0x5A direction sensor */
  initializeSensor();
}

/* Get value sensor MLX90614 */
float SensorMLX90614::getValueAmbient() {
  float adcMLX = 0.0;

  for (int i = 0; i <= numRead; ++i) {
    adcMLX += mlx.readAmbientTempC(); /* Realizamos varias lecturas para obtener una media */
    delay(5); /* Delay 5 ms between reads */
  }

  return adcMLX / numRead; /* Devolvemos la media de las lecturas */
}

/* Get value sensor MLX90614 */
float SensorMLX90614::getValueObject() {
  float objMLX = 0.0;

  for (int i = 0; i <= numRead; ++i) {
    objMLX += mlx.readObjectTempC(); /* Realizamos varias lecturas para obtener una media */
    delay(5); /* Delay 5 ms between reads */
  }

  return objMLX / numRead; /* Devolvemos la media de las lecturas */
}

/* PRIVATE METHODS */
void SensorMLX90614::initializeSensor() {
  mlx.begin();
}
