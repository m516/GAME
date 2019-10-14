#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "guiElement.h"

class Panel : public GUIElement
{
    public:
        int test = 0;
        void TestFunction();
};