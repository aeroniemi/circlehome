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
extern ErrorHandler eh;
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
    inline void handleButtons(ErrorHandler *eh, uint8_t index)
    {
        if (index == 0)
        {
            handleLeftButton(eh);
        }
        else
        {
            handleRightButton(eh);
        }
    }
    inline void handleLeftButton(ErrorHandler *eh){};
    inline void handleRightButton(ErrorHandler *eh){};
    inline void issue()
    {
    }
};
class ErrorHandler
{
private:
    cppQueue _error_queue = cppQueue(sizeof(Error *), 10, FIFO, true);
    lv_obj_t *_msgbox;
    lv_obj_t *_btn;
    Error _current_error;

public:
    ErrorHandler(){};
    inline void initialize(){};
    static void update(lv_timer_t *timer)
    {
        ErrorHandler *eh = (ErrorHandler *)timer->user_data;
        if (eh->_error_queue.isEmpty())
            return; // no errors
        Error error;
        eh->_error_queue.peek(&error);
        if (error.title == eh->_current_error.title)
            return; // error has not changed, so no need to update the UI
        eh->createMsgBox(error);
    };
    void createMsgBox(Error error)
    {
        _msgbox = lv_msgbox_create(NULL);
        lv_msgbox_add_title(_msgbox, error.title);
        lv_msgbox_add_text(_msgbox, error.text);
        _btn = lv_msgbox_add_footer_button(_msgbox, "Ok");
        lv_obj_add_event_cb(_btn, onButtonClick, LV_EVENT_CLICKED, this);
    };
    void deleteMsgBox()
    {
        lv_msgbox_close(_msgbox);
    };
    static void onButtonClick(lv_event_t *event)
    {
        ErrorHandler *eh = (ErrorHandler *)event->user_data;
        uint8_t btn_index = lv_buttonmatrix_get_selected_button(eh->_btn);
        eh->_current_error.handleButtons(eh, btn_index);
    };
};

#endif