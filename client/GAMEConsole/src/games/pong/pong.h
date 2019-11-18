#pragma once

#include "../game.h"
#include "../playerCounter.h"
#include "objects/ball.h"
#include "objects/paddle.h"
#include "objects/paddle_keyboard_controller.h"
#include "objects/paddle_network_controller.h"
#include "objects/score_board.h"

class Pong : public Game {
public:

	Pong();
	~Pong();

	//Inherited from Game class
	void beginNetworkGame();
	void beginOfflineGame();
	void beginSpectateGame();
	void update();
	void deinitialize();
	std::string getName();
	int getNumPlayers(); 
	int getGameType();

	//Inherited from GUIElement class
	void render();


private:
	Ball* ball = 0;
	Paddle* paddle_right = 0;
	Paddle* paddle_left = 0;
	PaddleKeyboardController* right_controller = 0;
	PaddleKeyboardController* left_controller = 0;
	PaddleNetworkController* paddle_network_controller = 0;

	PlayerCounter* player_counter = 0;

	bool initialized = false;
	bool waitingForPlayers = true;

	ScoreBoard* scoreboard;
};