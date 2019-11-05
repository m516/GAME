#pragma once

#include "..//..//..//controllers/keyboard_controller.h"
#include "..//paddle.h"

class PaddleKeyboardController : public KeyboardController {
public:
	virtual int update();
	void setPaddle(Paddle* paddle);
private:
	Paddle* paddle;
};