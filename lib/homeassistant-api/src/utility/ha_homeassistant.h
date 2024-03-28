#ifndef HA_HOMEASSISTANT
#define HA_HOMEASSISTANT

#include <HTTPClient.h>
#include <ArduinoJson.h>
#include <WiFi.h>
// #include "ha_entity.h"

#ifndef HA_MAX_ENTITIES
#define HA_MAX_ENTITIES 30
#endif
class Entity;
const JsonDocument empty_json;
class HomeAssistant
{
private:
    WiFiClient _wifiClient;
    HTTPClient _httpClient;
    char *_token;
    char *_host;
    int _port;
    bool _ensureConnected();
    Entity *_entities[HA_MAX_ENTITIES];
    int _definedEntities = 0;
    Entity *_activeEntity;

public:
    HomeAssistant(char *wifi_ssid, char *wifi_password, char *host, int port, char *token);
    void getDeviceList();
    bool isConnected();
    bool checkServerStatus();
    int triggerService(Entity *entity, String service, JsonDocument data = JsonDocument());
    int sendGetRequest(String endpoint);
    JsonDocument sendGetRequestWithResponse(String endpoint);
    int sendPostRequest(String endpoint, JsonDocument body = JsonDocument());
    JsonDocument sendPostRequestWithResponse(String endpoint, JsonDocument body = JsonDocument());
    Entity *getEntityByIdentifier(String identifier);
    Entity *getEntityByFriendlyName(String friendly_name);
    bool addEntity(Entity *entity);
    void updateAllStates();
    void createEntities();
    String getRollerString(String domain);
    Entity *getActiveEntity();
    void setActiveEntity(Entity *entity);
};
extern HomeAssistant *ha;

#endif