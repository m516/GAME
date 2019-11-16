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


	//Make me move!
	enable_motion = true;

	velocity.x = 0.01f;
	velocity.y = 0.006f;
}

void Ball::update() {
	Sprite::update();
}

void Ball::render() {
	updateScreenDimensions();

	shape.setPosition(screen_position);
	shape.setRadius(screen_size.x/2.f); 
	shape.setFillColor(game->getTheme()->color_selected);

	game->getRenderer()->draw(shape);
}