#pragma once

#include "../../sprite.h"
#include <SFML/Graphics/CircleShape.hpp>

class Ball : public Sprite 
{
    public:
        Ball(Game* game);

        //Inherited from Sprite class
        void update();
        void render();

    private:
        sf::CircleShape shape;
};