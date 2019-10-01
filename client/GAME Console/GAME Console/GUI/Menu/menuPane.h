#pragma once


#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "menuItem.h"
#include "../../UI/menuNavigator.h"

//Shortcut for writing vectors of MenuItems
typedef std::vector<MenuItem> MenuItem_vec_t;

using namespace sf;

class MenuPane {
public:
	/**
	Constructs a new MenuPane
	*/
	MenuPane(int initial_size);

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
	Set the size of the menu rendered on the screen
	*/
	void setSize(float x, float y);
	void setSize(sf::Vector2f& new_size);
	/**
	Get the size of the menu rendered on the screen
	*/
	sf::Vector2f getSize();

	/**
	Set the size of the menu rendered on the screen
	*/
	void setPosition(float x, float y);
	void setPosition(sf::Vector2f& new_position);

	/**
	Get the size of the menu rendered on the screen
	*/
	sf::Vector2f getPosition();

	/**
	Updates the menu
	*/
	void update();

	/**
	renders the item as a box with text in it
	@param target the window onto which this MenuItem renders
	*/
	void render(sf::RenderWindow* target);
	
private:
	/**
	A collection of Items
	Contained as std::vector<MenuItem>
	*/
	MenuItem_vec_t items;

	/**
	The position of the menu
	*/
	Vector2f position;

	/**
	The size of the menu
	*/
	Vector2f size;

	/**
	Updates how each item renders
	*/
	void updateItems();
};
