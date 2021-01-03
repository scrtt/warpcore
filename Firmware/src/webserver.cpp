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
    : server(80), lightOn(true)
{
    SPIFFS.begin();

    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
        request->send(SPIFFS, "/index.html", String(), false, processor);
    });

    server.on("/on", HTTP_GET, [&](AsyncWebServerRequest *request) {
        webserver::lightOn = true;
        request->send(200, "text/plain", "ok");
    });

    server.on("/off", HTTP_GET, [&](AsyncWebServerRequest *request) {
        webserver::lightOn = false;
        request->send(200, "text/plain", "ok");
    });

    server.begin();
}

bool webserver::getLightState()
{
    return lightOn;
}