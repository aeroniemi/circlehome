#include "aero_preferences.h"
#include <aero_error_handling.h>
Preferences settings;
UINeedsSetup error_needs_setup(F("Settings are not initialized"));
void setupPreferences()
{
    log_d("Setting up preferences");
    settings.begin("settings", false);

    if (!settings.getBool("initialized"))
    {
        log_d("Settings need initializing");
        settings.clear();
        settings.putBool("initialized", false);
        error_needs_setup.issue();
    }
    settings.end();
   
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