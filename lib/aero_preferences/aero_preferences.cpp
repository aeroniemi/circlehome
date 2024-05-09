#include "aero_preferences.h"
#include <aero_error_handling.h>
Preferences settings;
UINeedsSetup error_needs_setup(F("Settings are not initialized"));
void setupPreferences()
{
    log_d("Setting up preferences");   
    settings.begin("settings", true);
}
void resetPreferences()
{
    log_d("Resetting preferences");
    settings.end();
    settings.begin("settings", false);
    settings.clear();
    settings.end();
    setupPreferences();
}

void storeImprovSettings(const char *ssid, const char *password) {
    settings.end();
    settings.begin("settings", false);
    settings.putString("wifi_ssid", ssid);
    settings.putString("wifi_password", password);
    settings.end();
    settings.begin("settings", true);
}