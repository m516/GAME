#pragma once


#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "../../guiElement.h"



class Button : public GUIElement {
public:
	/**
	Constructs a new Buttond
	*/
	Button();


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
	void render();

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
	sf::RectangleShape border;
};
