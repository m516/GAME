#include "pong.h"


Pong::Pong() {
	camera_location.x = 0;
	camera_location.y = 0;

	camera_scale = 1.f;
}

Pong::~Pong() {
	delete ball;
	delete paddle_right;
	delete paddle_left;
}

void Pong::initialize(){
	ball = new Ball(this);

	//Create the right paddle
	paddle_right = new Paddle(this);
	paddle_right->position.x = 0.9f - paddle_right->size.x;

	KeyboardController* right_controller = new KeyboardController;
	right_controller->setKey(Controller::Control::UP, sf::Keyboard::I);
	right_controller->setKey(Controller::Control::DOWN, sf::Keyboard::K);
	paddle_right->setController(right_controller);

	//Create the left paddle
	paddle_left = new Paddle(this);
	paddle_left->position.x = 0.1f;
	paddle_left->setController(new KeyboardController);
}

void Pong::update(){
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
}

void Pong::render() {
	//TODO stub
	ball->render();
	paddle_right->render();
	paddle_left->render();
}

void Pong::deinitialize() {
	//TODO stub

}