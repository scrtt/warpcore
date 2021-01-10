#pragma once

#include <ESPAsyncWebServer.h>

class webserver final
{
private:
    AsyncWebServer server;
    bool lightOn;
    int animation;
    String getJSON();
public:
    webserver();
    bool getLightState();
    int getActiveAnimation();
};
