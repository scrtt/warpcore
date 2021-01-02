#pragma once

#include <ESPAsyncWebServer.h>

class webserver final
{
private:
    AsyncWebServer server;

public:
    webserver();
};
