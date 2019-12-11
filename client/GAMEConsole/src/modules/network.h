#pragma once

#include <websocketpp/config/asio_no_tls_client.hpp>
#include <websocketpp/client.hpp>
#include <iostream>

#define NETWORK_SERVER_URI "ws://coms-309-sr-5.misc.iastate.edu:8080"

namespace NetworkConnection
{
	//Define websocket client type
	typedef websocketpp::client<websocketpp::config::asio_client> client_t;
	//Define message type
	typedef websocketpp::config::asio_client::message_type::ptr message_ptr;
	//Define thread type
	typedef websocketpp::lib::shared_ptr<websocketpp::lib::thread> thread_t;

	//Number of kinds of listeners
	const size_t num_listeners = 4;

	//The list of listeners
	typedef enum class LISTENER
	{
		OPEN = 0,
		MESSAGE = 1,
		FAIL = 2,
		CLOSE = 3
	} Listener;

	//Add a listener
	std::function<void()>* addListener(Listener listener, std::function<void()> function);
	void onOpen(client_t* c, websocketpp::connection_hdl hdl);
	void onFail(client_t* c, websocketpp::connection_hdl hdl);
	void onMessage(client_t* c, websocketpp::connection_hdl hdl, message_ptr msg);
	void onClose(client_t* c, websocketpp::connection_hdl hdl);

	int connect();
	void disconnect();
	bool isConnected();

	void send(std::string message);

	void runFunctions(std::vector<std::function<void()>>* function_list);

	std::string getString();

	namespace 
    {
		thread_t network_client_thread;
		client_t network_client;
		client_t::connection_ptr connection;
		websocketpp::connection_hdl network_hdl;

		//List of listeners
		std::vector<std::function<void()>> listeners[num_listeners];

		//Network status stuff
		volatile bool network_initialized = false;
		volatile bool network_connected = false;
		volatile bool network_connecting = false;
		std::string message = "";

		//Network fields
		websocketpp::lib::thread* websocket_thread;
		thread_t client_thread;
		client_t* client;
		websocketpp::connection_hdl connection_hdl;
	}
}