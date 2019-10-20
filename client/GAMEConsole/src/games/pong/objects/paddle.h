#pragma once

#include "../../sprite.h"
#include "../controllers/controller.h"
#include <SFML/Graphics/RectangleShape.hpp>

class Paddle : public Sprite {
public:
	Paddle(Game* game);

	~Paddle();

	//Inherited from Sprite class
	void update();
	void render();

	//Sets the current controller
	void setController(Controller* controller);

private:
	sf::RectangleShape shape;

	Controller* controller;
};