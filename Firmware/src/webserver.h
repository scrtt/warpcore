#pragma once

#include <ESPAsyncWebServer.h>

class webserver final
{
private:
    AsyncWebServer server;
    bool lightOn;
    int animation;
public:
    webserver();
    bool getLightState();
    int getActiveAnimation();
};
