#ifndef SAVE_BUTTON_H
#define SAVE_BUTTON_H
#include "UIButton.h"
#include "iostream"
#include "Defines.h"
class SaveButton : public UIButton {

public:
	SaveButton(int y);
	OnClickActions onClick() override;

};

#endif 