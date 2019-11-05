#pragma once

#include <SFML/Window/Keyboard.hpp>

#include "controller.h"

class KeyboardController :public Controller {
public:

	KeyboardController();

	void update();

	//Bind a key to a character on the keyboard.
	//Default WASD controls
	void setKey(Control controlToSet, sf::Keyboard::Key key);

	//Current control
	Control current_control = Control::NONE;

private:

	//Key bindings for each control
	sf::Keyboard::Key keyUp = sf::Keyboard::W;
	sf::Keyboard::Key keyDown = sf::Keyboard::S;
	sf::Keyboard::Key keyLeft = sf::Keyboard::A;
	sf::Keyboard::Key keyRight = sf::Keyboard::D;
	sf::Keyboard::Key keyEnter = sf::Keyboard::Return;
	sf::Keyboard::Key keyExit = sf::Keyboard::Escape;
};