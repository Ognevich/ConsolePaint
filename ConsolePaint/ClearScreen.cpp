#include "ClearScreen.h"
#include <Windows.h>

ClearScreen::ClearScreen() {}

void ClearScreen::clearScreenMethod() const {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD count;
    COORD homeCoords = { 0, 0 };

    if (hConsole == INVALID_HANDLE_VALUE) return;

    if (!GetConsoleScreenBufferInfo(hConsole, &csbi)) return;

    int width = csbi.dwSize.X;
    int height = csbi.dwSize.Y / 2;

    if (!FillConsoleOutputCharacter(hConsole, (TCHAR)' ', width * height, homeCoords, &count)) return;
    if (!FillConsoleOutputAttribute(hConsole, csbi.wAttributes, width * height, homeCoords, &count)) return;

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