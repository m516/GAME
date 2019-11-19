#pragma once

#include "../lockingElement.h"

class SettingsMenu : public LockingElement
{
    public:
        SettingsMenu(sf::RenderWindow* window, Theme* theme);
        ~SettingsMenu();
        void render();

    private:
};