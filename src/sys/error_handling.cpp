#include "error_handling.h"
ErrorHandler eh;
void Error::issue()
{
    eh.createMsgBox(this);
};
void ErrorHandler::update(lv_timer_t *timer)
{
    if (eh._error_queue.isEmpty())
        return; // no errors
    Error *error;
    eh._error_queue.peek(error);
    eh._current_error->title;
    if (error == eh._current_error)
        return; // error has not changed, so no need to update the UI
    eh.createMsgBox(error);
};
void ErrorHandler::onButtonClick(lv_event_t *event)
{
    if (lv_event_get_target_obj(event) == eh._btnLeft){
        eh._current_error->handleLeftButton();
    }
    else if (lv_event_get_target_obj(event) == eh._btnRight){
        eh._current_error->handleRightButton();
    }
};
void ErrorHandler::createMsgBox(Error *error)
{
    _background = lv_obj_create(lv_layer_top());
    _title = lv_label_create(_background);
    _text = lv_label_create(_background);
    lv_obj_set_width(_background, 240);
    lv_obj_set_height(_background, 240);
    lv_obj_set_style_border_width(_background, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_scrollbar_mode(_background, LV_SCROLLBAR_MODE_OFF);
    lv_obj_set_style_bg_color(_background, lv_color_hex(0xAD343E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_label_set_text(_title, error->title->c_str());
    lv_label_set_text(_text, error->text->c_str());
    lv_obj_set_width(_title, 100);
    lv_obj_set_width(_text, 210);
    lv_obj_set_style_text_align(_title, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(_text, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_align(_title, LV_ALIGN_CENTER, 0, -80);
    lv_obj_align(_text, LV_ALIGN_CENTER, 0, -20);
    lv_obj_set_style_text_font(_title, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(_text, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
    if (error->left_btn_text->length() > 0) {
        _btnLeft = lv_btn_create(_background);
        lv_obj_align(_btnLeft, LV_ALIGN_CENTER, -50, 50);
        lv_obj_t *label = lv_label_create(_btnLeft);
        lv_label_set_text(label, error->left_btn_text->c_str());
        lv_obj_center(label);
        lv_obj_add_event_cb(_btnLeft, onButtonClick, LV_EVENT_PRESSED, NULL);
    }
    if (error->right_btn_text->length() > 0) {
        _btnRight = lv_btn_create(_background);
        lv_obj_align(_btnRight, LV_ALIGN_CENTER, 50, 50);
        lv_obj_t *label = lv_label_create(_btnRight);
        lv_label_set_text(label, error->right_btn_text->c_str());
        lv_obj_center(label);
        lv_obj_add_event_cb(_btnRight, onButtonClick, LV_EVENT_PRESSED, NULL);
    }

    
};
void Error::handleLeftButton()
{
    eh.deleteMsgBox();
};
void Error::handleRightButton() {
    ESP.restart();
}