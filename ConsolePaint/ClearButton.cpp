#include "ClearButton.h"

ClearButton::ClearButton(int y) : UIButton("Clear", y, OnClickActions::CLEAR){}

OnClickActions ClearButton::onClick()
{
	std::cout << "Screen is cleaned!" << std::endl;

	return OnClickActions::CLEAR;
}

