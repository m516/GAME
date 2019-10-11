#pragma once


#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "../guiElement.h"

//Shortcut for writing vectors of MenuItems
typedef std::vector<MenuItem> MenuItem_vec_t;


class Button : public GUIElement {
public:
	/**
	Constructs a new MenuPane
	*/
	Button(int initial_size);


	typedef enum STATE {
		UP,
		PRESSED,
		DOWN,
		RELEASED,
		DISABLED
	} state;


	/**
	Updates the button
	*/
	void update();

	//Overridden from GUIElement

	/**
	renders the item onto a RenderTarget
	@param target the window onto which this button renders
	*/
	void render(sf::RenderTarget* target);

	/**
	Updates how the GUI element looks
	Called after each time the position or size is reset
	*/
	void updateLook();

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
	sf::CircleShape circle;
};
