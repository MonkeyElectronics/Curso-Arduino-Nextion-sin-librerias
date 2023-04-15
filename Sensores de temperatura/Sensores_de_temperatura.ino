#include "DHT.h"
#include "DallasTemperature.h"
#include "OneWire.h"

#define PINLM35 A0
#define PINDHT11 3
#define PINDS18B20 2

DHT sensordht11(PINDHT11, DHT11);
OneWire comunicacion(PINDS18B20);
DallasTemperature sensords18b20(&comunicacion);

float temperaturalm35, temperaturads18b20;
int temperaturadht11, humedaddht11;

void setup() {
  Serial.begin(9600);
  sensordht11.begin();
  sensords18b20.begin();
}

void loop() {
  temperaturalm35 = analogRead(PINLM35) * 5 * 100 / 1024.0;
  temperaturadht11 = sensordht11.readTemperature();
  humedaddht11 = sensordht11.readHumidity();
  sensords18b20.requestTemperatures();
  temperaturads18b20 = sensords18b20.getTempCByIndex(0);
  enviar_texto("t0.txt=", temperaturalm35);
  enviar_texto("t1.txt=", temperaturadht11);
  enviar_texto("t2.txt=", humedaddht11);
  enviar_texto("t3.txt=", temperaturads18b20);
  delay(400);
}





void enviar_texto(String componente, float dato) {
  Serial.print(componente);
  Serial.print("\"");
  Serial.print(dato);
  Serial.print("\"");
  Serial.write(0xff);
  Serial.write(0xff);
  Serial.write(0xff);
}
