#include "aero_preferences.h"
#include <aero_error_handling.h>
Preferences settings;
UINeedsSetup error_needs_setup(F("Settings are not initialized"));
void setupPreferences()
{
    log_d("Setting up preferences");   
    settings.begin("settings", false);
}
void resetPreferences()
{
    log_d("Resetting preferences");
    settings.clear();
    setupPreferences();
}

void storeImprovSettings(const char *ssid, const char *password) {
    settings.putString("wifi_ssid", ssid);
    settings.putString("wifi_password", password);
}