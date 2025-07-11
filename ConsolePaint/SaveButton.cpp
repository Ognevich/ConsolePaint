#include "SaveButton.h"


SaveButton::SaveButton(int y) : UIButton("Save", y, OnClickActions::SAVE){}

OnClickActions SaveButton::onClick()
{
	std::cout << "Your data is saved" << std::endl;

	return OnClickActions::SAVE;
}

