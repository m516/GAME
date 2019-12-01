#pragma once

#include "..//sprite.h"

class Controller 
{
    public:
        //Virtual destructor
        virtual ~Controller();
        virtual void enable();
        virtual void disable();
        bool is_enabled();

        //Sets whether or not the controller does anything on update
        bool enabled = false;

        //Update the keys being pressed.
        virtual int update() = 0;
};

