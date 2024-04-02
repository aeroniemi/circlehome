#include "error_handling.h"
ErrorHandler eh;
void Error::issue()
{
    eh.createMsgBox(this);
};
void Error::handleButtons(uint8_t index)
{
    if (index == 0)
    {
        handleLeftButton();
    }
    else
    {
        handleRightButton();
    }   
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
    uint8_t btn_index = lv_buttonmatrix_get_selected_button(eh._btn);
    eh._current_error->handleButtons(btn_index);
};