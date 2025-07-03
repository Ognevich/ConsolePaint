#include "AppControler.h"

AppControler::AppControler(int height, int width) : map(height, width)
{
}

void AppControler::Run()
{
	map.drawScreen();
	UiControler panel;
	ClearScreen clr;

	panel.drawUI();

	while (true) {
		if (mouse.pollMouseEvent()) {
			COORD pos = mouse.getMousePosition();

			if (mouse.isLeftClick()) {
				panel.clickDetection(pos.X, pos.Y);
				callTask(panel.getActiveAction(), panel);
				map.drawScreen();
				map.addPixel(pos.Y, pos.X);
				panel.drawUI();
			}
			else if (mouse.isMouseMoved()) {

				panel.drawUI(pos.X, pos.Y);
			}
			
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
