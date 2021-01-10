#include "webserver.h"

#include <FS.h>

namespace
{
    String processor(const String &var)
    {
        if (var == "HEADLINE")
        {
            String headline = "LCARS";
            return headline;
        }
        return String();
    }

    String boolToString(const bool &bo)
    {
        if(bo)
        {
            return "true";
        }
        else
        {
            return "false";
        }
        
    }
} // namespace

webserver::webserver()
    : server(80), lightOn(true), animation(1)
{
    SPIFFS.begin();

    server.on("/", HTTP_GET, [&](AsyncWebServerRequest *request) {
        request->send(SPIFFS, "/index.html", String(), false, processor);
    });

    server.on("/control", HTTP_GET, [&](AsyncWebServerRequest *request) {
        int paramsNr = request->params();
        for (int i = 0; i < paramsNr; i++)
        {
            AsyncWebParameter *p = request->getParam(i);
            if (p->name() == "state")
            {
                if(p->value() == "on")
                {
                    lightOn = true;
                }
                else
                {
                    lightOn = false;
                }  
            }
        }

        request->send(200, "text/json", getJSON());
    });

    server.on("/css/lcars.min.css", HTTP_GET, [](AsyncWebServerRequest *request) {
        request->send(SPIFFS, "/css/lcars.min.css", String(), false);
    });

    server.on("/js/script.js", HTTP_GET, [](AsyncWebServerRequest *request) {
        request->send(SPIFFS, "/js/script.js", String(), false);
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

String webserver::getJSON()
{
    String json = "{";
    json += "\"state\": \""+boolToString(lightOn)+"\"";
    json += "}";

    return json;
}
