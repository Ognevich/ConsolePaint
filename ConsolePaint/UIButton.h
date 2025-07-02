#ifndef UI_BUTTON
#define UI_BUTTON
#include <string>
#include "Enumarators.h"
#include <iostream>
class UIButton {

public:

	UIButton(std::string label, int x, OnClickActions new_action);
	virtual ~UIButton() = default;

	virtual OnClickActions onClick() = 0;
	

	std::string getLabel();
	int getX();
	OnClickActions getAction();

protected:
	int x;
	std::string label;
	OnClickActions action;

};

#endif
