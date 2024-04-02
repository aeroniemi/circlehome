
#include "../ha_api.h"
#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

UIError error_no_wifi(F("Cannot connect to WiFi"));
UIError error_no_home_assistant(F("Cannot connect to HomeAssistant"));
UIError error_auth_home_assistant(F("Authentication with HomeAssistant failed - check token"));
UIInfo info_example(F("This is an example of an info message, hello!"),F("Go Team!"));

int HomeAssistant::sendGetRequest(String endpoint)
{
#if NETWORKING_ENABLED == 0
    return 200;
#else
    if (!_ensureConnected())
        //! error
        ;
    Serial.println("Preparing GET request NR to " + endpoint);
    _httpClient.begin(_host, _port, endpoint);
    _httpClient.addHeader("Authorization", _token);
    Serial.println("Sending GET request to " + endpoint);
    int status_code = _httpClient.GET();
    log_d("GET request dealt with");
    _httpClient.end();
    log_d("GET request completed with status code: %d", status_code);
    return status_code;
#endif
}
JsonDocument HomeAssistant::sendGetRequestWithResponse(String endpoint)
{
    if (!_ensureConnected())
        //! error
        ;
    Serial.println("Sending GET request WR to " + endpoint);
    _httpClient.begin(_host, _port, endpoint);
    _httpClient.addHeader("Authorization", _token);
    int status_code = _httpClient.GET();
    JsonDocument response;
    deserializeJson(response, _httpClient.getStream());
    _httpClient.end();
    response["status_code"] = status_code;
    Serial.println("Status: " + status_code);

    return response;
}
int HomeAssistant::sendPostRequest(String endpoint, JsonDocument body)
{
#if NETWORKING_ENABLED == 0
    return 200;
#else

    if (!_ensureConnected())
        ;
    //! error
    Serial.println("Sending POST request to " + endpoint);
    _httpClient.begin(_host, _port, endpoint);
    _httpClient.addHeader("Authorization", _token);
    _httpClient.addHeader("content-type", "application/json");
    String json;
    serializeJson(body, json);
    int status_code = _httpClient.POST(json);
    _httpClient.end();
    Serial.println("Status: " + status_code);
    return status_code;
#endif
}
JsonDocument HomeAssistant::sendPostRequestWithResponse(String endpoint, JsonDocument body)
{
    Serial.println("Sending POST request to " + endpoint);
    _httpClient.begin(_host, _port, endpoint);
    _httpClient.addHeader("Authorization", _token);
    _httpClient.addHeader("content-type", "application/json");
    String json;
    serializeJson(body, json);
    int status_code = _httpClient.POST(json);
    JsonDocument response;
    deserializeJson(response, _httpClient.getStream());
    _httpClient.end();
    response["status_code"] = status_code;
    Serial.println("Status: " + status_code);
    return response;
}
HomeAssistant::HomeAssistant(char *wifi_ssid, char *wifi_password, char *host, int port, char *token)
{
    _host = host;
    _token = token;
    _port = port;
    _httpClient.useHTTP10(true);
    // _httpClient.setReuse(true);
#if (NETWORKING_ENABLED == 1)
    Serial.println("Connecting to Wifi...");
    WiFi.begin(wifi_ssid, wifi_password);
    int wifi_time = 0;
    while (WiFi.status() != WL_CONNECTED)
    {
        if (wifi_time > WIFI_TIMEOUT)
        {
            error_no_wifi.issue();
            break;
        }
        delay(500);
        wifi_time += 500;
    }
    Serial.println("Connected to Wifi");
#endif
}
bool HomeAssistant::isConnected()
{
    return WiFi.status() == WL_CONNECTED;
}
bool HomeAssistant::_ensureConnected()
{
    if (isConnected())
        return true;
    //! do something
    return false;
}