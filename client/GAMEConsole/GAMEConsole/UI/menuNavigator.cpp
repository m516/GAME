#include "menuNavigator.h"

//Initializes the navigator
MenuNavigator::MenuNavigator() {

}
//Update the keys being pressed.
void MenuNavigator::poll() {
	//enter
	if (sf::Keyboard::isKeyPressed(_keyEnter)) {
		current_control = Control::ENTER;
		if (enter == Status::UP) enter = Status::PRESSED;
		else if (enter == Status::PRESSED) enter = Status::DOWN;
	}
	else {
		if (enter == Status::DOWN) enter = Status::RELEASED;
		else if (enter == Status::RELEASED) enter = Status::UP;
	}
	//exit
	if (sf::Keyboard::isKeyPressed(_keyExit)) {
		current_control = Control::EXIT;
		if (exit == Status::UP) exit = Status::PRESSED;
		else if (exit == Status::PRESSED) exit = Status::DOWN;
	}
	else {
		if (exit == Status::DOWN) exit = Status::RELEASED;
		else if (exit == Status::RELEASED) exit = Status::UP;
	}
	//up
	if (sf::Keyboard::isKeyPressed(_keyUp)) {
		current_control = Control::UP;
		if (up == Status::UP) up = Status::PRESSED;
		else if (up == Status::PRESSED) up = Status::DOWN;
	}
	else {
		if (up == Status::DOWN) up = Status::RELEASED;
		else if (up == Status::RELEASED) up = Status::UP;
	}
	//down
	if (sf::Keyboard::isKeyPressed(_keyDown)) {
		current_control = Control::DOWN;
		if (down == Status::UP) down = Status::PRESSED;
		else if (down == Status::PRESSED) down = Status::DOWN;
	}
	else {
		if (down == Status::DOWN) down = Status::RELEASED;
		else if (down == Status::RELEASED) down = Status::UP;
	}
	//left
	if (sf::Keyboard::isKeyPressed(_keyLeft)) {
		current_control = Control::LEFT;
		if (left == Status::UP) left = Status::PRESSED;
		else if (left == Status::PRESSED) left = Status::DOWN;
	}
	else {
		if (left == Status::DOWN) left = Status::RELEASED;
		else if (left == Status::RELEASED) left = Status::UP;
	}
	//right
	if (sf::Keyboard::isKeyPressed(_keyRight)) {
		current_control = Control::RIGHT;
		if (right == Status::UP) right = Status::PRESSED;
		else if (right == Status::PRESSED) right = Status::DOWN;
	}
	else {
		if (right == Status::DOWN) right = Status::RELEASED;
		else if (right == Status::RELEASED) right = Status::UP;
	}
}


//Bind a key to a character on the keyboard.
//Default WASD controls
void MenuNavigator::setKey(Control keyToSet, sf::Keyboard::Key value) {
	switch (keyToSet) {
	case Control::ENTER:
		_keyEnter = value;
		break;
	case Control::EXIT:
		_keyEnter = value;
		break;
	case Control::UP:
		_keyEnter = value;
		break;
	case Control::DOWN:
		_keyEnter = value;
		break;
	case Control::LEFT:
		_keyEnter = value;
		break;
	case Control::RIGHT:
		_keyEnter = value;
		break;
	default:
		break;
		//Do nothing
	}
}