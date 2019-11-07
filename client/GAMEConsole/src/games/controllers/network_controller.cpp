#include "network_controller.h"

//#define NETWORK_DEBUG

//Controls are similar to MenuNavigator

//Initializes the controller
NetworkController::NetworkController() {
	// set logging policy if needed

#ifdef NETWORK_DEBUG
	client.set_access_channels(websocketpp::log::alevel::all);
	client.set_error_channels(websocketpp::log::elevel::all);
#else
	client.clear_access_channels(websocketpp::log::alevel::all);
	client.clear_error_channels(websocketpp::log::elevel::all);
#endif

	// Initialize ASIO
	client.init_asio();

	//Marks the endpoint as perpetual, stopping it from exiting when empty
	client.start_perpetual();

	// Start the ASIO io_service run loop inside a new thread
	client_thread.reset(new websocketpp::lib::thread(&client_t::run, &client));

}

NetworkController::~NetworkController()
{
	client.close(hdl, websocketpp::close::status::normal, "Closing connection to server as normal");
}

int NetworkController::initialize() {
	std::string uri = SERVER_URI;

	try {

		// Create a connection to the given URI and queue it for connection once
		// the event loop starts
		websocketpp::lib::error_code ec;
		client_t::connection_ptr connection = client.get_connection(uri, ec);
		client.connect(connection);

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
// Note that they need to be bound to the client with client.set_xyz_handler()
// before they begin listening, and NetworkController can't do that


void NetworkController::onOpen(client_t* c, websocketpp::connection_hdl hdl) {
	if (c == &client)
	{
		this->hdl = hdl;
		std::cout << "NetworkController: onOpen called with correct client" << std::endl;
	}
	else {
		std::cout << "NetworkController: onOpen called with INCORRECT client; rejecting" << std::endl;
	}
}

void NetworkController::onFail(client_t* c, websocketpp::connection_hdl hdl) {
}

void NetworkController::onMessage(client_t* c, websocketpp::connection_hdl hdl, message_ptr msg) {
}

void NetworkController::onClose(client_t* c, websocketpp::connection_hdl hdl) {
}

//Sends a message to the server
void NetworkController::send(std::string message) {

#ifdef NETWORK_DEBUG
	std::cout << "NetworkController: Sending " << message << std::endl;
#endif // NETWORK_DEBUG

	client.send(hdl, message, websocketpp::frame::opcode::text);
}

/*
dummy update() function 
To be implemented by subclasses if necessary
*/
int NetworkController::update() {
	return 0;
}