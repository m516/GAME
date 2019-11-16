#include "menu.h"


Panel::Panel(int initial_size) {
	//Initialize list of items
	items.reserve(initial_size);
}

Panel::~Panel() {
	for (size_t i = 0; i < items.capacity(); i++) {
		delete items[i];
	}
	items.clear();
}

/**
Adds an item to the list of items to display
*/
void Panel::addElement(GUIElement* item) {
	item->setRenderer(renderer);

	//Disable MenuPanes
	if (MenuPane * item = dynamic_cast<MenuPane*>(items[selected])) {
		item->menuNavigator.keyboard_enabled = false;
	}
	if (Button * item = dynamic_cast<Button*>(items[selected])) {
		item->selected = false;
	}
	

	if (items.capacity() == items.size()) items.reserve(items.capacity() + 5);
	items.push_back(item);
	updateLook();
}

void Panel::updateLook() {
	//Resize all the items
	float desiredHeight = size.y / (float)items.size();


	for (unsigned int i = 0; i < items.size(); i++) {
		items[i]->setSize(size.x, desiredHeight);
		items[i]->setPosition(position.x, position.y + (float)i * desiredHeight);
	}
}


/**
Updates the Panel;
*/
void Panel::update() {
	paneNavigator.poll();

	if (paneNavigator.down == MenuNavigator::STATUS::PRESSED) {
		if (selected < items.size() - 1) selected++;
	}

	if (paneNavigator.up == MenuNavigator::STATUS::PRESSED) {
		if (selected > 0) selected--;
	}

	if (paneNavigator.enter == MenuNavigator::STATUS::PRESSED) {
		paneNavigator.keyboard_enabled = false;

		//Enable the navigator for the MenuPane
		if (MenuPane* item = dynamic_cast<MenuPane*>(items[selected])) {
			item->menuNavigator.keyboard_enabled = true;
		}

		if (Button * item = dynamic_cast<Button*>(items[selected])) {
			item->selected = false;
		}
	}
}

/**
Renders all the items
*/
void Panel::render() {
	for (unsigned int i = 0; i < items.size(); i++) {
		if (selected == i) items[i]->selected = 1;
		else items[i]->selected = 0;
		items[i]->render();
	}
}

//Override GUIElement functions to up-date the look

/**
Set the size of this object rendered on the screen
*/
void Panel::setSize(float x, float y) {
	GUIElement::setSize(x, y);
	updateLook();
}
void Panel::setSize(sf::Vector2f& new_size) {
	GUIElement::setSize(new_size);
	updateLook();
}


/**
Set the size of this objet rendered on the screen
*/
void Panel::setPosition(float x, float y) {
	GUIElement::setPosition(x, y);
	updateLook();
}
void Panel::setPosition(sf::Vector2f& new_position) {
	GUIElement::setPosition(new_position);
	updateLook();
}
