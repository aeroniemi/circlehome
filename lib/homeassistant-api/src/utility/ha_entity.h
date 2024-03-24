#ifndef HA_ENTITY
#define HA_ENTITY
#include <Arduino.h>
#include <ArduinoJson.h>

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
};
#endif