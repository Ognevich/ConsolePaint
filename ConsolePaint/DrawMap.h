#ifndef DRAW_MAP_H
#define DRAW_MAP_H
#include <iostream>
#include "ClearScreen.h"
#include <vector>

class Map {

public:
	Map(int height, int width);

	int getHeight();
	int getWidth();

	void createScreen();
	void drawScreen();
	void addPixel(const int height, const int width);


private:

	int height;
	int width;

	std::vector<std::vector<char>> screen;

	ClearScreen clearScreen;
};


#endif
