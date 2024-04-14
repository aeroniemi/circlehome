#ifndef HA_ENTITY
#define HA_ENTITY
#include <Arduino.h>
#include <ArduinoJson.h>
#include "ha_homeassistant.h"
class Entity
{
private:
    unsigned long _lastUpdated;
    String _entity_id;
    String _domain;
    String _friendly_name;
    String _state = "unknown";
    void _updateState();
    

public:
    Entity(const String identifier);
    String getIdentifier();
    String getDomain();
    String getState();
    void updateIfRequired();
    String getFriendlyName();
    void updateStateFromJSON(JsonDocument data);
    inline bool turnOn(HomeAssistant *ha)
    {
        return ha->triggerService(this, "turn_on") == 200;
    }
    inline bool turnOff(HomeAssistant *ha)
    {
        return ha->triggerService(this, "turn_off") == 200;
    }
    inline bool toggle(HomeAssistant *ha)
    {
        return ha->triggerService(this, "toggle") == 200;
    }
    // inline bool setBrightness(HomeAssistant *ha, int brightness) { return false; };
};
#endif