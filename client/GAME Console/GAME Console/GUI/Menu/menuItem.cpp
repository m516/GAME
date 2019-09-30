#include "menuItem.h"
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

MenuItem::MenuItem(const std::string& description_text, int (*function_when_pressed) ()) {
	text = description_text;
	pressed_function = function_when_pressed;
	//Configure border
	border.setPosition(position);
	border.setSize(size);
	//Set border render attributes
	border.setOutlineColor(sf::Color::White);
	border.setOutlineThickness(1.f);
}


MenuItem::~MenuItem() {
}


//renders the item as a box with text in it
void MenuItem::render(sf::RenderWindow *window) {
	if (selected) {
		border.setFillColor(sf::Color::White);
	}
	else {
		border.setFillColor(sf::Color::Black);
	}
	window->draw(border);
}

void MenuItem::setText(const std::string& description_text) {
	text = description_text;
}

/**
Set the size of the menuItem rendered on the screen
*/
void MenuItem::setSize(float x, float y) {
	size.x = x;
	size.y = y;
	border.setSize(size);
}
void MenuItem::setSize(sf::Vector2f &new_size) {
	size.x = new_size.x;
	size.y = new_size.y;
	border.setSize(size);
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
}
void MenuItem::setPosition(sf::Vector2f &new_position) {
	position.x = new_position.x;
	position.y = new_position.y;
	border.setPosition(position);
}

/**
Get the size of the menuItem rendered on the screen
*/
sf::Vector2f MenuItem::getPosition() {
	return position;
}