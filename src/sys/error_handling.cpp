#include "error_handling.h"
lv_color_t UIMessageLevelColor[] = {
    lv_palette_main(LV_PALETTE_CYAN),        // info
    lv_palette_main(LV_PALETTE_LIME),        // debug
    lv_palette_main(LV_PALETTE_AMBER),       // warning
    lv_palette_main(LV_PALETTE_DEEP_ORANGE), // error
    lv_palette_main(LV_PALETTE_RED),         // critical
};

UIMessageHandler eh;
void UIMessageBase::issue()
{
    eh.issue(this);
};
void UIMessageHandler::update(lv_timer_t *timer)
{
    if (eh._error_queue.isEmpty())
        return; // no errors

    if (eh._current_error == nullptr)
    {
        eh._error_queue.pop(&eh._current_error);
        eh.createMsgBox();
    };
};
void UIMessageHandler::onButtonClick(lv_event_t *event)
{
    if (lv_event_get_target_obj(event) == eh._btnLeft)
    {
        eh._current_error->handleLeftButton();
    }
    else if (lv_event_get_target_obj(event) == eh._btnRight)
    {
        eh._current_error->handleRightButton();
    }
};
void UIMessageHandler::createMsgBox()
{
    _background = lv_obj_create(lv_layer_top());
    _title = lv_label_create(_background);
    _text = lv_label_create(_background);
    lv_obj_set_width(_background, 240);
    lv_obj_set_height(_background, 240);
    lv_obj_set_style_border_width(_background, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_scrollbar_mode(_background, LV_SCROLLBAR_MODE_OFF);
    lv_obj_set_style_bg_color(_background, UIMessageLevelColor[_current_error->level], LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_label_set_text(_title, _current_error->title.c_str());
    log_d("%s", _current_error->title.c_str());
    lv_label_set_text(_text, _current_error->text.c_str());
    lv_obj_set_width(_title, 100);
    lv_obj_set_width(_text, 210);
    lv_obj_set_style_text_align(_title, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(_text, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_align(_title, LV_ALIGN_CENTER, 0, -80);
    lv_obj_align(_text, LV_ALIGN_CENTER, 0, -20);
    lv_obj_set_style_text_font(_title, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(_text, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
    if (_current_error->left_btn_text.length() > 0)
    {
        _btnLeft = lv_button_create(_background);
        lv_obj_align(_btnLeft, LV_ALIGN_CENTER, -50, 50);
        lv_obj_t *label = lv_label_create(_btnLeft);
        lv_label_set_text(label, _current_error->left_btn_text.c_str());
        lv_obj_center(label);
        lv_obj_add_event_cb(_btnLeft, onButtonClick, LV_EVENT_PRESSED, NULL);
    }
    if (_current_error->right_btn_text.length() > 0)
    {
        _btnRight = lv_button_create(_background);
        lv_obj_align(_btnRight, LV_ALIGN_CENTER, 50, 50);
        lv_obj_t *label = lv_label_create(_btnRight);
        lv_label_set_text(label, _current_error->right_btn_text.c_str());
        lv_obj_center(label);
        lv_obj_add_event_cb(_btnRight, onButtonClick, LV_EVENT_PRESSED, NULL);
    }
};
void UIMessageBase::close()
{
    eh.deleteMsgBox();
};