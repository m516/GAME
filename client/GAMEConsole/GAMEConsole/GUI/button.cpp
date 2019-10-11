#pragma once
//TODO nowhere near done!
//TODO make TODOs for the rest of the Button class implementation code!

#include <vector>

#include "button.h"

/**
Constructs a new Button
*/
Button::Button(int initial_size)



/**
Updates the button
*/
void Button::update(){
	
}

//Overridden from GUIElement

/**
renders the item onto a RenderTarget
@param target the window onto which this button renders
*/
void Button::render(sf::RenderTarget* target){
	target->render(circle);
}


/**
Set the size of this object rendered on the screen
*/
void Button::setSize(float x, float y) //TODO
void Button::setSize(sf::Vector2f& new_size);

/**
Set the position of this object rendered on the screen
*/
void Button::setPosition(float x, float y);
void Button::setPosition(sf::Vector2f& new_position);
