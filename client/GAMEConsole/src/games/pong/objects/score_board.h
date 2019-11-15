#pragma once

#include <exception>
#include <iostream>

#include "../../../GUI/theme.h"
#include "../../sprite.h"

class ScoreBoard: public Sprite{
public:

	ScoreBoard(Game* game, size_t num_players);
	~ScoreBoard();

	virtual void render();

	/*
	Adds one point to the player's score
	*/
	void increment_score(int player);

	/*
	Removes all points from a player
	*/
	void reset_score(int player);

	/*
	Resets all scores to 0
	*/
	void reset_scores();

	std::string get_score_string();

	class NPE : public std::exception
	{
		virtual const char* what() const throw()
		{
			return "Ignorance and stupidity happened, and it collided beautifully with forethought and intelligence to rasie this exception and obliterate the program.";
		}
	} NonexistentPlayerException;

private:
	void check_player(int player);
	unsigned int* scores;
	size_t num_players;

	//Graphics
	//string of text to display
	sf::Text label;
};

