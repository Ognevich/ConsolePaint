#include "MouseControl.h"

MouseHandler::MouseHandler() {
	hInput = GetStdHandle(STD_INPUT_HANDLE);
	SetConsoleMode(hInput, ENABLE_EXTENDED_FLAGS | ENABLE_MOUSE_INPUT);
}


bool MouseHandler::pollMouseEvent()
{
	ReadConsoleInput(hInput, &inputRecord, 2, &events);
	return inputRecord.EventType == MOUSE_EVENT;
}

bool MouseHandler::isLeftClick() const
{
	return inputRecord.Event.MouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED;
}

bool MouseHandler::isMouseMoved() const
{
    return inputRecord.Event.MouseEvent.dwEventFlags == MOUSE_MOVED;
}

COORD MouseHandler::getMousePosition() const
{
	return inputRecord.Event.MouseEvent.dwMousePosition;
}

