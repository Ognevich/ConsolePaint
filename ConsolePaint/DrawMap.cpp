#include "DrawMap.h"


Map::Map(int h, int w) : height(h), width(w), screen(height, std::vector<char>(width, ' ')) {
    createScreen();
}

int Map::getHeight()
{
	return height;
}

int Map::getWidth()
{
	return width;
}

void Map::createScreen()
{
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			screen[i][j] = ' ';
		}
	}
}

void Map::drawScreen() {
	clearScreen.clearGameScreen();
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1) {
                std::cout << "#";
            }
            else {
                std::cout << screen[i][j];
            }

        }
        std::cout << "\n";
    }
}

void Map::addPixel(const int y, const int x)
{
    if (y > 0 && y < height - 1 && x > 0 && x < width - 1) {
        screen[y][x] = 'o';
    }
}





