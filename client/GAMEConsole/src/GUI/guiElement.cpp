#include "guiElement.h"

//Virtual destructor
GUIElement::~GUIElement() 
{

}

/**
Sets the RenderTarget to render onto
*/
void GUIElement::setRenderer(sf::RenderWindow* new_renderer) 
{
	renderer = new_renderer;
}

/**
Gets the RenderTarget to render onto
*/
sf::RenderWindow* GUIElement::getRenderer() 
{
	return renderer;
}

/**
Set the size of the GUI Element rendered on the screen
*/
void GUIElement::setSize(float x, float y) 
{
	size.x = x;
	size.y = y;
}

void GUIElement::setSize(sf::Vector2f& new_size) 
{
	setSize(new_size.x, new_size.y);
}

Theme* GUIElement::getTheme() 
{
	return theme;
}

void GUIElement::setTheme(Theme* theme) 
{
	this->theme = theme;
}

/**
Get the size of the GUI Element rendered on the screen
*/
sf::Vector2f GUIElement::getSize() 
{
	return size;
}

/**
Set the position of the GUI Element rendered on the screen
*/
void GUIElement::setPosition(float x, float y) 
{
	position.x = x;
	position.y = y;
}
void GUIElement::setPosition(sf::Vector2f& new_position) 
{
	setPosition(new_position.x, new_position.y);
}

/**
Get the position of the GUI Element rendered on the screen
*/
sf::Vector2f GUIElement::getPosition() 
{
	return position;
}