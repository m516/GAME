#include "menuItem.h"
#include <string>
#include <iostream>

MenuItem::MenuItem(Theme *theme, const std::string& text, int (*function_when_pressed) ()) {
	//Set description text
	label.setString(text);
	label.setFont(theme->font_standard);
	label.setCharacterSize(label.getCharacterSize() * 2);
	label.scale(sf::Vector2f(0.5, 0.5));

	pressed_function = function_when_pressed;
	//Configure border
	border.setPosition(position);
	border.setSize(size);
	//Set border render attributes
	border.setOutlineColor(sf::Color::White);
	border.setOutlineThickness(1.f);
	//Set theme
	this->theme = theme;
}


MenuItem::~MenuItem() {
}


//renders the item as a box with text in it
void MenuItem::render() {
	
	//Set colors based on whether or not this item is selected
	if (selected) {
		border.setFillColor(theme->color_selected);
		label.setFillColor(theme->color_deselected);
	}
	else {
		border.setFillColor(theme->color_deselected);
		label.setFillColor(theme->color_selected);
	}
	
	renderer->draw(border);
	renderer->draw(label); //TODO doesn't check if the text is longer than the border!
	
}

void MenuItem::setText(const std::string& text) {
	label.setString(text);
}

/**
Set the size of the menuItem rendered on the screen
*/
void MenuItem::setSize(float x, float y) {
	GUIElement::setSize(x, y);
	border.setSize(size);
	label.setCharacterSize((int)(y - 4.0f));
}
void MenuItem::setSize(sf::Vector2f &new_size) {
	GUIElement::setSize(new_size);
	border.setSize(size);
	label.setCharacterSize((int)(new_size.y - 4.0f));
}


/**
Set the size of the menuItem rendered on the screen
*/
void MenuItem::setPosition(float x, float y) {
	GUIElement::setPosition(x, y);
	border.setPosition(position);
	label.setPosition(position);
}
void MenuItem::setPosition(sf::Vector2f &new_position) {
	GUIElement::setPosition(new_position);
	border.setPosition(position);
	label.setPosition(position);
}
