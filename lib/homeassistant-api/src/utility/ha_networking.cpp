 
#include "../ha_api.h"
#include <WiFi.h>
#include <HTTPClient.h>

int HomeAssistant::sendGetRequest(String endpoint)
{
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
    deserializeJson(response,_httpClient.getStream());
    _httpClient.end();
    response["status_code"] = status_code;
    Serial.println("Status: " + status_code);
    
    return response;
}
int HomeAssistant::sendPostRequest(String endpoint, JsonDocument body)
{
    if (!_ensureConnected())
        ;
        //!error
    Serial.println("Sending POST request to " + endpoint);
    _httpClient.begin(_host, _port, endpoint);
    _httpClient.addHeader("Authorization", _token);
    String json;
    serializeJson(body, json);
    int status_code = _httpClient.POST(json);
    _httpClient.end();
    Serial.println("Status: " + status_code);
    return status_code;
}
JsonDocument HomeAssistant::sendPostRequestWithResponse(String endpoint, JsonDocument body){
    Serial.println("Sending POST request to " + endpoint);
    _httpClient.begin(_host, _port, endpoint);
    _httpClient.addHeader("Authorization", _token);
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
HomeAssistant::HomeAssistant(char* wifi_ssid, char* wifi_password, char* host, int port, char* token)
{
    _host = host;
    _token = token;
    _port = port;
    _httpClient.useHTTP10(true);
    // _httpClient.setReuse(true);
    Serial.println("Connecting to Wifi...");
    WiFi.begin(wifi_ssid, wifi_password);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
    }
    Serial.println("Connected to Wifi");
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