#include "ball.h"

Ball::Ball(Game* game) {
	this->game = game;

	//Set initial size and position
	size = sf::Vector2f(0.05f, 0.05f);
	position = sf::Vector2f(0.5f, 0.5f);

	//Update screen dimensions
	updateScreenDimensions();

	//Create a circle to render
	shape = sf::CircleShape();

	//Set the radius of the shape based on its screen size
	shape.setRadius(50.f);

	shape.setFillColor(sf::Color(0,180,32));

	//Make me move!
	enable_motion = true;

	velocity.x = 0.005f;
	velocity.y = 0.002f;
}

void Ball::update() {
	Sprite::update();
	if (position.x < 0.f || position.x>1.f) position.x = 0.5f;
}

void Ball::render() {
	updateScreenDimensions();

	shape.setPosition(screen_position);
	shape.setRadius(screen_size.x/2.f);

	game->getRenderer()->draw(shape);
}