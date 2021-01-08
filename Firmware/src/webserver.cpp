#include "webserver.h"

#include <FS.h>

namespace
{
    String processor(const String &var)
    {
        if (var == "HEADLINE")
        {
            String headline = "<h1>Hallo</h1>";
            return headline;
        }
        return String();
    }

} // namespace

webserver::webserver()
    : server(80), lightOn(true), animation(1)
{
    SPIFFS.begin();

    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
        request->send(SPIFFS, "/index.html", String(), false, processor);
    });

     server.on("/css/lcars.min.css", HTTP_GET, [](AsyncWebServerRequest *request) {
        request->send(SPIFFS, "/css/lcars.min.css", String(), false);
    });

    server.on("/on", HTTP_GET, [&](AsyncWebServerRequest *request) {
        lightOn = true;
        request->send(200, "text/plain", "ok");
    });

    server.on("/off", HTTP_GET, [&](AsyncWebServerRequest *request) {
        lightOn = false;
        request->send(200, "text/plain", "ok");
    });

    server.on("/warpcore1", HTTP_GET, [&](AsyncWebServerRequest *request) {
        animation = 1;
        request->send(200, "text/plain", "ok");
    });

    server.on("/warpcore2", HTTP_GET, [&](AsyncWebServerRequest *request) {
        animation = 2;
        request->send(200, "text/plain", "ok");
    });

    server.on("/warpcore3", HTTP_GET, [&](AsyncWebServerRequest *request) {
        animation = 3;
        request->send(200, "text/plain", "ok");
    });

    server.begin();
}

bool webserver::getLightState()
{
    return lightOn;
}

int webserver::getActiveAnimation()
{
    return animation;
}
