#pragma once

#include <vector>

#include "..//..//sprite.h"

typedef std::vector<Sprite> sprite_list;

class Controller {
public:

	//Virtual destructor
	virtual ~Controller();

	//Sets whether or not the controller does anything on update
	bool enabled = false;

	//Update the keys being pressed.
	virtual void update() = 0;

	//List of Sprite objects to control
	sprite_list targets;
};

