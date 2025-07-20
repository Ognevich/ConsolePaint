#ifndef CIRCLE_BUTTON_H
#define CIRCLE_BUTTON_H
#include "UIButton.h"


class CircleButton : public UIButton {

public:
	CircleButton(int y);
	OnClickActions onClick() override;

};



#endif 