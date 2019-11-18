#include "menuPane.h"


MenuPane::MenuPane(int initial_size) {
	//Initialize list of items
	items.reserve(initial_size);
}

MenuPane::MenuPane(int initial_size, sf::RenderWindow* renderTarget)
{
	items.reserve(initial_size);
	this->setRenderer(renderTarget);
}

/**
Adds an item to the list of items to display
*/
void MenuPane::addItem(MenuItem item) {
	item.setRenderer(renderer);
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
void MenuPane::update() 
{
	menuNavigator.poll();

	if (menuNavigator.down==MenuNavigator::STATUS::PRESSED) 
	{
		if (selected < items.size() - 1) selected++;
		else selected = 0;
	}

	if (menuNavigator.up == MenuNavigator::STATUS::PRESSED) 
	{
		if (selected > 0) selected--;
		else selected = items.size() - 1;
	}

	if (menuNavigator.enter == MenuNavigator::STATUS::PRESSED) 
    {
		MenuItem current_item = items[selected];
		current_item.callPressedFunction();
	}
}

/**
Renders all the items
*/
void MenuPane::render() {
	for (unsigned int i = 0; i < items.size(); i++) {
		if (selected == i) items[i].selected = 1;
		else items[i].selected = 0;
		items[i].render();
	}
}

//Override GUIElement functions to up-date the look

/**
Set the size of this object rendered on the screen
*/
void MenuPane::setSize(float x, float y) {
	GUIElement::setSize(x, y);
	updateLook();
}
void MenuPane::setSize(sf::Vector2f& new_size) {
	GUIElement::setSize(new_size);
	updateLook();
}


/**
Set the size of this objet rendered on the screen
*/
void MenuPane::setPosition(float x, float y) {
	GUIElement::setPosition(x, y);
	updateLook();
}
void MenuPane::setPosition(sf::Vector2f& new_position) {
	GUIElement::setPosition(new_position);
	updateLook();
}
