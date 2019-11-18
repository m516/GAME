#include "playerCounter.h"


PlayerCounter::PlayerCounter(sf::RenderWindow* window, int gameID, int expectedNumPlayers, Theme* theme)
{
	//Set the renderer
	renderer = window;
	this->gameID = gameID;
	this->expectedNumPlayers = expectedNumPlayers;
	this->theme = theme;

	gameIDLabel = new sf::Text();
	numJoinedLabel = new sf::Text();
	//gameIDLabel->setCharacterSize(32);
	//gameIDLabel->setPosition(5,5);
	//numJoinedLabel->setCharacterSize(24);
	//numJoinedLabel->setPosition(5, 48);


	gameIDLabel->setFont(theme->font_standard);
	numJoinedLabel->setFont(theme->font_standard);



	numJoinedLabel->setFillColor(theme->color_deselected);
	gameIDLabel->setFillColor(theme->color_selected);

	NetworkConnection::addListener(NetworkConnection::LISTENER::MESSAGE, std::bind(&PlayerCounter::checkGameStatus, this));
}

PlayerCounter::~PlayerCounter()
{
	delete gameIDLabel;
	delete numJoinedLabel;
}

void PlayerCounter::render()
{
	if (renderer != NULL) 
	{

		gameIDLabel->setString("Waiting for game " + std::to_string(gameID));
		numJoinedLabel->setString("1 of " + std::to_string(expectedNumPlayers) + " players has joined");


		gameIDLabel->setCharacterSize(renderer->getSize().y / 8);
		gameIDLabel->setPosition((renderer->getSize().x - gameIDLabel->getGlobalBounds().width) / 2, 5);


		numJoinedLabel->setCharacterSize(renderer->getSize().y / 12);
		numJoinedLabel->setPosition((renderer->getSize().x - numJoinedLabel->getGlobalBounds().width) / 2, renderer->getSize().y /2.f);

		renderer->draw(*gameIDLabel);
		renderer->draw(*numJoinedLabel);
	}
	else {
		std::cout << "Renderer Is Null!" << std::endl;
	}
}

void PlayerCounter::ping()
{

	NetworkConnection::send("GS");
}

void PlayerCounter::lockUntilFull()
{
	while (numJoinedPlayers < expectedNumPlayers || !NetworkConnection::isConnected())
	{
		ping();
		//Sleep to not hog the CPU and network
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			return;
		}

		//Render
		renderer->clear();
		render();
		renderer->display();
	}
}

int PlayerCounter::getNumPlayers()
{
	return 0;
}

bool PlayerCounter::isFull()
{
	return false;
}

void PlayerCounter::checkGameStatus() {
	std::string response = NetworkConnection::getString();
	std::string delimiter = ";";

	size_t pos = 0;
	std::string token;
	while ((pos = response.find(delimiter)) != std::string::npos) {
		token = response.substr(0, pos);
		std::cout << token << std::endl;
		response.erase(0, pos + delimiter.length());
	}
	std::cout << response << std::endl;
}