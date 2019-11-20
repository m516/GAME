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
}

int PaddleNetworkController::update()
{
	//Don't send anything to a disconnected server
	if (!NetworkConnection::isConnected()) return 1;

	int paddle_y;
	int paddle_x;

	if (paddle_left_action == paddle_action_t::BROADCAST) {
		paddle_y = int(paddle_left->position.y * 9999);
		paddle_x = int(paddle_left->position.x * 9999);
	}
	else if (paddle_right_action == paddle_action_t::BROADCAST) {
		paddle_y = int(paddle_left->position.y * 9999);
		paddle_x = int(paddle_left->position.x * 9999);
	}
	else return 0;

	//Set the movement command
	std::string msg;

	if (paddle_x < 10) msg = "PM000" + std::to_string(paddle_x);
	else if (paddle_x < 100) msg = "PM00" + std::to_string(paddle_x);
	else if (paddle_x < 1000) msg = "PM0" + std::to_string(paddle_x);
	else msg = "PM" + std::to_string(paddle_x);

	if (paddle_y < 10) msg += ",000" + std::to_string(paddle_y);
	else if (paddle_y < 100) msg += ",00" + std::to_string(paddle_y);
	else if (paddle_y < 1000) msg += ",0" + std::to_string(paddle_y);
	else msg += "," + std::to_string(paddle_y);

	NetworkConnection::send(msg);

	return 0;
}

int PaddleNetworkController::initialize() {
	// Register our handlers
	NetworkConnection::addListener(NetworkConnection::LISTENER::MESSAGE, std::bind(&PaddleNetworkController::onMessage, this));
	beginTransmission();
	return 0;
}

void PaddleNetworkController::onMessage() {
#ifdef NETWORK_DEBUG
	std::cout << "PaddleNetworkController: Message from server: " << msg->get_payload() << std::endl;
#endif

	std::string payload = NetworkConnection::getString();
	if (payload[2] == '@') {
		payload = payload.substr(3, 2);
		//std::cout << "Received position: " + payload << std::endl;
		float position = std::stof(payload) * 100.f;
		if (paddle_left_action == paddle_action_t::CONTROL) {
			paddle_left->position.y = position / 10000;
		}
		else if (paddle_right_action == paddle_action_t::CONTROL) {
			paddle_right->position.y = position / 10000;
		}
	}
}

