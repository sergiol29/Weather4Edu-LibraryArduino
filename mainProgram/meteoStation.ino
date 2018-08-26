/* Librarys Arduino */
#include <Wire.h>
#include <ArduinoJson.h>

/* My Librarys */
#include <SensorDHT11.h>
#include <SensorSW420.h>
#include <SensorMLX90614.h>
#include <SensorGUVAS12D.h>
#include <SensorMQ7.h>
#include <SensorFR04.h>
#include <SensorGP2Y10.h>
#include <SensorBMP280.h>
#include <SensorGY302.h>

/* JSON */
StaticJsonBuffer<200> jsonBuffer;
JsonObject& data = jsonBuffer.createObject();
char json[256];

/* Const */
const unsigned long DELAY = 60000;

/* Initialize object Sensor */
SensorDHT11 dht11(2); /* 2 = Digital port connect */
SensorSW420 sw420(4); /* 4 = Digital port connect */

SensorGUVAS12D guvas12d(1); /* 1 = Analogic port connect */
SensorMQ7 mq7(0); /* 0 = Analogic port connect */
SensorFR04 fr04(2); /* 2 = Analogic port connect */
SensorGP2Y10 gp2y10(3, 7); /* 7 = Digital port connect, 3 = Analogic port connect */

SensorMLX90614 mlx90614; /* Sensor I2C */
SensorBMP280 bme280; /* Sensor I2C, 680m altitude peligros */
SensorGY302 gy302; /* Sensor I2C */

void setup() {
  Serial.begin(115200);
}

void loop() {
  /* DHT11 */
  float tempDHT11 = dht11.getTemperature();
  /*Serial.print("DHT11 (Temp) = "); Serial.println(tempDHT11);*/

  float humDHT11H = dht11.getHumidity();
  //Serial.print("DHT11 (Hum) = "); Serial.println(humDHT11H);

  /* SW420 */
  long valSW420 = sw420.getValue();
  //Serial.print("SW420 = "); Serial.println(valSW420);

  /* MLX90614 */
  float tempMLXamb = mlx90614.getValueAmbient();
  //Serial.print("MLX (I2C) Amb = "); Serial.println(tempMLXamb);

  float tempMLXobj = mlx90614.getValueObject();
  //Serial.print("MLX (I2C) Obj = "); Serial.println(tempMLXobj);

  /* GUVAS12D */
  float valGuva = guvas12d.getValue();
  //Serial.print("Guva = "); Serial.println(valGuva);

  int valUV = guvas12d.getUV();
  //Serial.print("Guva (UV) = "); Serial.println(valUV);

  /* MQ7 */
  float valMQ7 = mq7.getValue();
  //Serial.print("MQ7 = "); Serial.println(valMQ7);

  float valMQ7PPM = mq7.getCO2PPM();
  //Serial.print("MQ7 PPM = "); Serial.println(valMQ7PPM);

  /* FR04 */
  float valFR = fr04.getValue();
  //Serial.print("FR04 = "); Serial.println(valFR);
  
  /* GP2Y10 */
  float valGP2Y10Dust = gp2y10.dustDensity();
  
  /* GP2Y10 */
  float valGP2Y10PPM = gp2y10.ppm();
  
  /* GY302 */
  uint16_t valGY302 = gy302.getValue();
  //Serial.print("GY302 (I2C) = "); Serial.println(valGY302);

  /* BMP280 */
  float valBMPTemp = bme280.getValueTemperature();
  //Serial.print("BMP280 (I2C) Temp(C) = "); Serial.println(valBMPTemp);

  float valBMPre = bme280.getValuePressure();
  //Serial.print("BMP280 (I2C) Pre(Pa) = "); Serial.println(valBMPre);
  
  int valBMPAlt = bme280.getValueAltitude();
  //Serial.print("BMP280 (I2C) Alt(m) = "); Serial.println(valBMPAlt);

  /* Create JSON */
  data["TEMP_DHT"] = tempDHT11;
  data["HUM_DHT"] = humDHT11H;
  data["SW420"] = valSW420;
  data["TEMP_AMB_MLX"] = tempMLXamb;
  data["TEMP_OBJ_MLX"] = tempMLXobj;
  data["GUVA"] = valGuva;
  data["GUVA_UV"] = valUV;
  data["MQ7"] = valMQ7;
  data["MQ7PPM"] = valMQ7PPM;
  data["FR04"] = valFR;
  data["GP2Y10Dust"] = valGP2Y10Dust;
  data["GP2Y10PPM"] = valGP2Y10PPM;
  data["GY302"] = valGY302;
  data["BMP280_TMP"] = valBMPTemp;
  data["BMP280_PRE"] = valBMPre;
  data["BMP280_ALT"] = valBMPAlt;
  data["BAT"] = 40;
  
  data.printTo(json, sizeof(json)); /* Creamos JSON con el array generado */
  Serial.print(json); /* Enviamos JSON a nodeMCU por puerto serial TX */

  delay(DELAY);
}
