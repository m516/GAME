#include "paddle.h"

Paddle::Paddle(Game* game) {
	this->game = game;

	//Set initial size and position
	size = sf::Vector2f(0.02f, 0.15f);
	position = sf::Vector2f(0.1f, 0.5f);

	//Update screen dimensions
	updateScreenDimensions();

	//Create a rectangle to render
	shape = sf::RectangleShape();

	shape.setFillColor(sf::Color(17, 232, 255));
}

Paddle::~Paddle() {
}


void Paddle::update() {
}

void Paddle::render() {
	updateScreenDimensions();

	shape.setPosition(screen_position);
	shape.setSize(screen_size);

	game->getRenderer()->draw(shape);
}