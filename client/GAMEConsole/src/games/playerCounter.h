#pragma once

#include "../modules/network.h"
#include "../GUI/lockingElement.h"
#include <SFML\Graphics\Text.hpp>

/*This menu is made to call websocket op-codes that tell the server to create a new online game
or to join an existing one. Note that will only run preexisting games and WILL NOT create 
and configure new ones*/
class PlayerCounter : public GUIElement
{
public:

	PlayerCounter(sf::RenderWindow* window, int gameID, int expectedNumPlayers, Theme* theme = Theme::universal_theme);
	~PlayerCounter();

	void render();
	void ping();

	void lockUntilFull();
	int getNumPlayers();
	bool isFull();

private:
	int gameID;
	int expectedNumPlayers;
	sf::RenderWindow* renderer;
	sf::Text* gameIDLabel = 0;
	sf::Text* numJoinedLabel = 0;

	/*
	Counter for slow network refresh 
	(we don't need to ping the server
	to see if the game is full 60 times
	per second
	*/
	int counter = 0;
	int numJoinedPlayers = 0;
	void checkGameStatus();
};

