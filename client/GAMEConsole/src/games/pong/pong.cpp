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
	paddle_right->position.x = 0.9 - paddle_right->size.x;

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
	//TODO stub
	ball->update();
	paddle_right->update();
	paddle_left->update();
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