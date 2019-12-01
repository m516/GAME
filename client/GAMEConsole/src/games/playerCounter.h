#pragma once

#include "../modules/network.h"
#include "../GUI/lockingElement.h"
#include <SFML/Graphics/Text.hpp>
#include "game.h"
#include "../modules/session.h"

/*This menu is made to call websocket op-codes that tell the server to create a new online game
or to join an existing one. Note that will only run preexisting games and WILL NOT create 
and configure new ones*/
class PlayerCounter : public LockingElement
{
    public:
        PlayerCounter(Game* game);
        ~PlayerCounter();

        void render();

        int getNumPlayers();
        bool isFull();

    private:
        int gameID;
        int expectedNumPlayers;
        sf::Text* gameIDLabel = 0;
        sf::Text* numJoinedLabel = 0;
        Game* game;

        // Counter for slow network refresh
        // (we don't need to ping the server 60 times per second)
        int counter = 0;
};

