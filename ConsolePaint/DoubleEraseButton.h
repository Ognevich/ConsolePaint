#ifndef ERASE_DOUBLE_BUTTON_H
#define ERASE_DOUBLE_BUTTON_H
#include "UIButton.h"

class DoubleEraseButton : public UIButton {

public:

	DoubleEraseButton(int y);
	OnClickActions onClick() override;


};

#endif

