#ifndef UI_CONTROLER_H
#define UI_CONTROLER_H
#include "ClearButton.h"
#include "SaveButton.h"
#include "LoadButton.h"
#include <vector>
#include "iostream"
#include "Windows.h"

#define PANEL_Y_OFFSET 20 

class UiControler {
public:

	UiControler();
	~UiControler();

	void drawUI();
	void drawUI(int mouseX, int mouseY);
	void clickDetection(int mouseX, int mouseY);
	void setAction(OnClickActions new_action);
	OnClickActions getActiveAction();
	

private:
	std::vector<UIButton*> buttons;
	OnClickActions activeAction = OnClickActions::NONE;
};

#endif 