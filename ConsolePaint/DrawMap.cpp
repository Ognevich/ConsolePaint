#include "DrawMap.h"


Map::Map(int h, int w) : height(h), width(w), screen(height, std::vector<char>(width, ' ')) {
    drawTypeAction = DrawTypeAction::CIRCLE;
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
        
        char symbol = ChooseDrawTypeSymbol();
        
        if (symbol != 'N')
            screen[y][x] = symbol;
        else {
            for (int dy = -1; dy <= 1; ++dy) {
                for (int dx = -1; dx <= 1; ++dx) {
                    screen[y + dy][x + dx] = ' ';
                }
            }
        }
    
    }
}

std::string Map::getVectorToStringScreen()
{
    std::string currentMap;

    for (int i = 0; i < screen.size(); i++) {
        for (char j : screen[i]) {
            currentMap += j;
        }
        currentMap += "\n";
    }

    return currentMap;
}

void Map::setStringToVectorScreen(std::string loadScreen)
{
    std::vector<std::vector<char>> screen;
    std::vector<char> currentRow;

    for (char ch : loadScreen) {
        if (ch == '\0')
            ch = ' ';
        
        if (ch == '\n') {
            screen.push_back(currentRow);
            currentRow.clear();
        }
        else {
            currentRow.push_back(ch);
        }
    }

    if (!currentRow.empty()) {
        screen.push_back(currentRow);
    }

    this->screen = screen;
}

void Map::setDrawType(DrawTypeAction drawTypeAction)
{
    this->drawTypeAction = drawTypeAction;
}

char Map::ChooseDrawTypeSymbol()
{
    switch (drawTypeAction)
    {
    case DrawTypeAction::CIRCLE:
        return 'o';
    case DrawTypeAction::ASTERICS:
        return '*';
    case DrawTypeAction::ERASER:
        return ' ';
    case DrawTypeAction::DOUBLE_ERASER:
        return 'N';
    default:
        break;
    }
}






