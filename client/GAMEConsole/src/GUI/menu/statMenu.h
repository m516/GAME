#pragma once

#include "../lockingElement.h"

class StatMenu : public LockingElement
{
public: 
	StatMenu(sf::RenderWindow* window, Theme* theme);

	~StatMenu();

	//Inherited from GUIElement
	void render();

private: 






};