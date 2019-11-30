#pragma once

#include "../lockingElement.h"
#include <SFML/Network.hpp>

class StatMenu : public LockingElement
{
    public:
        StatMenu(sf::RenderWindow* window, Theme* theme);
        ~StatMenu();

        //Inherited from GUIElement
        void render();

    private:
        sf::Http http;
        sf::Text* username = 0;
        sf::Text* wins = 0;
        sf::Text* losses = 0;
        sf::Text* level = 0;
};