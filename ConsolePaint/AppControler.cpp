#include "AppControler.h"

AppControler::AppControler(int height, int width) : map(height, width)
{
}

void AppControler::Run()
{
	map.drawScreen();
	UiControler panel(21);
	panel.drawUI();
	while (true) {
		if (mouse.pollMouseEvent() && mouse.isLeftClick()) {
			COORD pos = mouse.getMousePosition();

			panel.clickDetection(pos.X, pos.Y);
			callTask(panel.getActiveAction(), panel);
	

			map.addPixel(pos.Y, pos.X);
			map.drawScreen();

			panel.drawUI();

		}
	}
}


void AppControler::callTask(OnClickActions activeAction, UiControler& panel)
{
	switch (activeAction)
	{
	case OnClickActions::NONE:
		break;
	case OnClickActions::SAVE:
		std::cout << "Save";
		panel.setAction(OnClickActions::NONE);
		break;
	case OnClickActions::LOAD:
		std::cout << "Load";
		panel.setAction(OnClickActions::NONE);
		break;
	case OnClickActions::CLEAR:
		map.createScreen();
		panel.setAction(OnClickActions::NONE);
		break;
	default:
		break;
	}
}
