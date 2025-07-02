#include "UIButton.h"

UIButton::UIButton(std::string current_label, int current_x, OnClickActions new_action)
    : label(current_label), x(current_x), action(new_action){}

std::string UIButton::getLabel()
{
    return label;
}

int UIButton::getX() {
    return x;
}

OnClickActions UIButton::getAction()
{
    return action;
}
