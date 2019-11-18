#include "pong.h"


Pong::Pong() {
	camera_location.x = 0;
	camera_location.y = 0;

	camera_scale = 1.f;

}

Pong::~Pong() {
	deinitialize();
}

void Pong::beginNetworkGame(){
	//Don't initialize twice, that's a memory leak
	if (initialized) return;

	ball = new Ball(this);

	//Create the right paddle
	paddle_right = new Paddle(this);
	paddle_right->position.x = 0.9f - paddle_right->size.x;

	//Create the right paddle controller
	right_controller = new PaddleKeyboardController;
	right_controller->setPaddle(paddle_right);
	right_controller->setKey(KeyboardController::Control::UP, sf::Keyboard::I);
	right_controller->setKey(KeyboardController::Control::DOWN, sf::Keyboard::K);
	right_controller->enable();

	//Create the left paddle
	paddle_left = new Paddle(this);
	paddle_left->position.x = 0.1f;

	//Create the left paddle controller
	left_controller = new PaddleKeyboardController;
	left_controller->setPaddle(paddle_left);
	left_controller->enable();

	//Create network controller
	paddle_network_controller = new PaddleNetworkController();
	paddle_network_controller->setLeftPaddle(paddle_left, PaddleNetworkController::paddle_action::BROADCAST);
	paddle_network_controller->setRightPaddle(paddle_right, PaddleNetworkController::paddle_action::CONTROL);
	paddle_network_controller->initialize();
	paddle_network_controller->enable();

	//Create the scoreboard
	scoreboard = new ScoreBoard(this, 2);
	scoreboard->position.x = 0.5f;
	scoreboard->position.y = 0.1f;

	//Tell the lock to call the deinitialize() function when unlocked
	unlock_function = std::bind(&Pong::deinitialize, this);

	initialized = true;
}

void Pong::beginSpectateGame() {
	//Don't initialize twice, that's a memory leak
	if (initialized) return;

	ball = new Ball(this);

	//Create the right paddle
	paddle_right = new Paddle(this);
	paddle_right->position.x = 0.9f - paddle_right->size.x;

	//Create the right paddle controller
	right_controller = 0;

	//Create the left paddle
	paddle_left = new Paddle(this);
	paddle_left->position.x = 0.1f;

	//Create the left paddle controller
	left_controller = 0;

	//Create network controller
	paddle_network_controller = new PaddleNetworkController();
	paddle_network_controller->setLeftPaddle(paddle_left, PaddleNetworkController::paddle_action::CONTROL);
	paddle_network_controller->setRightPaddle(paddle_right, PaddleNetworkController::paddle_action::CONTROL);
	paddle_network_controller->initialize();
	paddle_network_controller->enable();

	//Create the scoreboard
	scoreboard = new ScoreBoard(this, 2);
	scoreboard->position.x = 0.5f;
	scoreboard->position.y = 0.1f;

	//Tell the lock to call the deinitialize() function when unlocked
	unlock_function = std::bind(&Pong::deinitialize, this);

	initialized = true;
}

void Pong::beginOfflineGame() {
	//Don't initialize twice, that's a memory leak
	if (initialized) return;

	ball = new Ball(this);

	//Create the right paddle
	paddle_right = new Paddle(this);
	paddle_right->position.x = 0.9f - paddle_right->size.x;

	//Create the right paddle controller
	right_controller = new PaddleKeyboardController;
	right_controller->setPaddle(paddle_right);
	right_controller->setKey(KeyboardController::Control::UP, sf::Keyboard::I);
	right_controller->setKey(KeyboardController::Control::DOWN, sf::Keyboard::K);
	right_controller->enable();

	//Create the left paddle
	paddle_left = new Paddle(this);
	paddle_left->position.x = 0.1f;

	//Create the left paddle controller
	left_controller = new PaddleKeyboardController;
	left_controller->setPaddle(paddle_left);
	left_controller->enable();

	//Set the paddle network controller to null
	paddle_network_controller = 0;

	//Create the scoreboard
	scoreboard = new ScoreBoard(this, 2);
	scoreboard->position.x = 0.5f;
	scoreboard->position.y = 0.1f;

	//Tell the lock to call the deinitialize() function when unlocked
	unlock_function = std::bind(&Pong::deinitialize, this);

	initialized = true;
}

void Pong::update(){

	//Update controllers
	if(right_controller != NULL) right_controller->update();
	if(left_controller != NULL) left_controller->update();
	if(paddle_network_controller != NULL) paddle_network_controller->update();

	//Update sprites
	paddle_right->update();
	paddle_left->update();
	ball->update();

	/*
	Normally in large C++ programs, 
	there are dedicated Collision objects 
	that handle an object's interaction 
	with its surroundings. Pong is small
	enough that, for the sake of time, I
	will just implement ball collision code
	here
	*/

	//Bounce off of right paddle
	if (ball->position.x + ball->size.x > paddle_right->position.x &&
		ball->position.x < paddle_right->position.x + paddle_right->size.x &&
		ball->position.y + ball->size.y > paddle_right->position.y &&
		ball->position.y < paddle_right->position.y + paddle_right->size.y) {
		//Assuming ball bounces off sideways
		if (ball->velocity.x > 0) ball->velocity.x = -ball->velocity.x;

	}

	//Bounce off of left paddle
	if (ball->position.x + ball->size.x > paddle_left->position.x &&
		ball->position.x < paddle_left->position.x + paddle_left->size.x &&
		ball->position.y + ball->size.y > paddle_left->position.y &&
		ball->position.y < paddle_left->position.y + paddle_left->size.y) {
		//Assuming ball bounces off sideways
		if (ball->velocity.x < 0) ball->velocity.x = -ball->velocity.x;

	}

	//Bounce off of walls
	if (ball->position.y                < 0.f && ball->velocity.y < 0.0f) ball->velocity.y = -ball->velocity.y;
	if (ball->position.y + ball->size.y > 1.f && ball->velocity.y > 0.0f) ball->velocity.y = -ball->velocity.y;


	if (ball->position.x < 0.f) {
		ball->position.x = 0.1f;
		ball->position.y = 1.f- ball->position.y;
		ball->velocity.x = -ball->velocity.x;
		scoreboard->incrementScore(0);
	}
	if (ball->position.x > 1.f) {
		ball->position.x = 0.9f;
		ball->position.y = 1.f - ball->position.y;
		ball->velocity.x = -ball->velocity.x;
		scoreboard->incrementScore(1);
	}
}

void Pong::render() {
	update();
	scoreboard->render();
	ball->render();
	paddle_right->render();
	paddle_left->render();
}

void Pong::deinitialize() {
	if (!initialized) return;
	delete ball;
	delete paddle_right;
	delete paddle_left;
	delete right_controller;
	delete left_controller;
	delete paddle_network_controller;
	delete scoreboard;
	initialized = false;
}

std::string Pong::getName()
{
	return "Pong";
}
