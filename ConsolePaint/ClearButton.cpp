#include "ClearButton.h"

ClearButton::ClearButton(int y) : UIButton("Clear", y, OnClickActions::CLEAR){}

OnClickActions ClearButton::onClick()
{
	return OnClickActions::CLEAR;
}

