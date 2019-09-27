#include "MenuNavigator.h"

//Initializes the navigator
MenuNavigator::MenuNavigator() {

}
//Update the keys being pressed.
void MenuNavigator::poll() {
	clear();
	if (sf::Keyboard::isKeyPressed(_keyEnter)) {
		enter = 1;
		current_control = Control::NONE;
	}
	//TODO finish for up, down, left, right, and exit
}

void MenuNavigator::clear() {
	up = 0;
	down = 0;
	left = 0;
	right = 0;
	enter = 0;
	exit = 0;
	current_control = Control::NONE;
}

//Bind a key to a character on the keyboard.
//Default WASD controls
void MenuNavigator::setKey(Control keyToSet, sf::Keyboard::Key value) {
	switch (keyToSet) {
	case Control::ENTER:
		_keyEnter = value;
		break;
		//TODO add cases for up, down, left, right, and exit
	}
}