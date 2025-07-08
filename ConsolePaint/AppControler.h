#ifndef APP_CONTROLER_H
#define APP_CONTROLER_H
#include "MouseControl.h"
#include "DrawMap.h"
#include "UIControler.h"


class AppControler {

public:

	AppControler(int height, int width);


	//void callTask(OnClickActions activeAction, UiControler& panel);
	void Run();

private:

	Map map;
	MouseHandler mouse;


};

#endif 