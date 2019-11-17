#include "network.h"

#include <thread>
#include <iostream>


//See https://en.cppreference.com/w/cpp/utility/functional/function

#define SERVER_URI "ws://coms-309-sr-5.misc.iastate.edu:8080"

#define NETWORK_DEBUG


namespace NetworkConnection {




//Connect to server
int NetworkConnection::connect()
{

	//Include some networking stuff
	using websocketpp::lib::placeholders::_1;
	using websocketpp::lib::placeholders::_2;
	using websocketpp::lib::bind;


	//Restart if initialized
	if (network_initialized) disconnect();

	// set logging policy if needed
#ifdef NETWORK_DEBUG
	client.set_access_channels(websocketpp::log::alevel::all);
	client.set_error_channels(websocketpp::log::elevel::all);
#else
	client.clear_access_channels(websocketpp::log::alevel::all);
	client.clear_error_channels(websocketpp::log::elevel::all);
#endif


	//Set listeners
	client.set_open_handler(
		bind(&NetworkConnection::onOpen, &client, _1)
	);
	client.set_fail_handler(
		bind(&NetworkConnection::onFail, &client, _1)
	);
	client.set_close_handler(
		bind(&NetworkConnection::onClose, &client, _1)
	);
	client.set_message_handler(
		bind(&NetworkConnection::onMessage, &client, _1, _2)
	);

	// Initialize ASIO
	client.init_asio();

	//Marks the endpoint as perpetual, stopping it from exiting when empty
	client.start_perpetual();

	websocket_thread = new websocketpp::lib::thread(&client_t::run, &client);

	// Start the ASIO io_service run loop inside a new thread
	client_thread.reset(websocket_thread);

	std::cout << "Network initialized" << std::endl;

	network_initialized = true;

	std::string uri = SERVER_URI;

	try {

		// Create a connection to the given URI and queue it for connection once
		// the event loop starts
		websocketpp::lib::error_code ec;
		client_t::connection_ptr connection = client.get_connection(uri, ec);
		client.connect(connection);

		return 0;
	}
	catch (const std::exception & e) {
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

void disconnect()
{
	client.stop_perpetual();
	websocketpp::lib::error_code ec;
	client.close(connection_hdl, websocketpp::close::status::normal, "Closing connection to server as normal", ec);
	if (ec) {
		std::cout << "> Error closing connection: "
			<< ec.message() << std::endl;
	}
	client_thread->join();

	std::cout << "Connecton closed" << std::endl;

	network_connected = false;
	network_initialized = false;
}

bool isConnected()
{
	return network_connected;
}


void send(std::string message)
{
	try {

#ifdef NETWORK_DEBUG
		std::cout << "NetworkController: Sending " << message << std::endl;
#endif // NETWORK_DEBUG

		client.send(connection_hdl, message, websocketpp::frame::opcode::text);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << '\n';
		network_connected = false;
	}
}

std::string NetworkConnection::getString()
{
	return message;
}


void addListener(Listener listener, std::function<void()> function) {
	listeners[(int)listener].push_back(function);
}



void runFunctions(std::vector<std::function<void()>>* function_list) {
	for (int i = function_list->size() - 1; i >= 0; i--) {
		std::function<void()> f = (*function_list)[i];
		if (f) {
			f();
		}
		else {
			(*function_list).erase((*function_list).begin() + i);
		}
	}
}

//Listeners
void onOpen(client_t* c, websocketpp::connection_hdl hdl)
{
	if (network_connected) {
		std::cout << "Warning! connection_hdl is already set!" << std::endl;
	}
	if (&client == c) {
		connection_hdl = hdl;
		std::cout << "Network connected" << std::endl;
		network_connected = true;
		runFunctions(&listeners[(int)Listener::OPEN]);
	}
	else {
		std::cout << "Error: not the right client!" << std::endl;
	}
}

void onFail(client_t* c, websocketpp::connection_hdl hdl)
{
	if (&client == c) {
		std::cout << "Failure from the right client!" << std::endl;
	}
	else {
		std::cout << "Failure from the wrong client!" << std::endl;
	}
	network_connected = false;
	runFunctions(&listeners[(int)Listener::FAIL]);
}

void onMessage(client_t* c, websocketpp::connection_hdl hdl, message_ptr msg)
{
	message = msg->get_payload();
	std::cout << "Message from client: " << message << std::endl;
	runFunctions(&listeners[(int)Listener::MESSAGE]);
}

void onClose(client_t* c, websocketpp::connection_hdl hdl)
{
	std::cout << "NetworkController: Closing " << std::endl;
	network_connected = false;
	runFunctions(&listeners[(int)Listener::CLOSE]);
}



}