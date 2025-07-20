#include "AstericsButton.h"


AstericsButton::AstericsButton(int y) : UIButton("aster", y, OnClickActions::ASTERICS_B)
{}

OnClickActions AstericsButton::onClick()
{
    return OnClickActions::ASTERICS_B;
}
