#pragma once

class Controller {
public:

	//The list of controls that go into a menu
	typedef enum class CONTROL
	{
		UP,
		DOWN,
		LEFT,
		RIGHT,
		ENTER,
		EXIT,
		NONE
	} Control;

	typedef enum class STATUS {
		UP,
		PRESSED,
		DOWN,
		RELEASED,
		DISABLED
	} Status;


	//Update the keys being pressed.
	virtual void update() = 0;


	//Controls
	Status up = Status::UP;
	Status down = Status::UP;
	Status left = Status::UP;
	Status right = Status::UP;
	Status enter = Status::UP;
	Status exit = Status::UP;
	Control current_control = Control::NONE;

	//updates the controls only if enabled is true
	bool enabled = true;
};

