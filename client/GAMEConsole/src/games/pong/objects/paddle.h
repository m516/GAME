#pragma once

#include "..//..//sprite.h"
#include "..//..//controllers/keyboard_controller.h"
#include <SFML/Graphics/RectangleShape.hpp>

class Paddle : public Sprite 
{
    public:
        Paddle(Game* game);
        ~Paddle();

        //Inherited from Sprite class
        void update();
        void render();

    private:
        sf::RectangleShape shape;
};