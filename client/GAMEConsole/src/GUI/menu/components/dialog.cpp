#include "dialog.h"
/**
Initializes the TextField with the things it needs to have.
@param text the text to display on the menu
@param function the function to call when the menu item is activated
*/
Dialog::Dialog(GUIElement* parent, const std::string message) {
	this->parent = parent;
	this->label = new sf::Text();
	this->theme = parent->getTheme();
	this->renderer = parent->getRenderer();
	label->setFont(theme->font_standard);
	label->setFillColor(theme->color_selected);
	label->setCharacterSize(renderer->getSize().y / 10.f);
	label->setPosition(5.f, 5.f);
	label->setString(message);
}
/**
Deconstructor for MenuItem
*/
Dialog::~Dialog() {
	delete label;
}

/**
renders the item as a box with text in it
@param target the window onto which this MenuItem renders
*/
void Dialog::render() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return)) {
		if (enter_state == 0) enter_state = 1;
	}
	else {
		if (enter_state == -1) enter_state = 0;
		else if (enter_state == 1) unlockRender();
	}
	renderer->draw(*label);
}

/**
Creates a new Dialog and displays it.

Equivalent to creating a new Dialog instance and calling its
lockRender() function
*/
void Dialog::show(GUIElement* parent, const std::string message) {
	Dialog d(parent, message);
	d.lockRender();
}