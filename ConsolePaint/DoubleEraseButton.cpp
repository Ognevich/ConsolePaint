#include "DoubleEraseButton.h"

DoubleEraseButton::DoubleEraseButton(int y) : UIButton("er2x", y, OnClickActions::DOUBLE_ERASER_B)
{}

OnClickActions DoubleEraseButton::onClick() {
	return OnClickActions::DOUBLE_ERASER_B;
}