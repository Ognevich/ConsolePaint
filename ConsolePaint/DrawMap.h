#ifndef DRAW_MAP_H
#define DRAW_MAP_H
#include <iostream>
#include "ClearScreen.h"
#include <vector>
#include "Enumarators.h"

class Map {

public:
	Map(int height, int width);

	int getHeight();
	int getWidth();

	void createScreen();
	void drawScreen();
	void addPixel(const int height, const int width);

	std::string getVectorToStringScreen();
	void setStringToVectorScreen(std::string loadScreen);

	void setDrawType(DrawTypeAction drawTypeAction);
	
	char ChooseDrawTypeSymbol();
	


private:

	int height;
	int width;

	std::vector<std::vector<char>> screen;

	ClearScreen clearScreen;
	DrawTypeAction drawTypeAction;
};


#endif
