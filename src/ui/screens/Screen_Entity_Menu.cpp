#include "Screen_Entity_Menu.h"
void Screen_Entity_Menu::roller_handler(lv_event_t *event)
{
    Screen_Entity_Menu *screen = (Screen_Entity_Menu *)event->user_data;
    if (ha->getNumEntities() == 0)
    {
        log_d("No Entities found, so cannot select");   
        return;
    };
    char friendlyName[40];
    lv_roller_get_selected_str(screen->roller, friendlyName, 40);
    if (strcmp(friendlyName, "No Entities found"))
        ha->setActiveEntity(ha->getEntityByFriendlyName(friendlyName));
    //! no longer exists lv_screen_load(ha->getActiveEntity()->getEntityPage());

    // log_d("Active Entity: %s", ha->getActiveEntity()->getIdentifier().c_str());
    //     ha->getActiveEntity()->toggle(ha);
}
Screen_Entity_Menu screen_entity_menu;