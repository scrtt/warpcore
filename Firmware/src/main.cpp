#include <Arduino.h>
#include <ESP8266WiFi.h>

#include "wifi.h"
#include <FS.h>
#include "ESPAsyncWebServer.h"


AsyncWebServer server(80);

void setup()
{
  Serial.begin(9600);
  SPIFFS.begin();

  // connect to wifi
  Serial.println("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
//kacke
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

  //starting webserver
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(SPIFFS, "/index.html", String(), false);
  });

  server.begin();
}

void loop()
{
  Serial.println("hallo_timmy");
}
