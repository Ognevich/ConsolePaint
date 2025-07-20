#include "CircleButton.h"

CircleButton::CircleButton(int y) : UIButton("circle", y, OnClickActions::CIRCLE_B)
{
}

OnClickActions CircleButton::onClick() {
	return OnClickActions::CIRCLE_B;
}