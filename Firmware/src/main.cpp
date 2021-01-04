#include "wifi.h"
#include "webserver.h"
#include "ledanimations.h"

#include <Arduino.h>

#include <memory>

#include <ESP8266WiFi.h>

std::unique_ptr<webserver> httpsrv;
ledanimations light;

void setup()
{
  Serial.begin(9600);

  // connect to wifi
  Serial.println("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(1000);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.print("my IP: ");
  Serial.println(WiFi.localIP());
  uint8_t macAddr[6];
  WiFi.macAddress(macAddr);
  Serial.printf("mac address: %02x:%02x:%02x:%02x:%02x:%02x\n", macAddr[0], macAddr[1], macAddr[2], macAddr[3], macAddr[4], macAddr[5]);

  httpsrv.reset(new webserver());
}

void loop()
{
  EVERY_N_MILLISECONDS( 20 ) { light.addgHue(); }
  if(httpsrv->getLightState())
  {
    light.setAnimation(httpsrv->getActiveAnimation());
    light.switchOn();
  }
  else
  {
    light.blackout();
  }
    
}
