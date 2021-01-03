#pragma once

#include <ESPAsyncWebServer.h>

class webserver final
{
private:
    AsyncWebServer server;
    bool lightOn;
public:
    webserver();
    bool getLightState();
};
