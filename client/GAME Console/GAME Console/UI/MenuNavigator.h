#pragma once
#ifndef MENU_NAVIGATOR_H
#define MENU_NAVIGATOR_H
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
class MenuNavigator {
public:
	//Initializes the navigator
	MenuNavigator();
	//Update the keys being pressed.
	void poll();
	//Bind a key to a character on the keyboard.
	//Default WASD controls
	void setKey(control_t controlToSet, char key);


	//Controls
	int up = 0;
	int down = 0;
	int left = 0;
	int right = 0;
	int enter = 0;
	int exit = 0;

	//MenuNavigator updates the controls only if 
	//keyboard_enabled is true
	int keyboard_enabled = 1;


	//The list of controls that go into a menu
	typedef enum CONTROL
	{
		UP,
		DOWN,
		LEFT,
		RIGHT,
		ENTER,
		EXIT
	} control_t;

private:
	//Key bindings for each control
	char _keyUp    = 'w';
	char _keyDown  = 's';
	char _keyLeft  = 'a';
	char _keyRight = 'd';
	char _keyEnter = '\n';
	char _keyExit  = '\t';
};

#endif