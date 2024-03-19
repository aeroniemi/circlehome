#include "ui/ui.h"
#ifdef M5STACK_DIAL
#include "hal/m5dial/m5dial.h"
#endif
void setup() {
    ui_init();
};
void loop() {
    ui_update();
    delay(5);
}
