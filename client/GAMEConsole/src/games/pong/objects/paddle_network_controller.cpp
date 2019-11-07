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
	//Don't send anything to a disconnected server
	if (!connected) return 1;


	if (paddle_left_action == paddle_action_t::BROADCAST) {
		int paddle_y = int(paddle_left->position.y * 99);
		std::string msg = "." + std::to_string(paddle_y);
		send(msg);
	}
	else if (paddle_right_action == paddle_action_t::BROADCAST) {
		int paddle_y = int(paddle_left->position.y * 99);
		std::string msg = "." + std::to_string(paddle_y);
		send(msg);
	}

	return 0;
}

int PaddleNetworkController::initialize() {
	// Register our handlers
	client.set_open_handler(
		bind(&PaddleNetworkController::onOpen, this, &client, ::_1)
	);
	client.set_fail_handler(
		bind(&PaddleNetworkController::onFail, this, &client, ::_1)
	);
	client.set_close_handler(
		bind(&PaddleNetworkController::onClose, this, &client, ::_1)
	);
	client.set_message_handler(
		bind(&PaddleNetworkController::onMessage, this, &client, ::_1, ::_2)
	);

	return NetworkController::initialize();
}

void PaddleNetworkController::onMessage(client_t* c, websocketpp::connection_hdl hdl, message_ptr msg) {
	std::cout << "PaddleNetworkController: Message from server: " << msg->get_payload() << std::endl;
}

void PaddleNetworkController::onFail(client_t* c, websocketpp::connection_hdl hdl) {
	std::cout << "PaddleNetworkController: Failed to retain connection to server" << std::endl;
	connected = false;
}

void PaddleNetworkController::onClose(client_t* c, websocketpp::connection_hdl hdl) {
	std::cout << "PaddleNetworkController: Closing connection to server" << std::endl;
	connected = false;
}

void PaddleNetworkController::onOpen(client_t* c, websocketpp::connection_hdl hdl) {
	NetworkController::onOpen(c, hdl);
	std::cout << "PaddleNetworkController: Connected to server" << std::endl;
	connected = true;
	beginTransmission();
}
