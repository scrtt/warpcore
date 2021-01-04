#include "ledanimations.h"

ledanimations::ledanimations()
: gHue(0)
{
  FastLED.addLeds<WS2812B, 4, GRB>(leds, num_leds);
}

void ledanimations::warpcore()
{
  for (int i = num_leds - 1; i > 31; --i)
  {
    fadeToBlackBy(leds, num_leds, 135);
    leds[i] = CRGB::Blue;
    FastLED.show();
    delay(30);
  }

  for (int i = 0; i < 15; i++)
  {
    fadeToBlackBy(leds, num_leds, 135);
    leds[i] = CRGB::Blue;
    leds[31 - i] = CRGB::Blue;
    FastLED.show();
    delay(30);
  }
  fadeToBlackBy(leds, num_leds, 135);
  FastLED.show();
  leds[15] = CRGB::White;
  leds[16] = CRGB::White;
  FastLED.show();
  delay(60);
}

void ledanimations::blackout()
{
  fill_solid(leds, num_leds, CRGB(0, 0, 0));
  FastLED.show();
}

void ledanimations::animation_1()
{
  fill_solid(leds, num_leds, CRGB(120, 120, 20));
  FastLED.show();
}

void ledanimations::animation_2()
{
 fill_rainbow( leds, num_leds, gHue, 7);
 FastLED.show();
}

void ledanimations::setAnimation(int animation)
{
  activeAnimation = animation;
}

void ledanimations::addgHue()
{
  gHue = gHue+1;
}

void ledanimations::switchOn()
{
  switch (activeAnimation)
  {
  case 1:
    warpcore();
    break;

  case 2:
    animation_1();
    break;

  case 3:
    animation_2();
    break;

  default:
    warpcore();
  }
} 
