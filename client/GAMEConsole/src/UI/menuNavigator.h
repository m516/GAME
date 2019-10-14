#pragma once
#ifndef MENU_NAVIGATOR_H
#define MENU_NAVIGATOR_H
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
class MenuNavigator {
public:

	//The list of controls that go into a menu
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

	typedef enum class STATUS{
		UP,
		PRESSED,
		DOWN,
		RELEASED,
		DISABLED
	} Status;


	//Initializes the navigator
	MenuNavigator();
	//Update the keys being pressed.
	void poll();
	//Bind a key to a character on the keyboard.
	//Default WASD controls
	void setKey(Control controlToSet, sf::Keyboard::Key key);


	//Controls
	Status up = Status::UP;
	Status down = Status::UP;
	Status left = Status::UP;
	Status right = Status::UP;
	Status enter = Status::UP;
	Status exit = Status::UP;
	Control current_control = Control::NONE;

	//MenuNavigator updates the controls only if 
	//keyboard_enabled is true
	int keyboard_enabled = 1;

private:
	//Key bindings for each control
	sf::Keyboard::Key _keyUp    = sf::Keyboard::W;
	sf::Keyboard::Key _keyDown  = sf::Keyboard::S;
	sf::Keyboard::Key _keyLeft  = sf::Keyboard::A;
	sf::Keyboard::Key _keyRight = sf::Keyboard::D;
	sf::Keyboard::Key _keyEnter = sf::Keyboard::Return;
	sf::Keyboard::Key _keyExit = sf::Keyboard::Escape;
};

#endif