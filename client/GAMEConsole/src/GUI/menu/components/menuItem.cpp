#include "menuItem.h"
#include <string>
#include <iostream>
#include <functional>

MenuItem::MenuItem(Theme *theme, const std::string& text, std::function<void()> pressed) 
{
	// Set theme
	this->theme = theme;

	//Set description text
	label.setString(text);
	label.setFont(theme->font_standard);
	
	pressed_function = pressed;
	//Configure border
	border.setPosition(position);
	border.setSize(size);
	border.setOutlineThickness(1.f);
}

MenuItem::~MenuItem() 
{

}

//renders the item as a box with text in it
void MenuItem::render() 
{
	//Set colors based on whether or not this item is selected
	if (selected) 
	{
		label.setFillColor(theme->color_selected);
		border.setOutlineColor(theme->color_selected);
		border.setFillColor(theme->color_selected);
	}
	else 
	{
		label.setFillColor(theme->color_deselected);
		border.setOutlineColor(theme->color_deselected);
		border.setFillColor(theme->color_deselected);
	}
	

	renderer->draw(border);
	renderer->draw(label); //TODO doesn't check if the text is longer than the border!
}

void MenuItem::setText(const std::string& text) 
{
	label.setString(text);
}

sf::Text MenuItem::getText()
{
	return label;
}

/**
Set the size of the menuItem rendered on the screen
*/
void MenuItem::setSize(float x, float y) 
{
	GUIElement::setSize(x, y);
	border.setSize(sf::Vector2f(y*.5f, y*.5f));
	label.setCharacterSize(y - 4.f);
}

void MenuItem::setSize(sf::Vector2f &new_size) 
{
	GUIElement::setSize(new_size);
	border.setSize(sf::Vector2f(new_size.y*.5f, new_size.y*.5f));
	label.setCharacterSize(new_size.y - 4.f);
}

/**
Set the size of the menuItem rendered on the screen
*/
void MenuItem::setPosition(float x, float y) 
{
	GUIElement::setPosition(x, y);
	border.setPosition(position.x + size.y / 4.f, position.y + size.y / 4.f);
	label.setPosition(position.x + size.y + 10, position.y + 2.f);
}

void MenuItem::setPosition(sf::Vector2f &new_position) 
{
	GUIElement::setPosition(new_position);
	border.setPosition(position.x + size.y/4.f, position.y + size.y / 4.f);
	label.setPosition(position.x + size.y + 10, position.y);
}

void MenuItem::setPressedFunction(std::function<void()> pressed) {
	pressed_function = pressed;
}

void MenuItem::callPressedFunction() {
	if(pressed_function != NULL) 
		pressed_function();
}