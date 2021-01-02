#include "wifi.h"
#include "webserver.h"

#include <Arduino.h>

#include <memory>

#include <ESP8266WiFi.h>

#include <FastLED.h>

#define LED_PIN 4
#define NUM_LEDS 37

std::unique_ptr<webserver> httpsrv;
CRGB leds[NUM_LEDS];



void setup()
{
  //init leds
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);

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

void warpCoreAnimation()
{
  for (int i = NUM_LEDS - 1; i > 31; --i)
  {
    fadeToBlackBy(leds, NUM_LEDS, 135);
    leds[i] = CRGB::Blue;
    FastLED.show();
    delay(30);
  }

  for (int i = 1; i <= 15; i++)
  {
    fadeToBlackBy(leds, NUM_LEDS, 135);
    leds[i - 1] = CRGB::Blue;
    leds[32 - i] = CRGB::Blue;
    FastLED.show();
    delay(30);
  }
  fadeToBlackBy(leds, NUM_LEDS, 135);
  leds[15] = CRGB::White;
  leds[16] = CRGB::White;
  FastLED.show();
  delay(60);
}

void loop()
{
  warpCoreAnimation();
}
