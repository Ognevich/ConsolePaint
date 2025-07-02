#ifndef MOUSE_CONTROLE_H
#define MOUSE_CONTROLE_H
#include <windows.h>

class MouseHandler {
public:
    MouseHandler();
    bool pollMouseEvent(); 
    bool isLeftClick() const;
    bool isMouseMoved() const;

    COORD getMousePosition() const;



private:
    HANDLE hInput;
    INPUT_RECORD inputRecord{};
    DWORD events = 0;
};

#endif