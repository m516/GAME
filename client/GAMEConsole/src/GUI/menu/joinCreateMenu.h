#pragma once

#include "../lockingElement.h"
#include "../../games/game.h"
#include "../../application.h"
#include "components/menuPane.h"

class JoinCreateMenu : public LockingElement
{
public:
	JoinCreateMenu(sf::RenderWindow* window, Game* game, Theme* theme);

	~JoinCreateMenu();

	//Inherited from GUIElement
	void render();

private:

	MenuPane* menu = 0;

	sf::Text* title = 0;

	/** Minimum frame time (essentially highest fps possible)*/
	const sf::Time frame_period = sf::milliseconds(10.f);

	//private menu-specific functions
	void startOnlineGame();
	void startOfflineGame();
	void startSpectateGame();

	Game* game;
};

