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
				map.addPixel(pos.Y, pos.X);
				map.drawScreen();
				//callTask(panel.getActiveAction(), panel);
				panel.drawUI();
			}
			else if (mouse.isMouseMoved()) {

				panel.drawUI(pos.X, pos.Y);
			}
			
		}

	}
}


//void AppControler::callTask(OnClickActions activeAction, UiControler& panel)
//{
//    DBG("callTask called with activeAction = " << static_cast<int>(activeAction));
//
//    switch (activeAction)
//    {
//    case OnClickActions::NONE:
//        DBG("Action: NONE — нічого не робимо\n\n");
//        break;
//
//    case OnClickActions::SAVE:
//    {
//        std::string currentPath = fileControl.getFilePath();
//
//        if (currentPath.empty()) {
//            DBG("Помилка: file_path порожній, файл не буде збережено!");
//        }
//        else {
//            fileControl.createFile();
//        }
//        panel.setAction(OnClickActions::NONE);
//        break;
//    }
//
//    case OnClickActions::LOAD:
//        DBG("Action: LOAD");
//        panel.setAction(OnClickActions::NONE);
//        break;
//
//    case OnClickActions::CLEAR:
//        DBG("Action: CLEAR — очищуємо мапу");
//        map.createScreen();
//        panel.setAction(OnClickActions::NONE);
//        break;
//
//    default:
//        DBG("Action: НЕВІДОМИЙ (" << static_cast<int>(activeAction) << ")");
//        break;
//    }
//}
