#ifndef CLEAR_SCREEN_H
#define CLEAR_SCREEN_H
#include <Windows.h>
#include <iostream>
#include "Defines.h"

class ClearScreen {
public:
    ClearScreen();
    void clearScreenMethod() const;
    void clearGameScreen() const;
    void setCursorPos(COORD uiPos);
    void setStringLine();
    void clearButtonInfo();

};

#endif