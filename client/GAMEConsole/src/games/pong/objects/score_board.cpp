#include "score_board.h"


ScoreBoard::ScoreBoard(Game* game, size_t num_players) 
{
	//Set the game instance
	this->game = game;

	//Initialize score counters
	scores = new unsigned int[num_players];
	this->num_players = num_players;
	//Reset the scores
	resetScores();
}

ScoreBoard::~ScoreBoard() 
{
	delete scores;
}

void ScoreBoard::render() 
{
	//Set text
	label.setFont(game->getTheme()->font_standard);
	label.setCharacterSize(game->getSize().y/3.f);
	label.setString(getScoreString());
	label.setFillColor(game->getTheme()->color_deselected);

	//Set its position
	updateScreenDimensions();
	screen_position.x -= label.getGlobalBounds().width / 2.f;
	label.setPosition(screen_position);
	
	//Render it!
	game->getRenderer()->draw(label);
}

/*
Adds one point to the player's score
*/
void ScoreBoard::incrementScore(int player) 
{
	checkPlayer(player);
	scores[player]++;
}

/*
Removes all points from a player
*/
void ScoreBoard::resetScore(int player) 
{
	checkPlayer(player);
	scores[player] = 0;
}


std::string ScoreBoard::getScoreString() 
{
	std::string text;
	for (int i = 0; i < num_players-1; i++) 
    {
		text.append(std::to_string(scores[i]));
		text.append(", ");
	}

	if(num_players > 1) text.append(std::to_string(scores[num_players-1]));

	return text;
}

/*
Resets all scores to 0
*/
void ScoreBoard::resetScores() 
{
	for (int i = 0; i < num_players; i++) 
    {
		scores[i] = 0;
	}
}

void ScoreBoard::checkPlayer(int player) 
{
	if (player >= num_players || player < 0) 
    {
		std::cout << "Attempting to modify player " << player << " when only 0-" << num_players << " exist.";
		throw NonexistentPlayerException;
	}
}

