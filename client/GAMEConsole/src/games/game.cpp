#include "game.h"

//Keep this file in case we need to use it later to implement functions

int Game::getGameID()
{
	return gameID;
}

void Game::setGameID(int id)
{
	gameID = id;
}

std::string Game::getName()
{
	return "Game";
}
