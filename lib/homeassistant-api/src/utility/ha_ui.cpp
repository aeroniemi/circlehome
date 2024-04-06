#include "../ha_api.h"
#include "ha_ui.h"

String HomeAssistant::getRollerString(String domain)
{
    String roller = "";
    log_d("Starting roller string");
    for (int i = 0; i < _definedEntities; i++)
    {
        // String lcl = ;
        // log_d("%s", lcl);
        if (_entities[i]->getDomain().equals(domain))
        {
            log_d("Found a device in the domain");
            roller.concat(_entities[i]->getFriendlyName());
            roller.concat("\n");
            log_d("%s", roller.c_str());
        }
    }
    roller.trim();
    if (roller.length() == 0)
    {
        roller = F("No Entities found");
    }
    return roller;
}