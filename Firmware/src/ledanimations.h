#pragma once

#include <FastLED.h>

class ledanimations final
{
private:
    size_t num_leds;
    CRGB leds[37];

public:
    ledanimations();
    void warpcore();
    void blackout();
};
