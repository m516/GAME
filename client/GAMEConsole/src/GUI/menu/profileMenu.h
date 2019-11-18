#pragma once

#include "../lockingElement.h"


class ProfileMenu : public LockingElement
{
    public:
        /** Menu for user profiles */
        ProfileMenu(sf::RenderWindow* window, Theme* theme);
        ~ProfileMenu();
        void render(); // Inherits from GUIElement

    private:
        sf::Text title = sf::Text();

    protected:
};