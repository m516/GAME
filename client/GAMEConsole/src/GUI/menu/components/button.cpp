//TODO nowhere near done!
//TODO make TODOs for the rest of the Button class implementation code!

#include "button.h"

#include "../../guiElement.h"
#include "menuItem.h"

/**
Constructs a new Button
*/
Button::Button()
{
	border = sf::RectangleShape();
	setSize(16, 16);
	setPosition(8, 8);
}

/**
Updates the button
*/
void Button::update()
{
	if (selected) 
    {
		border.setFillColor(theme->color_selected);
	}
	else 
    {
		border.setFillColor(theme->color_deselected);
	}
}

//Overridden from GUIElement

/**
Set the size of the button rendered on the screen
*/
void Button::setSize(float x, float y) 
{
	GUIElement::setSize(x, y);
	border.setSize(size);
}

void Button::setSize(sf::Vector2f& new_size)
{
	GUIElement::setSize(new_size);
	border.setSize(size);
}

/**
Set the size of the button rendered on the screen
*/
void Button::setPosition(float x, float y) 
{
	GUIElement::setPosition(x, y);
	border.setPosition(position);
}

void Button::setPosition(sf::Vector2f& new_position) 
{
	GUIElement::setPosition(new_position);
	border.setPosition(position);
}

/**
renders the item onto a RenderTarget
@param target the window onto which this button renders
*/
void Button::render() 
{
	renderer->draw(border);
}
