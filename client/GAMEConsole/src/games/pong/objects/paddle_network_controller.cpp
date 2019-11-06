#include "paddle_network_controller.h"

void PaddleNetworkController::setRightPaddle(Paddle* paddle, paddle_action_t action)
{
	paddle_right = paddle;
	paddle_right_action = action;
}

void PaddleNetworkController::setRightPaddleAction(paddle_action_t action)
{
	paddle_right_action = action;
}

void PaddleNetworkController::setLeftPaddle(Paddle* paddle, paddle_action_t action)
{
	paddle_left = paddle;
	paddle_left_action = action;
}

void PaddleNetworkController::setLeftPaddleAction(paddle_action_t action)
{
	paddle_left_action = action;
}

void PaddleNetworkController::beginTransmission() {
	if (paddle_left_action == paddle_action_t::BROADCAST) {
		send("!11");
	}
	else {
		send("!12");
	}
}

int PaddleNetworkController::update()
{
	if (paddle_left_action == paddle_action_t::BROADCAST) {
		int paddle_y = int(paddle_left->position.y * 99);
		std::string msg = "." + std::to_string(paddle_y);
		send(msg);
	}
	else if(paddle_right_action == paddle_action_t::BROADCAST){
		int paddle_y = int(paddle_left->position.y * 99);
		std::string msg = "." + std::to_string(paddle_y);
		send(msg);
	}

	return 0;
}

void PaddleNetworkController::onMessage(client_t* c, websocketpp::connection_hdl hdl, message_ptr msg) {
	std::cout << "Message from server: " << msg->get_payload();
}
