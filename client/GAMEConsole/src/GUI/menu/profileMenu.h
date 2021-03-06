#pragma once

#include "../lockingElement.h"
#include <string>
#include <SFML/Network.hpp>

class ProfileMenu : public LockingElement
{
    public:
        /** Menu for user profiles */
        ProfileMenu(sf::RenderWindow* window, Theme* theme, int user_id);
        ~ProfileMenu();
        void render(); // Inherits from GUIElement

    private:
		sf::Http http;
        sf::Text username = sf::Text();
        sf::Text usernameLabel = sf::Text();
        sf::Text userID = sf::Text();
        sf::Text userIDLabel = sf::Text();
        sf::Text level = sf::Text();
        sf::Text friends = sf::Text();
        sf::Text friendsLabel = sf::Text();
        sf::Text games = sf::Text();
        sf::Text gamesLabel = sf::Text();
        sf::Text playTime = sf::Text();

        sf::RectangleShape levelSquare = sf::RectangleShape(sf::Vector2f(2, 2));
};