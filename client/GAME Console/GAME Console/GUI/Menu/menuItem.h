#pragma once

#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "../theme.h"

class MenuItem {
public:
	/**
	Initializes the MenuItem with the things it needs to have.
	@param text the text to display on the menu
	@param function the function to call when the menu item is activated
	*/
	MenuItem(Theme *theme, const std::string& text, int (*function_when_pressed) ());
	/**
	Deconstructor for MenuItem
	*/
	~MenuItem();
	/**
	true if selected, false if not selected
	*/
	int selected = 0;
	/**
	true if pressed, false if otherwise
	*/
	int pressed = 0;
	/**
	function to call when this menu item is pressed
	*/
	int (*pressed_function) ();
	/**
	Sets the text to display
	*/
	void setText(const std::string& description_text);


	//Display-oriented code
	/**
	Set the size of the menuItem rendered on the screen
	*/
	void setSize(float x, float y);
	void setSize(sf::Vector2f &new_size);
	/**
	Get the size of the menuItem rendered on the screen
	*/
	sf::Vector2f getSize();

	/**
	Set the size of the menuItem rendered on the screen
	*/
	void setPosition(float x, float y);
	void setPosition(sf::Vector2f &new_position);

	/**
	Get the size of the menuItem rendered on the screen
	*/
	sf::Vector2f getPosition();

	/**
	renders the item as a box with text in it
	@param target the window onto which this MenuItem renders
	*/
	void render(sf::RenderTarget*target);
private:
	/**
	The size of the menu item in pixels
	*/
	sf::Vector2f size;
	/**
	The position of the menu item in pixels
	*/
	sf::Vector2f position;
	//string of text to display
	sf::Text label;
	//Instance of rectangle border
	sf::RectangleShape border;
	//Reference to current theme
	Theme* theme;
};
