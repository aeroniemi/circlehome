#include "Screen_Entity_Menu.h"
void Screen_Entity_Menu::roller_handler(lv_event_t *event)
{
    Screen_Entity_Menu *screen = (Screen_Entity_Menu *)event->user_data;
    char friendlyName[40];
    lv_roller_get_selected_str(screen->roller, friendlyName, 40);
    ha->setActiveEntity(ha->getEntityByFriendlyName(friendlyName));
    lv_screen_load(ha->getActiveEntity()->getEntityPage());
    // log_d("Active Entity: %s", ha->getActiveEntity()->getIdentifier().c_str());
    //     ha->getActiveEntity()->toggle(ha);
}
Screen_Entity_Menu screen_entity_menu;