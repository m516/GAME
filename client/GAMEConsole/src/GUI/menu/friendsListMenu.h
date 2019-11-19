#pragma once

#include "../lockingElement.h"

class FriendsListMenu : public LockingElement
{
    public:
        FriendsListMenu(sf::RenderWindow* window, Theme* theme);
        ~FriendsListMenu();
        void render();

    private:
};