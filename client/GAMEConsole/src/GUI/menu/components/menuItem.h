#pragma once

#include <string>
#include <functional>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "../../theme.h"
#include "../../guiElement.h"


class MenuItem : public GUIElement{
public:
	/**
	Initializes the MenuItem with the things it needs to have.
	@param text the text to display on the menu
	@param function the function to call when the menu item is activated
	*/
	MenuItem(Theme *theme, const std::string& text, std::function<void()> pressed = 0);
	/**
	Deconstructor for MenuItem
	*/
	~MenuItem();
	/**
	true if pressed, false if otherwise
	*/
	bool pressed = false;
	/**
	Sets the text to display
	*/
	void setText(const std::string& description_text);
	sf::Text getText();

	//Overridden from GUIElement
	/**
	Set the size of the menuItem rendered on the screen
	*/
	void setSize(float x, float y);
	void setSize(sf::Vector2f &new_size);

	/**
	Set the size of the menuItem rendered on the screen
	*/
	void setPosition(float x, float y);
	void setPosition(sf::Vector2f &new_position);

	/**
	Set the Pressed Function after selecting a button 
	*/
	void setPressedFunction(std::function<void()> pressed);

	void callPressedFunction();

	/**
	renders the item as a box with text in it
	@param target the window onto which this MenuItem renders
	*/
	void render();
private:
	//string of text to display
	sf::Text label;
	//Instance of rectangle border
	sf::RectangleShape border;
	/**
	function to call when this menu item is pressed
	*/
	std::function<void()> pressed_function;
};
