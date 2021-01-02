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
    : server(80)
{
    SPIFFS.begin();
    //starting webserver
    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
        request->send(SPIFFS, "/index.html", String(), false, processor);
    });

    server.begin();
}
