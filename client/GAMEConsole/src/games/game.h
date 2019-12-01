#pragma once

#include <SFML/System/Vector2.hpp>
#include "../GUI/lockingElement.h"

class Game : public LockingElement 
{
    public:
        sf::Vector2f camera_location;
        float camera_scale;

        virtual void beginNetworkGame() = 0;
        virtual void beginOfflineGame() = 0;
        virtual void beginSpectateGame() = 0;
        /*Number of players that can play this game*/
        virtual int getNumPlayers() = 0;
        /*Unique index of type of game (so people don't join games with the wrong rules)*/
        virtual int getGameType() = 0;
        /*Unique index of the game played on the network*/
        int getGameID();
        void setGameID(int id);

        virtual std::string getName();

    protected:
        int gameID = -1;
};