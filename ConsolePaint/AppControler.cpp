#include "AppControler.h"

AppControler::AppControler(int height, int width) : map(height, width), fileControler(FILE_PATH)
{
}

void AppControler::callTask(UiControler& panel)
{

	OnClickActions current_action = panel.getActiveAction();

	switch (current_action)
	{
	case OnClickActions::NONE:
		break;
	case OnClickActions::SAVE:
	{
		fileControler.createFile(map.getVectorToStringScreen());
		panel.setAction(OnClickActions::NONE);
		break;
	}
	case OnClickActions::LOAD:
	{
		std::string fileData = fileControler.promptFilenameInput();
		if (fileData.empty()) {
			panel.setAction(OnClickActions::NONE);
			return;
		}
		map.setStringToVectorScreen(fileData);


		panel.setAction(OnClickActions::NONE);
		break;
	}
	case OnClickActions::CLEAR:
	{
		map.createScreen();
		panel.setAction(OnClickActions::NONE);
		break;
	}
	case OnClickActions::CIRCLE_B:
	{
		map.setDrawType(DrawTypeAction::CIRCLE);
		break;
	}
	case OnClickActions::ASTERICS_B:
	{
		map.setDrawType(DrawTypeAction::ASTERICS);
		break;
	}
	case OnClickActions::ERASER_B:
	{
		map.setDrawType(DrawTypeAction::ERASER);
		break;
	}
	case OnClickActions::DOUBLE_ERASER_B:
	{
		map.setDrawType(DrawTypeAction::DOUBLE_ERASER);
		break;
	}
	default:
		break;
	}

}

void AppControler::Run()
{
	map.drawScreen();
	ClearScreen clr;
	UiControler panel;

	panel.drawUI();

	while (true) {

		// CLEAR INFO BELOW UI
		clr.clearButtonInfo();

		if (mouse.pollMouseEvent()) {
			COORD pos = mouse.getMousePosition();

			if (mouse.isLeftClick()) {
				panel.clickDetection(pos.X, pos.Y);
				callTask(panel);
				map.addPixel(pos.Y, pos.X);
				map.drawScreen();
				panel.drawUI();

			}
			else if (mouse.isMouseMoved()) {
				panel.drawUI(pos.X, pos.Y);
			}
			
		}

	}
}
