#include "ball.h"

Ball::Ball(Game* game) {
	this->game = game;

	//Set initial size and position
	size = sf::Vector2f(0.1f, 0.1f);
	position = sf::Vector2f(0.5f, 0.5f);

	//Update screen dimensions
	updateScreenDimensions();

	//Create a circle to render
	shape = sf::CircleShape();

	//Set the radius of the shape based on its screen size
	shape.setRadius(50.f);

	shape.setFillColor(sf::Color(0,180,32));
}

void Ball::update() {
	position.x += 0.01f;
	position.y += 0.01f;

	if (position.x >= 1.0) {
		position.x = 0.0;
		position.y = 0.0;
	}
}

void Ball::render() {
	updateScreenDimensions();

	shape.setPosition(screen_position);
	shape.setRadius(screen_size.x);

	game->getRenderer()->draw(shape);
}