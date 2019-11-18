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
        sf::Text username = sf::Text();
        sf::Text level = sf::Text();
        sf::Text friends = sf::Text();
        sf::Text games = sf::Text();
        sf::Text playTime = sf::Text();

        sf::RectangleShape levelSquare = sf::RectangleShape(sf::Vector2f(2, 2));

    protected:
};