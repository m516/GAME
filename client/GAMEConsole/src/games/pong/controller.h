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


	//Controls
	Status up = Status::UP;
	Status down = Status::UP;
	Status left = Status::UP;
	Status right = Status::UP;
	Status enter = Status::UP;
	Status exit = Status::UP;
	Control current_control = Control::NONE;

	//Controller updates the controls only if enabled is true
	int enabled = 1;

	virtual void update() = 0;
};