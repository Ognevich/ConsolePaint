#ifndef LOAD_BUTTON_H
#define LOAD_BUTTON_H
#include "UIButton.h"
#include "iostream"

class LoadButton : public UIButton{
public:
	LoadButton(int y);
	OnClickActions onClick() override;

	
};


#endif 