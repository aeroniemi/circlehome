#ifndef HA_LIGHT
#define HA_LIGHT
#include "../ha_entity.h"
#include "../ha_homeassistant.h"
class Light : public Entity
{
    using Entity::Entity;
    bool turnOn(HomeAssistant ha);
    bool turnOff(HomeAssistant ha);
    bool toggle(HomeAssistant ha);
    bool getState(HomeAssistant ha);
    void setBrightness(HomeAssistant ha, int brightness);
    int getBrightness(HomeAssistant ha);
    void getColor(HomeAssistant ha);
    void setColor(HomeAssistant ha);
};
#endif