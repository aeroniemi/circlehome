#ifndef HA_BASICS
#define HA_BASICS
#include "../ha_api.h"

bool HomeAssistant::checkServerStatus()
{
    const JsonDocument response = sendGetRequestWithResponse("/api/");
    if (response["status_code"] != 200)
        // invalid response
        return false;
    if (response["message"] == "API running.")
        return true;
    return false;
}
void HomeAssistant::getDeviceList(){};

Entity * HomeAssistant::getEntityByIdentifier(String identifier)
{
    for (int i = 0; i < _definedEntities; i++)
    {
        if (_entities[i]->getIdentifier().equals(identifier))
        {
            return _entities[i];
        }
    }
    log_w("No Entity with identifier '%s' found", identifier.c_str());
    return nullptr;
}
Entity * HomeAssistant::getEntityByFriendlyName(String friendly_name)
{
    for (int i = 0; i < _definedEntities; i++)
    {
        if (_entities[i]->getFriendlyName().equals(friendly_name))
        {
            return _entities[i];
        }
    }
    log_w("No Entity with friendly_name '%s' found", friendly_name.c_str());
    return nullptr;
}

bool HomeAssistant::addEntity(Entity *entity)
{
    if (_definedEntities >= HA_MAX_ENTITIES) {
        log_w("No empty space available");
        return false;
    }
    _entities[_definedEntities] = entity;
    log_d("Successfully added entity at position %d", _definedEntities);
    _definedEntities++;
    return true;
}
int HomeAssistant::triggerService(Entity *entity, String service) {
    JsonDocument body;
    body["entity_id"] = entity->getIdentifier();
    int response = sendPostRequest(String("/api/services/" + entity->getDomain() + "/" + service), body);
    return response;
}

#endif