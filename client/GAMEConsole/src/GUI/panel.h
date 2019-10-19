#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "guiElement.h"
#include "../UI/menuNavigator.h"

//Shortcut for writing vectors of MenuItems
typedef std::vector<GUIElement> GUIElement_vec_t;

class Panel : public GUIElement
{

public:
	/**
	Constructs a new MenuPane
	*/
	Panel(int initial_size);

	/**
	Adds an item to the list of items to display
	*/
	void addItem(Panel item);


	/**
	The selected item's index
	*/
	unsigned int selected = 0;


	/**
	The MenuNavigator object controlling the menu
	*/
	MenuNavigator paneNavigator;


	/**
	Updates the panel
	*/
	void update();


	/**
	renders the item onto a RenderWindow
	@param target the window onto which this MenuItem renders
	*/
	void render(sf::RenderTarget* target);

	/**
	Updates how the GUI element looks
	Called after each time the position or size is reset
	*/
	void updateLook();

	//Overridden from GUIElement
	/**
	Set the size of this object rendered on the screen
	*/
	void setSize(float x, float y);
	void setSize(sf::Vector2f& new_size);

	/**
	Set the position of this object rendered on the screen
	*/
	void setPosition(float x, float y);
	void setPosition(sf::Vector2f& new_position);


private:
	/**
	A collection of Items
	Contained as std::vector<MenuItem>
	*/
	GUIElement_vec_t items;

	/**
	Updates how each item renders
	*/
	void updateItems();
};
