#include "ledanimations.h"

ledanimations::ledanimations()
    : leds1(leds(0, 14))
    , leds2(leds(15, 16))
    , leds3(leds(17, 36))
    , gHue(0)
{
  FastLED.addLeds<WS2812B, 4, GRB>(leds, NUM_LEDS);
}

void ledanimations::warpcore()
{

  for (int i = NUM_LEDS - 1; i > 31; --i)
  {
    if (i <= 34)
    {
      leds2.fadeToBlackBy(60);
      FastLED.show();
    }

    leds3.fadeToBlackBy(135);
    leds1.fadeToBlackBy(135);
    leds[i] = CRGB::Blue;
    FastLED.show();
    FastLED.delay(80);
  }

  for (int i = 0; i < 15; i++)
  {
    leds1.fadeToBlackBy(135);
    leds3.fadeToBlackBy(135);
    leds[i] = CRGB::Blue;
    leds[31 - i] = CRGB::Blue;
    FastLED.show();
    FastLED.delay(80);

    if (i == 13)
    {
      leds2.fill_solid(CRGB::White);
      FastLED.show();
    }
  }
}

void ledanimations::blackout()
{
  leds.fill_solid(CRGB(0, 0, 0));
  FastLED.show();
}

void ledanimations::animation_1()
{
  leds3.fill_solid(CRGB::Blue);
  FastLED.show();
  delay(1000);
  leds1.fill_solid(CRGB::Blue);
  FastLED.show();
  delay(2000);
  leds3.fadeToBlackBy(250);
  FastLED.show();
  delay(3000);
}

void ledanimations::animation_2()
{ /*
  fill_rainbow(leds, num_leds, gHue, 7);
  FastLED.show();*/
}

void ledanimations::setAnimation(int animation)
{
  activeAnimation = animation;
}

void ledanimations::addgHue()
{
  gHue = gHue + 1;
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
