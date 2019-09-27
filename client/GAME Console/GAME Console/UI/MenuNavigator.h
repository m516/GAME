#pragma once
#ifndef MENU_NAVIGATOR_H
#define MENU_NAVIGATOR_H
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
class MenuNavigator {
public:
	MenuNavigator();
	void poll();
	void setKey();

	int up = 0;
	int down = 0;
	int left = 0;
	int right = 0;
	int enter = 0;

	enum KEY
	{
		UP,
		DOWN,
		LEFT,
		RIGHT,
		ENTER
	};

private:
	char _keyUp    = 'w';
	char _keyDown  = 's';
	char _keyLeft  = 'a';
	char _keyRight = 'd';
	char _keyEnter = '\n';

	
};

#endif