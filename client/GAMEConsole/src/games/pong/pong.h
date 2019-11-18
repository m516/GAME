#pragma once

#include "../game.h"
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
	int getGameIndex();

	//Inherited from GUIElement class
	void render();


private:
	Ball* ball;
	Paddle* paddle_right;
	Paddle* paddle_left;
	PaddleKeyboardController* right_controller;
	PaddleKeyboardController* left_controller;
	PaddleNetworkController* paddle_network_controller;

	bool initialized = false;

	ScoreBoard* scoreboard;
};