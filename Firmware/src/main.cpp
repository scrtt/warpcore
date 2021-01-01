#include <Arduino.h>

#include <ESP8266WiFi.h>

#include "wifi.h"
#include <FS.h>
#include "ESPAsyncWebServer.h"

#include <Adafruit_NeoPixel.h>

#define LED_PIN 4
#define NUM_LEDS 4
#define COLOR_ORDER GRB

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUM_LEDS, LED_PIN);

AsyncWebServer server(80);

String processor(const String &var)
{
  if (var == "HEADLINE")
  {
    String headline = "<h1>Hallo</h1>";
    return headline;
  }
  return String();
}

void setup()
{
  //init leds
  pixels.begin();

  pixels.show();

  Serial.begin(9600);
  SPIFFS.begin();

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

  //starting webserver
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(SPIFFS, "/index.html", String(), false, processor);
  });

  server.begin();
}

void loop()
{
  for (int i = 0; i < NUM_LEDS; i++)
  {
    pixels.setPixelColor(i, pixels.Color(0, 0, 255));
    pixels.show();
    delay(80);
    pixels.setPixelColor(i, pixels.Color(0, 0, 0));
    pixels.show();
  }
}
