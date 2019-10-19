#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "theme.h"

class GUIElement
{
public:
	/**
	Sets the RenderTarget to render onto
	*/
	void setRenderer(sf::RenderTarget* new_renderer);

	/**
	Set the size of this object rendered on the screen
	*/
	void setSize(float x, float y);
	void setSize(sf::Vector2f& new_size);
	/**
	Get the size of this object rendered on the screen
	*/
	sf::Vector2f getSize();

	/**
	Set the position of this object rendered on the screen
	*/
	void setPosition(float x, float y);
	void setPosition(sf::Vector2f& new_position);

	/**
	Get the position of this object rendered on the screen
	*/
	sf::Vector2f getPosition();

	/**
	renders the item onto a RenderWindow
	@param target the window onto which this GUI element renders
	*/
	virtual void render()=0;
	
	/**
	Enabled
	*/
	bool selected = 1;

protected:
	/** Reference to the parent render object that this element is rendered onto */
	sf::RenderTarget* renderer;
	
	/**
	The position of the item
	*/
	sf::Vector2f position;

	/**
	The size of the item
	*/
	sf::Vector2f size;
	
	/**
	A reference to the theme of the item
	*/
	Theme* theme;
};
