#ifndef ERASE_BUTTON_H
#define ERASE_BUTTON_H
#include "UIButton.h"


class EraseButton : public UIButton  {

public:
	EraseButton(int y);
	OnClickActions onClick() override;

};

#endif
