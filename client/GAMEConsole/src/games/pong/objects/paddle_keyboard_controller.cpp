#include "paddle_keyboard_controller.h"

int PaddleKeyboardController::update() 
{
	KeyboardController::update();

	if (down == KeyboardController::STATUS::DOWN) 
    {
		if (paddle->position.y < 1.f - paddle->size.y) paddle->position.y += 0.01f;
	}

	else if (up == KeyboardController::STATUS::DOWN) 
    {
		if (paddle->position.y > 0.0f) paddle->position.y -= 0.01f;
	}

	return 0;
}
