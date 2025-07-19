#include "SaveButton.h"


SaveButton::SaveButton(int y) : UIButton("Save", y, OnClickActions::SAVE){}

OnClickActions SaveButton::onClick()
{
	return OnClickActions::SAVE;
}

