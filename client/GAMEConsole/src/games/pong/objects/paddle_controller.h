#pragma once

#include "paddle.h"

class PaddleController
{
public:
	void setPaddle(Paddle* paddle);
	virtual int update() = 0;
protected:
	Paddle* paddle;
};

