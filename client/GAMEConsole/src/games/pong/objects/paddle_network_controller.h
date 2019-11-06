#pragma once

#include "paddle.h"
#include "..//..//controllers/network_controller.h"

class PaddleNetworkController : public NetworkController
{
public:
	Paddle* paddle_left;
	Paddle* paddle_right;

	typedef enum paddle_action {
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

	void onMessage(client_t* c, websocketpp::connection_hdl hdl, message_ptr msg);

	void onFail(client_t* c, websocketpp::connection_hdl hdl);

	void onClose(client_t* c, websocketpp::connection_hdl hdl);

	void onOpen(client_t* c, websocketpp::connection_hdl hdl);

private:
	paddle_action_t paddle_left_action = paddle_action_t::NONE;
	paddle_action_t paddle_right_action = paddle_action_t::NONE;
	bool connected = false;
	void beginTransmission();
};

