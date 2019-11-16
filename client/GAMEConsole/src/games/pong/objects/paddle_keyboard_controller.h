#pragma once

#include "paddle.h"
#include "paddle_controller.h"
#include "..//..//controllers/keyboard_controller.h"

class PaddleKeyboardController : public KeyboardController, public  PaddleController{
public:
	virtual int update();
};