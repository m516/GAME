#pragma once

#include "../../lockingElement.h"
#include "../../guiElement.h"
#include <functional>
#include <SFML/Window/Keyboard.hpp>

class Dialog : public LockingElement
{
public:
	/**
	Initializes the Dialog
	*/
	Dialog(GUIElement* parent, const std::string message);

	/**
	Deconstructor for Dialog
	*/
	~Dialog();

	/**
	renders the item
	*/
	void render();

	/**
	Creates a new Dialog and displays it.

	Equivalent to creating a new Dialog instance and calling its
	lockRender() function
	*/
	static void show(GUIElement* parent, const std::string message);

private:
	GUIElement* parent;
	sf::Text* label;
	int enter_state = -1;
};

