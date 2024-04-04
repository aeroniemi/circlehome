#include "aero_web_portal.h"
#include <WiFiAP.h>
#include <aero_preferences.h>
WebServer server(80);
extern char *html_form;
const String valid_args[] = {
    "ntp_timezone", "ha_port", "ha_hostname", "wifi_ssid", "wifi_password", "ha_token"};
bool aero_web_server_enabled = false;
void form_handler()
{
    settings.end();
    settings.begin("settings", false);
    for (int i = 0; i < server.args(); i++)
    {
        String name = server.argName(i);
        String value = server.arg(i);
        for (int i = 0; i < valid_args->length(); i++)
        {
            if (valid_args[i].equals(name))
            {
                log_d("Writing setting: '%s' Value '%s'", name.c_str(), value.c_str());
                settings.putString(name.c_str(), value.c_str());
            };
        };
    };
    settings.putBool("initialized", true);
    settings.end();
    settings.begin("settings", true);
}
void aero_web_portal_setup()
{
    WiFi.softAPConfig(IPAddress(192, 168, 0, 1), IPAddress(192, 168, 0, 1), IPAddress(255, 255, 255, 0));
    WiFi.softAP("M5Dial", "");

    server.on("/", []()
              { server.send(200, "text/html", html_form); });
    server.on("/submit", HTTP_POST, form_handler);

    server.begin();
    aero_web_server_enabled = true;
};