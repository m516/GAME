#include "network_controller.h"

//Controls are similar to MenuNavigator

//Initializes the controller
NetworkController::NetworkController() {
	initialize();
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
		/*
		client.set_fail_handler(
			&this->on_fail
		);
		client.set_message_handler(
			&this->on_message
		);
		client.set_close_handler(
			&this->on_close
		);
		*/

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
}

void NetworkController::onFail(client_t* c, websocketpp::connection_hdl hdl) {
}

void NetworkController::onMessage(client_t* c, websocketpp::connection_hdl hdl, message_ptr msg) {
}

void NetworkController::onClose(client_t* c, websocketpp::connection_hdl hdl) {
}

/*
dummy update() function 
To be implemented by subclasses if necessary
*/
int NetworkController::update() {
	return 0;
}