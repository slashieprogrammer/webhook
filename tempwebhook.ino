
#include <idDHT22.h>
#include <Particle.h>

int idDHT22pin = D4;
void dht22_wrapper();
bool handleDHTResult(int result);

idDHT22 DHT22(idDHT22pin, dht22_wrapper);

void dht22_wrapper()
{
  DHT22.isrCallback();
}

void setup()
{
  Serial.begin(9600);
}

void loop()
{

  DHT22.acquire();
  while (DHT22.acquiring());

  int result = DHT22.getStatus();

  float temp =  DHT22.getCelsius();
  Particle.publish("temp", String(temp), PRIVATE);

  delay(1000);
}
