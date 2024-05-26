#ifndef ERROR_HANDLING_H
#define ERROR_HANDLING_H
#include <cppQueue.h>
#include <Arduino.h>
#include <lvgl.h>
// #include <aero_web_portal.h>
#define ERROR_BUTTON_LEFT 0
#define ERROR_BUTTON_RIGHT 1
enum UIMessageLevel
{
    info = 0,
    debug,
    warning,
    error,
    critical
};
extern lv_color_t UIMessageLevelColor[];
class UIMessageHandler;
class UIMessageBase;

class UIMessageHandler
{
private:
    cppQueue _error_queue = cppQueue(sizeof(UIMessageBase *), 10, FIFO, true);
    lv_obj_t *_background;
    lv_obj_t *_title;
    lv_obj_t *_text;
    lv_obj_t *_btnLeft;
    lv_obj_t *_btnRight;
    UIMessageBase *_current_error;

public:
    UIMessageHandler(){};
    inline void initialize(){};
    static void update(lv_timer_t *timer);
    void createMsgBox();
    void deleteMsgBox()
    {
        lv_obj_delete(_background);
        _current_error = nullptr;
    };
    void issue(UIMessageBase *error)
    {
        _error_queue.push(&error);
    }
    static void onButtonClick(lv_event_t *event);
    void reboot()
    {
        log_d("! Reboot has been requested, will restart shortly.");
        delay(100);
        ESP.restart();
    }
};
extern UIMessageHandler eh;

class UIMessageBase
{
public:
    UIMessageBase(String _title, String _text, String _left_btn_text, String _right_btn_text, UIMessageLevel _level)
    {
        title = _title;
        text = _text;
        left_btn_text = _left_btn_text;
        right_btn_text = _right_btn_text;
        level = _level;
    };
    static lv_color_t _level_colors[5];
    UIMessageLevel level;
    String title;
    String text;
    String left_btn_text;
    String right_btn_text;
    virtual void handleLeftButton(){};
    virtual void handleRightButton(){};
    void issue();
    void close();
};

class UIInfo : public UIMessageBase
{
public:
    UIInfo(String _text, String _left_btn_text = F("Ignore"), String _right_btn_text = "") : UIMessageBase(F("Info"), _text, _left_btn_text, "", info)
    {
        log_i("%s", _text);
    };
    void handleLeftButton() override
    {
        close();
    };
};
class UIError : public UIMessageBase
{
public:
    UIError(String _text) : UIMessageBase(F("Error"), _text, F("Ignore"), F("Restart"), error)
    {
        log_e("%s", _text);
    };
    void handleLeftButton() override
    {
        close();
    };
    void handleRightButton() override
    {
        eh.reboot();
    };
};
class UICritical : public UIMessageBase
{
public:
    UICritical(String _text) : UIMessageBase(F("Critical"), _text, "", F("Restart"), critical)
    {
        log_e("%s", _text);
    };
    void handleRightButton() override
    {
        eh.reboot();
    };
};
class UINeedsSetup : public UIMessageBase
{
public:
    UINeedsSetup(String _text) : UIMessageBase(F("Setup"), _text, F("Setup"), F("Restart"), debug)
    {
        log_d("%s", _text);
    };
    void handleLeftButton() override
    {
        // aero_web_portal_setup();
    };
    void handleRightButton() override
    {
        eh.reboot();
    };
};
#endif