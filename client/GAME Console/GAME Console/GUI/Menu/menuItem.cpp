#include "menuItem.h"
#include <string>

MenuItem::MenuItem(Theme *theme, const std::string& text, int (*function_when_pressed) ()) {
	//Set description text
	label.setString(text);
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
void MenuItem::render(sf::RenderWindow *window) {
	//Set colors based on whether or not this item is selected
	if (selected) {
		border.setFillColor(theme->color_selected);
		label.setFillColor(theme->color_deselected);
	}
	else {
		border.setFillColor(theme->color_deselected);
		label.setFillColor(theme->color_selected);
	}
	window->draw(border);
	window->draw(label); //TODO doesn't check if the text is longer than the border!
}

void MenuItem::setText(const std::string& text) {
	label.setString(text);
}

/**
Set the size of the menuItem rendered on the screen
*/
void MenuItem::setSize(float x, float y) {
	size.x = x;
	size.y = y;
	border.setSize(size);
	label.setCharacterSize(y - 4);
}
void MenuItem::setSize(sf::Vector2f &new_size) {
	setSize(new_size.x, new_size.y);
}

/**
Get the size of the menuItem rendered on the screen
*/
sf::Vector2f MenuItem::getSize() {
	return size;
}

/**
Set the size of the menuItem rendered on the screen
*/
void MenuItem::setPosition(float x, float y) {
	position.x = x;
	position.y = y;
	border.setPosition(position);
	label.setPosition(position);
	//TODO center the label
}
void MenuItem::setPosition(sf::Vector2f &new_position) {
	setPosition(new_position.x, new_position.y);
}

/**
Get the size of the menuItem rendered on the screen
*/
sf::Vector2f MenuItem::getPosition() {
	return position;
}