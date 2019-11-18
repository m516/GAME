#pragma once

#include "../lockingElement.h"
#include "../../games/game.h"
#include "../../application.h"
#include "components/menuPane.h"
#include "../../modules/network.h"

/*This menu is made to call websocket op-codes that tell the server to create a new online game
or to join an existing one. Note that will only run preexisting games and WILL NOT create 
and configure new ones*/
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

	volatile int gameID = -1;

	/** Minimum frame time (essentially highest fps possible)*/
	const sf::Time frame_period = sf::milliseconds(10.f);

	//private menu-specific functions
	void joinGame();
	void createGame();
	void getGameID();

	Game* game;
};

