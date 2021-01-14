#pragma once

#include <FastLED.h>

class ledanimations final
{
private:
    static constexpr size_t NUM_LEDS{37U};

    CRGBArray<NUM_LEDS> leds;
    CRGBSet leds1;
    CRGBSet leds2;
    CRGBSet leds3;
    uint8_t gHue;

    int activeAnimation;
    int warpDelay;
    void warpcore();
    void animation_1();
    void animation_2();

public:
    ledanimations();
    void blackout();
    void switchOn();
    void setAnimation(int);
    void addgHue();
};
