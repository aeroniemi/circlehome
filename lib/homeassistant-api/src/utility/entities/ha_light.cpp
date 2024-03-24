#include "ha_light.h"
bool Light::turnOn(HomeAssistant ha) {
    return ha.triggerService(this, "turn_on") == 200;
}
bool Light::turnOff(HomeAssistant ha) {
    return ha.triggerService(this, "turn_off") == 200;
}
bool Light::toggle(HomeAssistant ha) {
    return ha.triggerService(this, "toggle") == 200;
}
// bool Light::setBrightness(HomeAssistant ha, int brightness) {
//     JsonDocument request;
//     int[4] request["brightness"] = [ 0, 0, 0, 255 ];
//     return ha.triggerService(this, "turn_on", ) == 200;
// }