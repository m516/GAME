#include "paddle.h"

Paddle::Paddle(Game* game) {
	this->game = game;

	//Set initial size and position
	size = sf::Vector2f(0.05f, 0.2f);
	position = sf::Vector2f(0.1f, 0.5f);

	//Update screen dimensions
	updateScreenDimensions();

	//Create a rectangle to render
	shape = sf::RectangleShape();

	shape.setFillColor(sf::Color(32, 255, 128));
}

Paddle::~Paddle() {
	delete controller;
}

void Paddle::setController(Controller* controller) {
	this->controller = controller;
}

void Paddle::update() {

	controller->update();

	if (controller->down==Controller::STATUS::DOWN) {
		if (position.y < 1.f-size.y) position.y += 0.01f;
	}
	else if (controller->up == Controller::STATUS::DOWN) {
		if (position.y > 0.0f) position.y -= 0.01f;
	}

}

void Paddle::render() {
	updateScreenDimensions();

	shape.setPosition(screen_position);
	shape.setSize(screen_size);

	game->getRenderer()->draw(shape);
}