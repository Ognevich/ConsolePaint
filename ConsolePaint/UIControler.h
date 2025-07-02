#ifndef UI_CONTROLER_H
#define UI_CONTROLER_H
#include "ClearButton.h"
#include "SaveButton.h"
#include "LoadButton.h"
#include <vector>
#include "iostream"


class UiControler {
public:

	UiControler(int xOffset);
	~UiControler();

	void drawUI();
	void clickDetection(int mouseX, int mouseY);
	void setAction(OnClickActions new_action);
	OnClickActions getActiveAction();
	

private:
	std::vector<UIButton*> buttons;
	int panelXoffset;
	OnClickActions activeAction = OnClickActions::NONE;
};

#endif 