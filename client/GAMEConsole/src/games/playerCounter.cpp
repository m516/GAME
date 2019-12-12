#include "playerCounter.h"

PlayerCounter::PlayerCounter(Game* game)
{
	gameIDLabel = new sf::Text();
	numJoinedLabel = new sf::Text();
	//gameIDLabel->setCharacterSize(32);
	//gameIDLabel->setPosition(5,5);
	//numJoinedLabel->setCharacterSize(24);
	//numJoinedLabel->setPosition(5, 48);

	renderer = game->getRenderer();
	theme = game->getTheme();
	this->game = game;

	gameIDLabel->setFont(theme->font_standard);
	numJoinedLabel->setFont(theme->font_standard);


	numJoinedLabel->setFillColor(theme->color_deselected);
	gameIDLabel->setFillColor(theme->color_selected);
}

PlayerCounter::~PlayerCounter()
{
	delete gameIDLabel;
	delete numJoinedLabel;
}

void PlayerCounter::render()
{
	//Set the counter so we know how to periodically check the server for game stats
	counter++;
	if (counter == 100) 
    {
		counter = 0;
		Session::updateAvailableGames();
	}

	//Check for a full game
	if (isFull()) unlockRender();

	//Draw stuff!
	if (renderer != NULL) 
	{

		gameIDLabel->setString("Waiting to start");
		if (Session::currentGame()==nullptr) 
        {
			numJoinedLabel->setString("NULL GAME");
		}
		else 
        {
			numJoinedLabel->setString(Session::currentGame()->getInfo());
		}

		gameIDLabel->setCharacterSize(renderer->getSize().y / 8);
		gameIDLabel->setPosition((renderer->getSize().x - gameIDLabel->getGlobalBounds().width) / 2, 5);

		numJoinedLabel->setCharacterSize(renderer->getSize().y / 12);
		numJoinedLabel->setPosition((renderer->getSize().x - numJoinedLabel->getGlobalBounds().width) / 2, renderer->getSize().y /2.f);

		renderer->draw(*gameIDLabel);
		renderer->draw(*numJoinedLabel);
	}
	else 
    {
		std::cout << "Renderer Is Null!" << std::endl;
	}
}

int PlayerCounter::getNumPlayers()
{
	return Session::currentGame()->num_players;
}

bool PlayerCounter::isFull()
{
	return Session::currentGame()->num_players >= Session::currentGame()->max_players;
}
