#pragma once

#include <FastLED.h>

class ledanimations final
{
private:
    static constexpr size_t num_leds{37U};
    CRGB leds[num_leds];

public:
    ledanimations();
    void warpcore();
    void blackout();
};
