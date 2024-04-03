#include "aero_preferences.h"
Preferences settings;

void setupPreferences() {
    settings.begin("settings", false);

    if (!settings.isKey("initialized")) {
        settings.putString("ntp_timezone", "Europe/London");
        settings.putUInt("ha_port", 8123);
        settings.putString("ha_token", "");
        settings.putString("wifi_ssid", "");
        settings.putString("wifi_password", "");
        settings.putString("ha_hostname", "homeassistant.local");
        settings.putBool("initialized", true);
    }
    settings.end();
    settings.begin("settings", true);
}