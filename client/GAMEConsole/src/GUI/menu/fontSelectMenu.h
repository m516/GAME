#pragma once

#include "../lockingElement.h"
#include "components/menuPane.h"

class FontSelectMenu : public LockingElement
{
    public:
        FontSelectMenu(sf::RenderWindow* window, Theme* theme);
        ~FontSelectMenu();
        void render();

    private:
        sf::Text title = sf::Text();
        MenuPane* fontPane;

        void setFont(int fontIndex);
};