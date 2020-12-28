#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

#include "wifi.h"

void setup() {
  Serial.begin(9600);

  // Connect to Wifi
  Serial.println("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
}

void loop() {
  // put your main code here, to run repeatedly:
}