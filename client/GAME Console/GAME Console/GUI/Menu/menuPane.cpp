#include "menuPane.h"


MenuPane::MenuPane(int initial_size) {
	//Initialize list of items
	items.reserve(initial_size);
}

/**
Adds an item to the list of items to display
*/
void MenuPane::addItem(MenuItem item) {
	if (items.capacity() == items.size()) items.reserve(items.capacity() + 5);
	items.push_back(item);
	updateItems();
}

void MenuPane::updateItems() {
	//Resize all the items
	float desiredHeight = size.y / (float)items.size();


	for (unsigned int i = 0; i < items.size(); i++) {
		items[i].setSize(size.x, desiredHeight);
		items[i].setPosition(position.x, (float)i * desiredHeight);
	}
}

/**
Set the size of the menuItem rendered on the screen
*/
void MenuPane::setSize(float x, float y) {
	size.x = x;
	size.y = y;
	updateItems();
}
void MenuPane::setSize(sf::Vector2f& new_size) {
	setSize(new_size.x, new_size.y);
	updateItems();
}

/**
Get the size of the menuItem rendered on the screen
*/
sf::Vector2f MenuPane::getSize() {
	return size;
}

/**
Set the size of the menuItem rendered on the screen
*/
void MenuPane::setPosition(float x, float y) {
	position.x = x;
	position.y = y;
	updateItems();
}
void MenuPane::setPosition(sf::Vector2f& new_position) {
	setPosition(new_position.x, new_position.y);
	updateItems();
}


/**
Get the size of the menuItem rendered on the screen
*/
sf::Vector2f MenuPane::getPosition() {
	return position;
}

void MenuPane::update() {
	menuNavigator.poll();

	if (menuNavigator.down==MenuNavigator::STATUS::PRESSED) {
		if (selected < items.size()) selected++;
	}

	if (menuNavigator.up == MenuNavigator::STATUS::PRESSED) {
		if (selected > 0) selected--;
	}
}

/**
Renders all the items
*/
void MenuPane::render(sf::RenderWindow* target) {
	for (unsigned int i = 0; i < items.size(); i++) {
		if (selected == i) items[i].selected = 1;
		else items[i].selected = 0;
		items[i].render(target);
	}
}