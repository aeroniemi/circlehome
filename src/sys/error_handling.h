#ifndef ERROR_HANDLING_H
#define ERROR_HANDLING_H
#include <cppQueue.h>
#include <Arduino.h>
#include <lvgl.h>
enum ErrorLevel
{
    info = 0,
    debug,
    warning,
    error,
    critical
};
class ErrorHandler;
class Error;
class Error
{
public:
    Error(String title, String text, String left_btn_text = F("Ignore"), String right_btn_text = F("Restart")) : title{title}, text{text}, left_btn_text{left_btn_text}, right_btn_text{right_btn_text}
    {
    }
    ErrorLevel level;
    String title[20];
    String text[40];
    String left_btn_text[10];
    String right_btn_text[10];
    uint32_t left_btn_color;
    uint32_t right_btn_color;
    void handleButtons(uint8_t index);
    inline void handleLeftButton(){};
    inline void handleRightButton(){};
    void issue();
};
class ErrorHandler
{
private:
    cppQueue _error_queue = cppQueue(sizeof(Error *), 10, FIFO, true);
    lv_obj_t *_msgbox;
    lv_obj_t *_btn;
    Error *_current_error;

public:
    ErrorHandler(){};
    inline void initialize(){};
    static void update(lv_timer_t *timer);
    void createMsgBox(Error *error)
    {
        _msgbox = lv_msgbox_create(NULL);
        lv_msgbox_add_title(_msgbox, error->title->c_str());
        lv_msgbox_add_text(_msgbox, error->text->c_str());
        _btn = lv_msgbox_add_footer_button(_msgbox, "Ok");
        lv_obj_add_event_cb(_btn, onButtonClick, LV_EVENT_CLICKED, this);
    };
    void deleteMsgBox()
    {
        lv_msgbox_close(_msgbox);
    };
    static void onButtonClick(lv_event_t *event);
};
extern ErrorHandler eh;
#endif