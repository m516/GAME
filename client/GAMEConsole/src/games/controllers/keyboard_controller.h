#pragma once

#include <SFML/Window/Keyboard.hpp>

#include "controller.h"

class KeyboardController : public Controller 
{
    public:
        KeyboardController();

        virtual int update();
        virtual void disable();

        //The list of controls
        typedef enum class CONTROL
        {
            UP,
            DOWN,
            LEFT,
            RIGHT,
            ENTER,
            EXIT,
            NONE
        } Control;

        typedef enum class STATUS 
        {
            UP,
            PRESSED,
            DOWN,
            RELEASED,
            DISABLED
        } Status;

        //Bind a key to a character on the keyboard.
        //Default WASD controls
        void setKey(Control controlToSet, sf::Keyboard::Key key);

    protected:
        //Key bindings for each control
        sf::Keyboard::Key keyUp = sf::Keyboard::W;
        sf::Keyboard::Key keyDown = sf::Keyboard::S;
        sf::Keyboard::Key keyLeft = sf::Keyboard::A;
        sf::Keyboard::Key keyRight = sf::Keyboard::D;
        sf::Keyboard::Key keyEnter = sf::Keyboard::Return;
        sf::Keyboard::Key keyExit = sf::Keyboard::Escape;

        //Controls
        Status up = Status::UP;
        Status down = Status::UP;
        Status left = Status::UP;
        Status right = Status::UP;
        Status enter = Status::UP;
        Status exit = Status::UP;
        Control current_control = Control::NONE;
};