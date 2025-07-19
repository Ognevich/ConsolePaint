#include "ClearScreen.h"

ClearScreen::ClearScreen() {}

void ClearScreen::clearScreenMethod() const {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD count;
    COORD homeCoords = { 0, 0 };

    if (hConsole == INVALID_HANDLE_VALUE) return;
    if (!GetConsoleScreenBufferInfo(hConsole, &csbi)) return;

    int consoleSize = csbi.dwSize.X * csbi.dwSize.Y; 

    if (!FillConsoleOutputCharacter(hConsole, (TCHAR)' ', consoleSize, homeCoords, &count)) return;
    if (!FillConsoleOutputAttribute(hConsole, csbi.wAttributes, consoleSize, homeCoords, &count)) return;

    SetConsoleCursorPosition(hConsole, homeCoords);
}
void ClearScreen::clearGameScreen() const {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(hConsole, &cursorInfo);

    COORD cursorPosition;
    cursorPosition.X = 0;
    cursorPosition.Y = 0;
    SetConsoleCursorPosition(hConsole, cursorPosition);
}

void ClearScreen::setCursorPos(COORD uiPos)
{
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), uiPos);
}

void ClearScreen::setStringLine()
{
    std::cout << std::string(150, ' ');
}

void ClearScreen::clearButtonInfo()
{
    COORD uipos = { 0, PANEL_Y_OFFSET + 2 };
    setStringLine();
    setCursorPos(uipos);
}

