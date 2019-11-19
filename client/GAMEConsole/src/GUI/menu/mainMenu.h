#pragma once

#include "../lockingElement.h"
#include "../../games/pong/pong.h"
#include "../../application.h"
#include "components/menuPane.h"
#include "gameSelectionMenu.h"
#include "profileMenu.h"

class MainMenu : public LockingElement
{
    public:
        MainMenu(sf::RenderWindow* window, Theme* theme);
        ~MainMenu();

        void render(); // Inherited from GUIElement

    private:
        MenuPane* menu = 0;
        sf::Text* title = 0;

        /** Pong instance (temporary)*/
        Pong* pong_game = 0;

        /** Minimum frame time (essentially highest fps possible)*/
        const sf::Time frame_period = sf::milliseconds(10.f);

        //private menu-specific functions
        void play();
        void profile();
        void friendsList();
        void party();
        void settings();
};

