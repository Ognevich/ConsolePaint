#include "EraseButton.h"

EraseButton::EraseButton(int y) : UIButton("Erase", y, OnClickActions::ERASER_B) {}


OnClickActions EraseButton::onClick()
{
    return OnClickActions::ERASER_B;
}
