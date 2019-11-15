#include "score_board.h"


ScoreBoard::ScoreBoard(Game* game, size_t num_players) {
	scores = new unsigned int[num_players];
	this->num_players = num_players;

	//Set description text
	label.setFont(game->getTheme()->font_standard);
}
ScoreBoard::~ScoreBoard() {
	delete scores;
}

void ScoreBoard::render() {

	label.setCharacterSize(20);
	label.setString(get_score_string());
	label.setFillColor(game->getTheme()->color_selected);

	updateScreenDimensions();
	label.setPosition(screen_position);
	game->getRenderer()->draw(label);
}

/*
Adds one point to the player's score
*/
void ScoreBoard::increment_score(int player) {
	check_player(player);
	scores[player]++;
}

/*
Removes all points from a player
*/
void ScoreBoard::reset_score(int player) {
	check_player(player);
	scores[player] = 0;
}


std::string ScoreBoard::get_score_string() {
	std::string text;
	text.append("Score: ");
	for (int i = 0; i < num_players; i++) {
		text.append(std::to_string(scores[i]));
		text.append(", ");
	}
	return text;
}

/*
Resets all scores to 0
*/
void ScoreBoard::reset_scores() {
	for (int i = 0; i < num_players; i++) {
		scores[i] = 0;
	}
}

void ScoreBoard::check_player(int player) {
	if (player >= num_players || player < 0) {
		std::cout << "Attempting to modify player " << player << " when only 0-" << num_players << " exist.";
		throw NonexistentPlayerException;
	}
}

