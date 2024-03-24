#ifndef HA_HOMEASSISTANT
#define HA_HOMEASSISTANT

#include <HTTPClient.h>
#include <ArduinoJson.h>
#include <WiFi.h>
#include "ha_entity.h"

#ifndef HA_MAX_ENTITIES
#define HA_MAX_ENTITIES 10
#endif
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

public:
    HomeAssistant(char *wifi_ssid, char *wifi_password, char *host, int port, char *token);
    void getDeviceList();
    bool isConnected();
    bool checkServerStatus();
    int triggerService(Entity *entity, String service) { return 0; };
    int sendGetRequest(String endpoint);
    JsonDocument sendGetRequestWithResponse(String endpoint);
    int sendPostRequest(String endpoint, JsonDocument body);
    JsonDocument sendPostRequestWithResponse(String endpoint, JsonDocument body);
    Entity *getEntityByIdentifier(String identifier);
    bool addEntity(Entity *entity);
    void updateAllStates();
    void createEntities();
    String getRollerString(String domain);
};
extern HomeAssistant *ha;

#endif