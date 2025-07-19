#ifndef CLEAR_SCREEN_H
#define CLEAR_SCREEN_H

class ClearScreen {
public:
    ClearScreen();
    void clearScreenMethod() const;
    void clearGameScreen() const;
    void clearBelowLine(int lineY) const;
};

#endif