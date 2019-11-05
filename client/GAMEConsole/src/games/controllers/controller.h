#pragma once

#include "..//sprite.h"

class Controller {
public:

	//Virtual destructor
	virtual ~Controller();

	void enable();

	void disable();

	bool is_enabled();

	//Sets whether or not the controller does anything on update
	bool enabled = false;

	//Update the keys being pressed.
	virtual int update() = 0;
};

