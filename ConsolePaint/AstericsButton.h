#ifndef ASTERICS_BUTTON_H
#define ASTERICS_BUTTON_H
#include "UIButton.h"

class AstericsButton : public UIButton {
public:
	AstericsButton(int y);
	OnClickActions onClick() override;
};

#endif