#include "statMenu.h"
#include <iostream>


StatMenu::StatMenu(sf::RenderWindow* window, Theme* theme = 0)
{
	//Set the renderer
	renderer = window;
	this->theme = theme;

	//Initialize a new theme if necessary
	if (theme == NULL)  theme = new Theme();

	sf::Http http;
	http.setHost("coms-309-sr-5.misc.iastate.edu", 8080);
	//TODO UNHARD_CODE THIS
	sf::Http::Request request("/user/4", sf::Http::Request::Get);
	sf::Http::Response response = http.sendRequest(request);
	std::string responseString = response.getBody();
	std::int16_t responseLength = responseString.length();
	std::string shortenedString = responseString.substr(1, (responseLength - 2));
	std::int16_t size = shortenedString.length();

	std::string delimeter = ",";

	size_t pos = 0;
	std::string token;
	//ADD USERNAME
	//ADD WINS 
	//ADD LOSES 
	//ADD LEVEL

	while ((pos = shortenedString.find(delimeter)) != std::string::npos) 
    {
		token = shortenedString.substr(0, pos);
		std::cout << token << std::endl;
		shortenedString.erase(0, pos + delimeter.length());
	}

	std::cout << shortenedString << std::endl;

	//Convers the string into a char array to do parsing with

	//std::string tokenized = responseString.split(" ");
	//char responseChar[size];

	//const char* tokenized = str(responseChar, "\"");
	//std::string tokenized = strtok( "\"");
	//std::string responseString2 = response.getField("date");

	//This removes the two curly braces from the end and the beginning, offset of 1
	//and a shorter length of 2

	//This prints the reponse Str to the console for testing 
	//std::cout << responseString << std::endl;
	//std::cout << responseChar << std::endl;
	//std::cout << strtok(responseString, "\"") << std::endl;
	//std::cout << responseLength << std::endl;
	//std::cout << shortenedString << std::endl;
	std::cout << response.getField("email") << std::endl;

	//Create Display for Stat Fields
	username = new sf::Text();
	username->setCharacterSize(50);
	username->setFont(theme->font_standard);
	username->setFillColor(theme->color_selected);
	//TODO -> get this information from the database
	username->setString("Username:" + responseString);

	//TODO -> to be changed later
	username->setPosition(10, 10);

	wins = new sf::Text();
	wins->setCharacterSize(50);
	wins->setFont(theme->font_standard);
	wins->setFillColor(theme->color_selected);
	//TODO -> get this information from the database
	wins->setString("Wins: 0");

	//TODO -> to be changed later
	wins->setPosition(10, 70);

	losses = new sf::Text();
	losses->setCharacterSize(50);
	losses->setFont(theme->font_standard);
	losses->setFillColor(theme->color_selected);
	//TODO -> get this information from the database
	losses->setString("Losses: 1");

	//TODO -> to be changed later
	losses->setPosition(10, 130);

	level = new sf::Text();
	level->setCharacterSize(50);
	level->setFont(theme->font_standard);
	level->setFillColor(theme->color_selected);
	//TODO -> get this information from the database
	level->setString("Level: 2");

	//TODO -> to be changed later
	level->setPosition(10, 190);
}

void StatMenu::render()
{
	if (renderer != NULL) 
    {
		renderer->draw(*username);
		renderer->draw(*wins);
		renderer->draw(*losses);
		renderer->draw(*level);
	}
}

StatMenu::~StatMenu()
{
	delete username;
	delete wins;
	delete losses;
	delete level;
}