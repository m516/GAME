#pragma once

#include "../lockingElement.h"
#include "components/menuPane.h"

class SettingsMenu : public LockingElement
{
    public:
        SettingsMenu(sf::RenderWindow* window, Theme* theme);
        ~SettingsMenu();
        void render();

    private:
        sf::Text title = sf::Text();
        MenuPane* settingsItems;
};