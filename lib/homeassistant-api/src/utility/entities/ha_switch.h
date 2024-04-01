#ifndef HA_SWITCH
#define HA_SWITCH
#include "../ha_entity.h"
#include <lvgl.h>
class Switch : public Entity
{
public:
    using Entity::Entity;
    void turnOn();
    void turnOff();
    void toggle();
    bool getState();
    lv_obj_t *getEntityPage() { return lv_obj_create(NULL); };
};
#endif