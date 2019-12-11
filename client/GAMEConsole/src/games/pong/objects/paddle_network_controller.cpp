#include "paddle_network_controller.h"

//#define NETWORK_DEBUG

PaddleNetworkController::~PaddleNetworkController()
{
	//Tell the network controller to deregister this callback function
	if (message_listener_function != nullptr) {
		*message_listener_function = std::function<void* ()>();
	}
}

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

void PaddleNetworkController::setBall(Ball* ball)
{
	this->ball = ball;
}

void PaddleNetworkController::setScoreBoard(ScoreBoard* score_board)
{
	this->score_board = score_board;
}

void PaddleNetworkController::beginTransmission() 
{
    // Create a ball game object if this client is the Alpha
	if (isAlpha) {
		if (ball != nullptr) {
			sendObjectData("CR", (Ball*)ball);
		}
	}

}

void PaddleNetworkController::sendObjectData(const std::string prefix, Sprite* sprite)
{
	std::string msg = prefix;

	int sprite_x = int(sprite->position.x * 9999);
	int sprite_y = int(sprite->position.y * 9999);
	if(sprite_x < 0)
		msg += "0000";
	if (sprite_x < 10)
		msg += "000" + std::to_string(sprite_x);
	else if (sprite_x < 100)
		msg += "00" + std::to_string(sprite_x);
	else if (sprite_x < 1000)
		msg += "0" + std::to_string(sprite_x);
	else if (sprite_x < 10000)
		msg += std::to_string(sprite_x);
	else
		msg += "9999";

	if (sprite_y < 0)
		msg += ",0000";
	else if (sprite_y < 10)
		msg += ",000" + std::to_string(sprite_y);
	else if (sprite_y < 100)
		msg += ",00" + std::to_string(sprite_y);
	else if (sprite_y < 1000)
		msg += ",0" + std::to_string(sprite_y);
	else if(sprite_y < 10000)
		msg += "," + std::to_string(sprite_y);
	else
		msg += ",9999";
	NetworkConnection::send(msg);

}

int PaddleNetworkController::update()
{

	//Don't send anything to a disconnected server
	if (!NetworkConnection::isConnected()) return 1;
	
	//Send my location occasionally
	location_ping_timer++;
	if (location_ping_timer >= location_ping_time) {
		location_ping_timer = 0;

		if (paddle_left_action == paddle_action_t::BROADCAST)
		{
			sendObjectData("PM", (Sprite*)paddle_left);
		}
		else if (paddle_right_action == paddle_action_t::BROADCAST)
		{
			sendObjectData("PM", (Sprite*)paddle_right);
		}
		else
		{
			return 0;
		}
	}

    // Controlls ball, score if alpha
	if (isAlpha) {
		//Only request player positions
		NetworkConnection::send("PL");

		if (ball != nullptr) {
			//Update the score if the ball is out of bounds
			if (ball->position.x < 0.f)
			{
				ball->position.x = 0.1f;
				ball->position.y = 1.f - ball->position.y;
				ball->velocity.x = -ball->velocity.x;
				((ScoreBoard*)score_board)->incrementScore(1);

			}

			if (ball->position.x > 1.f)
			{
				ball->position.x = 0.9f;
				ball->position.y = 1.f - ball->position.y;
				ball->velocity.x = -ball->velocity.x;
				((ScoreBoard*) score_board)->incrementScore(0);
			}

			((Ball*)ball)->update();

			//Send the location of the ball to the server
			sendObjectData("OM", (Ball*)ball);
		}
	}
	else { //Updates
		//Request all object positions
		NetworkConnection::send("BL");
	}


	return 0;
}

int PaddleNetworkController::initialize() 
{
	// Register our handlers
	message_listener_function = NetworkConnection::addListener(NetworkConnection::LISTENER::MESSAGE, std::bind(&PaddleNetworkController::onMessage, this));
	beginTransmission();
	return 0;
}

void PaddleNetworkController::onMessage() 
{
    #ifdef NETWORK_DEBUG
	std::cout << "PaddleNetworkController: Message from server: " << msg->get_payload() << std::endl;
    #endif

	std::string payload = NetworkConnection::getString();
	if (payload.substr(0, 3) == "00@") {

		if (payload.size() % 11 == 0) {


			std::vector<std::string> players(payload.size() / 11);
			for (int i = 0; i < payload.size() / 11; i++) {
				players[i] = payload.substr(i * 11, 11);
			}

			if (paddle_left_action == paddle_action::CONTROL) {
				float x = std::stof(players[0].substr(3, 4)) / 10000.f;
				float y = std::stof(players[0].substr(7, 4)) / 10000.f;
				paddle_left->position.x = x;
				paddle_left->position.y = y;
			}
			if (paddle_right_action == paddle_action::CONTROL) {
				float x = std::stof(players[1].substr(3, 4)) / 10000.f;
				float y = std::stof(players[1].substr(7, 4)) / 10000.f;
				paddle_right->position.x = x;
				paddle_right->position.y = y;
			}

		}
	}
	else if (payload.substr(0, 4) == "P00@") {

		if (payload.size() % 11 == 2) {

			//Extract the players
			std::vector<std::string> players;
			int i;
			for (i = 1; i < payload.size() && payload[i] != 'O'; i += 11) {
				players.push_back(payload.substr((size_t)i, 11));
			}
			//Extract the objects
			std::vector<std::string> objects;
			i++;
			for (; i < payload.size(); i += 11) {
				objects.push_back(payload.substr((size_t)i, 11));
			}

			//Pong-specific functionality
			//Reject if player size not equal to two
			if (players.size() != 2) {
				std::cerr << "I don't know what to do with " << players.size() << " players" << std::endl;
				return;
			}
			//Set left player movement
			if (paddle_left_action == paddle_action::CONTROL) {
				float x = std::stof(players[0].substr(3, 4)) / 10000.f;
				float y = std::stof(players[0].substr(7, 4)) / 10000.f;
				paddle_left->position.x = x;
				paddle_left->position.y = y;
			}
			//Set right player movement
			if (paddle_right_action == paddle_action::CONTROL) {
				float x = std::stof(players[1].substr(3, 4)) / 10000.f;
				float y = std::stof(players[1].substr(7, 4)) / 10000.f;
				paddle_right->position.x = x;
				paddle_right->position.y = y;
			}

			//Reject if object size not equal to one
			if (objects.size() != 1) {
				std::cerr << "I don't know what to do with " << players.size() << " objects" << std::endl;
				return;
			}

			//Ball movement
			float x = std::stof(objects[0].substr(3, 4)) / 10000.f;
			float y = std::stof(objects[0].substr(7, 4)) / 10000.f;
			ball->position.x = x;
			ball->position.y = y;
		}
	}
}

