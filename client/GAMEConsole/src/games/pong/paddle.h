#pragma once

#include "../../sprite.h"
#include <SFML/Graphics/RectangleShape.h>

class Paddle : public Sprite {
public:
	Paddle(Game* game);

	//Inherited from Sprite class
	void update();
	void render();

private:
	sf::CircleShape shape;
};