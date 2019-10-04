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
	updateLook();
}

void MenuPane::updateLook() {
	//Resize all the items
	float desiredHeight = size.y / (float)items.size();


	for (unsigned int i = 0; i < items.size(); i++) {
		items[i].setSize(size.x, desiredHeight);
		items[i].setPosition(position.x, position.y+(float)i * desiredHeight);
	}
}


/**
Updates the MenuPane
*/
void MenuPane::update() {
	menuNavigator.poll();

	if (menuNavigator.down==MenuNavigator::STATUS::PRESSED) {
		if (selected < items.size()-1) selected++;
	}

	if (menuNavigator.up == MenuNavigator::STATUS::PRESSED) {
		if (selected > 0) selected--;
	}
}

/**
Renders all the items
*/
void MenuPane::render(sf::RenderTarget* target) {
	for (unsigned int i = 0; i < items.size(); i++) {
		if (selected == i) items[i].selected = 1;
		else items[i].selected = 0;
		items[i].render(target);
	}
}