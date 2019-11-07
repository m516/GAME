#pragma once

#include "../game.h"
#include "objects/ball.h"
#include "objects/paddle.h"
#include "objects/paddle_keyboard_controller.h"
#include "objects/paddle_network_controller.h"

class Pong : public Game {
public:

	Pong();
	~Pong();

	//Inherited from Game class
	void initialize();
	void update();
	void deinitialize();

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
};