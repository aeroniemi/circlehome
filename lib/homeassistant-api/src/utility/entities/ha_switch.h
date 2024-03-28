#ifndef HA_SWITCH
#define HA_SWITCH
#include "../ha_entity.h"
class Switch : public Entity {
public:
    using Entity::Entity;
    void turnOn();
    void turnOff();
    void toggle();
    bool getState();
    lv_obj_t *getEntityPage() { return screen_on_off; };
};
#endif