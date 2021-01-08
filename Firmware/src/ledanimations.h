#pragma once

#include <FastLED.h>

class ledanimations final
{
private:
    static constexpr size_t num_leds{37U};
    CRGB leds[num_leds];
    int activeAnimation;
    void warpcore();
    void animation_1();
    void animation_2();
    uint8_t gHue;
    bool a = false;

public:
    ledanimations();
    void blackout();
    void switchOn();
    void setAnimation(int);
    void addgHue();
};
