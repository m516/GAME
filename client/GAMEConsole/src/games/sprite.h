#pragma once
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

#include "game.h"

class Sprite 
{
    public:
        virtual ~Sprite();

        sf::Vector2f position;
        sf::Vector2f velocity;
        sf::Vector2f acceleration;
        sf::Vector2f size;
        sf::Vector2f screen_position;
        sf::Vector2f screen_size;

        bool enable_motion = false;

        virtual void update();
        virtual void render() = 0;

    protected:
        /**
        A reference to the game object
        */
        Game* game;

        /**
        Updates screen_size and screen_position based on position, size, camera_position and camera_size
        */
        void updateScreenDimensions();
};