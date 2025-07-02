#ifndef CLAER_BUTTON_H
#define CLAER_BUTTON_H
#include "UIButton.h"
#include "iostream"

class ClearButton : public UIButton {
public:
	ClearButton(int y);
	OnClickActions onClick() override;

};


#endif
