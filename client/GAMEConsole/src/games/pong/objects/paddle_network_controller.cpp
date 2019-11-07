#include "paddle_network_controller.h"

//#define NETWORK_DEBUG

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
	else if (paddle_right_action == paddle_action_t::BROADCAST) {
		send("!12");
	}
}

int PaddleNetworkController::update()
{
	//Don't send anything to a disconnected server
	if (!connected) return 1;

	int paddle_y;

	if (paddle_left_action == paddle_action_t::BROADCAST) {
		paddle_y = int(paddle_left->position.y * 9999);
	}
	else if (paddle_right_action == paddle_action_t::BROADCAST) {
		paddle_y = int(paddle_left->position.y * 9999);
	}
	else return 0;

	std::string msg;

	if (paddle_y < 10) msg = ".000" + std::to_string(paddle_y);
	else if (paddle_y < 100) msg = ".00" + std::to_string(paddle_y);
	else if (paddle_y < 1000) msg = ".0" + std::to_string(paddle_y);
	else msg = "." + std::to_string(paddle_y);

	send(msg);

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
#ifdef NETWORK_DEBUG
	std::cout << "PaddleNetworkController: Message from server: " << msg->get_payload() << std::endl;
#endif

	std::string payload = msg->get_payload();
	if (payload[0] == '.') {
		payload = payload.substr(1, 4);
		//std::cout << "Received position: " + payload << std::endl;
		float position = std::stof(payload);
		if (paddle_left_action == paddle_action_t::CONTROL) {
			paddle_left->position.y = position / 10000;
		}
		else if (paddle_right_action == paddle_action_t::CONTROL) {
			paddle_right->position.y = position / 10000;
		}
	}
}

void PaddleNetworkController::onFail(client_t* c, websocketpp::connection_hdl hdl) {
#ifdef NETWORK_DEBUG
	std::cout << "PaddleNetworkController: Failed to retain connection to server" << std::endl;
#endif
	connected = false;
}

void PaddleNetworkController::onClose(client_t* c, websocketpp::connection_hdl hdl) {
#ifdef NETWORK_DEBUG
	std::cout << "PaddleNetworkController: Closing connection to server" << std::endl;
#endif
	connected = false;
}

void PaddleNetworkController::onOpen(client_t* c, websocketpp::connection_hdl hdl) {
	NetworkController::onOpen(c, hdl);
#ifdef NETWORK_DEBUG
	std::cout << "PaddleNetworkController: Connected to server" << std::endl;
#endif
	connected = true;
	beginTransmission();
}
