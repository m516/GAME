#pragma once
#pragma once
#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class GUIElement {
public:
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
	renders the item onto a RenderWindow
	@param target the window onto which this MenuItem renders
	*/
	virtual void render(sf::RenderTarget* target) = 0;

	/**
	Updates how the GUI element looks
	Called after each time the position or size is reset
	*/
	virtual void updateLook() = 0;



protected:


	/**
	The position of the item
	*/
	sf::Vector2f position;

	/**
	The size of the item
	*/
	sf::Vector2f size;
};