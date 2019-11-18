#pragma once


#include <SFML/Window.hpp>
#include <SFML/System.hpp>
class MenuNavigator {
public:


	//The list of controls that go into a menu
	typedef enum class CONTROL
	{
		UP = 0,
		DOWN = 1,
		LEFT = 2,
		RIGHT = 3,
		ENTER = 4,
		EXIT = 5,
		NONE = 6
	} Control;

	typedef enum class STATUS{
		UP = 0,
		PRESSED = 1,
		DOWN = 2,
		RELEASED = 3,
		DISABLED = 4
	} Status;




	//Initializes the navigator
	MenuNavigator();
	//Update the keys being pressed.
	void poll();
	//Bind a key to a character on the keyboard.
	//Default WASD controls
	void setKey(Control controlToSet, sf::Keyboard::Key key);


	//Controls
	Status up = Status::DOWN;
	Status down = Status::DOWN;
	Status left = Status::DOWN;
	Status right = Status::DOWN;
	Status enter = Status::DOWN;
	Status exit = Status::DOWN;
	Control current_control = Control::NONE;


	const int num_states = 6;

	//MenuNavigator updates the controls only if 
	//keyboard_enabled is true
	int keyboard_enabled = 1;

private:
	
	STATUS* control_status[6] = {
		&up,
		&down,
		&left,
		&right,
		&enter,
		&exit
	};
	
	sf::Keyboard::Key control_key[6] = {
		sf::Keyboard::W,
		sf::Keyboard::S,
		sf::Keyboard::A,
		sf::Keyboard::D,
		sf::Keyboard::Return,
		sf::Keyboard::Escape
	};
};

