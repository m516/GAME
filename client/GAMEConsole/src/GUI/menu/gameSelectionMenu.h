#pragma once

#include "../lockingElement.h"
#include "../../games/pong/pong.h"
#include "../../application.h"
#include "components/menuPane.h"
#include "gameMenu.h"

class GameSelectionMenu : public LockingElement
{
public:
	GameSelectionMenu(sf::RenderWindow* window, Theme* theme);

	~GameSelectionMenu();

	//Inherited from GUIElement
	void render();

private:

	MenuPane* menu = 0;

	sf::Text* title = 0;

	/** Minimum frame time (essentially highest fps possible)*/
	const sf::Time frame_period = sf::milliseconds(10.f);

	//private menu-specific functions
	void runPong();
	void goBack();
};

