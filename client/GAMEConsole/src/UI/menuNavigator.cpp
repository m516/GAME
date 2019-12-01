#include "menuNavigator.h"

//Initializes the navigator
MenuNavigator::MenuNavigator() 
{
    // Empty constructor
}

//Update the keys being pressed.
void MenuNavigator::poll() 
{
	if (keyboard_enabled) 
    {
		for (int i = 0; i < num_states; i++) 
        {
			if (sf::Keyboard::isKeyPressed(control_key[i])) 
            {
				current_control = (CONTROL)i;

				if (*control_status[i] == Status::UP || *control_status[i] == Status::RELEASED) 
                    *control_status[i] = Status::PRESSED;
				else if (*control_status[i] == Status::PRESSED) 
                    *control_status[i] = Status::DOWN;
			}
			else 
            {
				if (*control_status[i] == Status::DOWN || *control_status[i] == STATUS::PRESSED) 
                    *control_status[i] = Status::RELEASED;
				else if (*control_status[i] == Status::RELEASED) 
                    *control_status[i] = Status::UP;
			}
		}

		/*
		//enter
		if (sf::Keyboard::isKeyPressed(keyEnter)) 
        {
			current_control = Control::ENTER;
			if (enter == Status::UP || enter == Status::RELEASED) 
                enter = Status::PRESSED;
			else if (enter == Status::PRESSED) 
                enter = Status::DOWN;
		}
		else 
        {
			if (enter == Status::DOWN || enter == STATUS::PRESSED) 
                enter = Status::RELEASED;
			else if (enter == Status::RELEASED) 
                enter = Status::UP;
		}

		//exit
		if (sf::Keyboard::isKeyPressed(keyExit)) 
        {
			current_control = Control::EXIT;
			if (exit == Status::UP) 
                exit = Status::PRESSED;
			else if (exit == Status::PRESSED) 
                exit = Status::DOWN;
		}
		else 
        {
			if (exit == Status::DOWN || exit == STATUS::PRESSED) 
                exit = Status::RELEASED;
			else if (exit == Status::RELEASED)
                 exit = Status::UP;
		}

		//up
		if (sf::Keyboard::isKeyPressed(keyUp)) 
        {
			current_control = Control::UP;
			if (up == Status::UP) 
                up = Status::PRESSED;
			else if (up == Status::PRESSED) 
                up = Status::DOWN;
		}
		else 
        {
			if (up == Status::DOWN) 
                up = Status::RELEASED;
			else if (up == Status::RELEASED)
                up = Status::UP;
		}

		//down
		if (sf::Keyboard::isKeyPressed(keyDown)) 
        {
			current_control = Control::DOWN;
			if (down == Status::UP) 
                down = Status::PRESSED;
			else if (down == Status::PRESSED) 
                down = Status::DOWN;
		}
		else 
        {
			if (down == Status::DOWN) 
                down = Status::RELEASED;
			else if (down == Status::RELEASED) 
                down = Status::UP;
		}

		//left
		if (sf::Keyboard::isKeyPressed(keyLeft)) 
        {
			current_control = Control::LEFT;
			if (left == Status::UP) 
                left = Status::PRESSED;
			else if (left == Status::PRESSED) 
                left = Status::DOWN;
		}
		else 
        {
			if (left == Status::DOWN) 
                left = Status::RELEASED;
			else if (left == Status::RELEASED) 
                left = Status::UP;
		}

		//right
		if (sf::Keyboard::isKeyPressed(keyRight)) 
        {
			current_control = Control::RIGHT;
			if (right == Status::UP) 
                right = Status::PRESSED;
			else if (right == Status::PRESSED) 
                right = Status::DOWN;
		}
		else 
        {
			if (right == Status::DOWN) 
                right = Status::RELEASED;
			else if (right == Status::RELEASED) 
                right = Status::UP;
		}
		*/
	}
	else 
    {
		enter = Status::UP;
		exit = Status::UP;
		up = Status::UP;
		down = Status::UP;
		left = Status::UP;
		right = Status::UP;
	}
}

/**
 * Bind a key to a character on the keyboard.
 * Defaults to WASD controls
 */
void MenuNavigator::setKey(Control keyToSet, sf::Keyboard::Key value) 
{
	control_key[(int)keyToSet] = value;
}