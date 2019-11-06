#include "network_controller.h"

//Controls are similar to MenuNavigator

//Initializes the controller
NetworkController::NetworkController() {
	initialize();
}

NetworkController::~NetworkController()
{
	client.close(hdl, websocketpp::close::status::normal, "Closing connection to server as normal");
}

int NetworkController::initialize() {
	std::string uri = SERVER_URI;

	try {
		// set logging policy if needed
		client.clear_access_channels(websocketpp::log::alevel::frame_header);
		client.clear_access_channels(websocketpp::log::alevel::frame_payload);
		//c.set_error_channels(websocketpp::log::elevel::none);

		// Initialize ASIO
		client.init_asio();

		// Register our handlers
		client.set_open_handler(
			bind(&NetworkController::onOpen, this, &client, ::_1)
		); 
		client.set_fail_handler(
			bind(&NetworkController::onFail, this, &client, ::_1)
		);
		client.set_close_handler(
			bind(&NetworkController::onClose, this, &client, ::_1)
		);
		client.set_message_handler(
			bind(&NetworkController::onMessage, this, &client, ::_1, ::_2)
		);

		// Create a connection to the given URI and queue it for connection once
		// the event loop starts
		websocketpp::lib::error_code ec;
		client_t::connection_ptr con = client.get_connection(uri, ec);
		client.connect(con);

		// Start the ASIO io_service run loop
		client.run();

		return 0;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
		return 1;
	}
	catch (websocketpp::lib::error_code e) {
		std::cout << e.message() << std::endl;
		return 2;
	}
	catch (...) {
		std::cout << "other exception" << std::endl;
		return 3;
	}
}

// Handlers
// These are dummy methods that can be implemented by subclasses


void NetworkController::onOpen(client_t* c, websocketpp::connection_hdl hdl) {
	if (c == &client) this->hdl = hdl;
}

void NetworkController::onFail(client_t* c, websocketpp::connection_hdl hdl) {
}

void NetworkController::onMessage(client_t* c, websocketpp::connection_hdl hdl, message_ptr msg) {
}

void NetworkController::onClose(client_t* c, websocketpp::connection_hdl hdl) {
}

//Sends a message to the server
void NetworkController::send(std::string message) {
	client.send(hdl, message, websocketpp::frame::opcode::text);
}

/*
dummy update() function 
To be implemented by subclasses if necessary
*/
int NetworkController::update() {
	return 0;
}