#pragma once

#include "paddle.h"
#include "../../controllers/controller.h"
#include "../../../modules/network.h"

class PaddleNetworkController : public Controller
{
public:
	Paddle* paddle_left;
	Paddle* paddle_right;

	typedef enum class paddle_action {
		BROADCAST,
		CONTROL,
		NONE
	} paddle_action_t;

	void setRightPaddle(Paddle* paddle, paddle_action_t action = paddle_action_t::NONE);
	void setRightPaddleAction(paddle_action_t action);

	void setLeftPaddle(Paddle* paddle, paddle_action_t action);
	void setLeftPaddleAction(paddle_action_t action);


	int update();

	int initialize();

	void onMessage();


private:
	paddle_action_t paddle_left_action = paddle_action_t::NONE;
	paddle_action_t paddle_right_action = paddle_action_t::NONE;
	bool connected = false;
	void beginTransmission();
};

