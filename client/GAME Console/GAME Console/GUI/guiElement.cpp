#include "guiElement.h"
/**
Set the size of the menuItem rendered on the screen
*/
void GUIElement::setSize(float x, float y) {
	size.x = x;
	size.y = y;
	updateLook();
}
void GUIElement::setSize(sf::Vector2f& new_size) {
	setSize(new_size.x, new_size.y);
	updateLook();
}

/**
Get the size of the menuItem rendered on the screen
*/
sf::Vector2f GUIElement::getSize() {
	return size;
}

/**
Set the size of the menuItem rendered on the screen
*/
void GUIElement::setPosition(float x, float y) {
	position.x = x;
	position.y = y;
	updateLook();
}
void GUIElement::setPosition(sf::Vector2f& new_position) {
	setPosition(new_position.x, new_position.y);
	updateLook();
}


/**
Get the size of the menuItem rendered on the screen
*/
sf::Vector2f GUIElement::getPosition() {
	return position;
}