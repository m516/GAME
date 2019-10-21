#pragma once


#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "menuItem.h"
#include "../../UI/menuNavigator.h"
#include "../guiElement.h"

//Shortcut for writing vectors of MenuItems
typedef std::vector<MenuItem> MenuItem_vec_t;


class MenuPane : public GUIElement {
public:
	/**
	Constructs a new MenuPane
	*/
	MenuPane(int initial_size);
	/**
	 * Prevent seg faults by init with render target
	 */
	MenuPane(int initial_size, sf::RenderTarget* renderTarget);

	/**
	Adds an item to the list of items to display
	*/
	void addItem(MenuItem item);


	/**
	The selected item's index
	*/
	unsigned int selected = 0;


	/**
	The MenuNavigator object controlling the menu
	*/
	MenuNavigator menuNavigator;


	/**
	Updates the menu
	*/
	void update();


	/**
	renders the item onto a RenderWindow
	@param target the window onto which this MenuItem renders
	*/
	void render();

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
	MenuItem_vec_t items;
};
