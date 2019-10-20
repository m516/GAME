#pragma once


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
	sf::Keyboard::Key keyUp    = sf::Keyboard::W;
	sf::Keyboard::Key keyDown  = sf::Keyboard::S;
	sf::Keyboard::Key keyLeft  = sf::Keyboard::A;
	sf::Keyboard::Key keyRight = sf::Keyboard::D;
	sf::Keyboard::Key keyEnter = sf::Keyboard::Return;
	sf::Keyboard::Key keyExit = sf::Keyboard::Escape;
};

