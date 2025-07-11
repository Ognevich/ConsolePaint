#ifndef UI_CONTROLER_H
#define UI_CONTROLER_H

#include "UIButton.h"
#include "ClearButton.h"
#include "SaveButton.h"
#include "LoadButton.h"

#include <vector>
#include <memory>
#include <iostream>
#include <Windows.h>
#include "Defines.h"
#include "Enumarators.h"

class UiControler {
public:
    UiControler();

    // Заборонити копіювання
    UiControler(const UiControler&) = delete;
    UiControler& operator=(const UiControler&) = delete;

    void drawUI();
    void drawUI(int mouseX, int mouseY);
    void clickDetection(int mouseX, int mouseY);
    void setAction(OnClickActions new_action);
    OnClickActions getActiveAction();

private:
    std::vector<std::unique_ptr<UIButton>> buttons;
    OnClickActions activeAction = OnClickActions::NONE;
};

#endif