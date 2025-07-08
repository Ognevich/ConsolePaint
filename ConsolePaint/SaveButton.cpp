#include "SaveButton.h"


SaveButton::SaveButton(int y) : UIButton("Save", y, OnClickActions::SAVE){}

OnClickActions SaveButton::onClick()
{
	FileControler fileControler(FILE_PATH);

	fileControler.createFile();
	std::cout << "Your data is saved" << std::endl;

	return OnClickActions::SAVE;
}

