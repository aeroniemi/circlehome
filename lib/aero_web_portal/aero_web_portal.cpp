#include "aero_web_portal.h"
#include <WiFiAP.h>
#include <aero_preferences.h>
#include <timezonedb_lookup.h>
WebServer server(80);
extern char *html_form;
const String valid_args[] = {
    "ntp_timezone", "ha_port", "ha_hostname", "wifi_ssid", "wifi_password", "ha_token"};
bool aero_web_server_enabled = false;

void sendError(String text)
{
    server.send(200, "text/html", String("Validation error: " + text));
};
bool handleSetting(String name, String value)
{
    name.trim();
    value.trim();
    if (value.length()==0) {
        return false;
    }
    if (name.equals("ntp_timezone"))
    {
        const char *tz = lookup_posix_timezone_tz(value.c_str());
        if (tz == nullptr)
        {
            sendError(F("Timezone not in database. "));
            return true;
        }
        settings.putString("ntp_timezone", value);
        settings.putString("ntp_tz_str", tz);
    }
    else if (name.equals("ha_port"))
    {
        const int port = value.toInt();
        if (port <= 0 || port > 65535)
        {
            sendError("Port not in range 1-65535");
            return true;
        }
        settings.putInt("ha_port", port);
    }
    else if (name.equals("ha_hostname"))
    {
        if (value.length() < 3)
        {
            sendError("Hostname too short");
            return true;
        }
        if (value.length() > 127)
        {
            sendError("Hostname too long - max 127 char");
            return true;
        }
        for (size_t i = 0; i < value.length(); i++)
        {
            char c = value.charAt(i);
            if (not(isalnum(c) || c == '.' || c == '-' || c == '_'))
            {
                sendError("Hostname contains invalid chars (alphanumeric and .-_ are valid)");
                return true;
            }
        }
        settings.putString("ha_hostname", value);
    }
    else if (name.equals("ha_token"))
    {
        String token = String("Bearer " + value);
        // TODO no validation applied here, need to add when it's clear what can be done
        settings.putString("ha_token", token);
    }
    else if (name.equals("wifi_ssid"))
    {
        if (value.length() < 3)
        {
            sendError("WiFi SSID too short");
            return true;
        }
        if (value.length() > 32)
        {
            sendError("WiFi SSID too long - max 32 char");
            return true;
        }
        settings.putString("wifi_ssid", value);
    }
    else if (name.equals("wifi_password"))
    {
        if (value.length() > 63)
        {
            sendError("WiFi Password too long - max 63 char");
            return true;
        }
        if (value.length() < 8 && value.length() > 0)
        {
            sendError("WiFi Password too short - min 8 char or blank for open network");
            return true;
        }
        settings.putString("wifi_password", value);
    }
    return false;
};

void sendSuccess()
{
    server.sendHeader("Location", "/", true);
    server.send(302);
};



void form_handler()
{
    settings.end();
    settings.begin("settings", false);
    for (int i = 0; i < server.args(); i++)
    {
        if (handleSetting(server.argName(i), server.arg(i)))
        {
            settings.end();
            settings.begin("settings", true);
            return;
        }
    };
    settings.putBool("initialized", true);
    settings.end();
    settings.begin("settings", true);
    sendSuccess();
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