#pragma once

#include "../lockingElement.h"

class PartyMenu : public LockingElement
{
    public:
        PartyMenu(sf::RenderWindow* window, Theme* theme);
        ~PartyMenu();
        void render();

    private:
};