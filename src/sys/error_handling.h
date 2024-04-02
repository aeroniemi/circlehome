#ifndef ERROR_HANDLING_H
#define ERROR_HANDLING_H
#include <cppQueue.h>
#include <Arduino.h>
#include <lvgl.h>
#define ERROR_BUTTON_LEFT 0
#define ERROR_BUTTON_RIGHT 1
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
    String title;
    String text;
    String left_btn_text;
    String right_btn_text;
    void handleLeftButton();
    void handleRightButton();
    void issue();
};
class ErrorHandler
{
private:
    cppQueue _error_queue = cppQueue(sizeof(Error *), 10, FIFO, true);
    lv_obj_t *_background;
    lv_obj_t *_title;
    lv_obj_t *_text;
    lv_obj_t *_btnLeft;
    lv_obj_t *_btnRight;
    Error *_current_error;

public:
    ErrorHandler(){};
    inline void initialize(){};
    static void update(lv_timer_t *timer);
    void createMsgBox(Error *error);
    void deleteMsgBox()
    {
        lv_obj_delete(_background);
    };
    static void onButtonClick(lv_event_t *event);
};
extern ErrorHandler eh;
#endif