#include "aero_web_portal.h"
#include <WiFiAP.h>
#include <aero_preferences.h>
#include <timezonedb_lookup.h>
WebServer server(80);
extern char *html_form;
const String valid_args[] = {
    "ntp_timezone", "ha_port", "ha_hostname", "wifi_ssid", "wifi_password", "ha_token"};
bool aero_web_server_enabled = false;

void aero_web_portal_setup()
{
    // server.on("/", []()
    //           { server.send(200, "text/plain", "hello!"); });
    server.on("/", []()
              { server.sendHeader("Location", String("http://homeassistant.local:8123/auth/authorize?client_id=https%3A%2F%2F" + WiFi.localIP().toString() + "&redirect_uri=https%3A%2F%2F" + WiFi.localIP().toString() + "/auth_callback"), true);
                                  server.send(302, "text/plain", ""); });
    server.on("/auth_callback", []()
              {
         for (int i = 0; i < server.args(); i++)
    {
        if (server.argName(i).equals("code")) {
            String token = server.arg(i);
            log_d("Setting token to '%s'", token.c_str());
            settings.putString("ha_token", token);
        };
        // log_d("%s : %s", server.argName(i), server.arg(i));
    };

    server.send(200, "text/plain", "Success"); });
    server.begin();
};