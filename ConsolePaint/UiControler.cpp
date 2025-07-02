#include "UIControler.h"

UiControler::UiControler(int xOffset) : panelXoffset(xOffset) {
	buttons.push_back(new SaveButton(0));
	buttons.push_back(new LoadButton(8));
	buttons.push_back(new ClearButton(16));
}

UiControler::~UiControler() {
	for (auto button : buttons) {
		delete button;
	}
}

OnClickActions UiControler::getActiveAction()
{
	return activeAction;
}


void UiControler::drawUI() {

	std::cout << "\n";
	for (const auto& btn : buttons) {
		
		std::cout << "[" << btn->getLabel() << "]  ";

	}
	std::cout << "\n";

	
}

void UiControler::clickDetection(int mouseX, int mouseY)
{
	if (mouseY < panelXoffset) return;

	for (auto& btn : buttons) {
		int start = btn->getX();
		int end = start + btn->getLabel().size() + 1;

		if (mouseX >= start && mouseX <= end) {
			activeAction = btn->onClick();
			break;
		}
	}
}

void UiControler::setAction(OnClickActions new_action)
{
	activeAction = new_action;
}
