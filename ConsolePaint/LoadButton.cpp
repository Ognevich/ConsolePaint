#include "LoadButton.h"


LoadButton::LoadButton(int y) : UIButton("Load", y, OnClickActions::LOAD){}

OnClickActions LoadButton::onClick()
{
	return OnClickActions::LOAD;
}
