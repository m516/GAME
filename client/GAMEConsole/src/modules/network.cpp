#include "network.h"

#include <thread>
#include <iostream>

using namespace NetworkConnection;

//See https://en.cppreference.com/w/cpp/utility/functional/function

std::vector<std::function<void()>> onOpen_listeners;
std::vector<std::function<void()>> onClose_listeners;
std::vector<std::function<void()>> onMessage_listeners;
std::vector<std::function<void()>> onFail_listeners;

bool network_initialized = false;

int NetworkConnection::connect()
{
	if (network_initialized) return 0;



	return 0;
	//TODO stub
}

void NetworkConnection::onOpen(client_t* c, websocketpp::connection_hdl hdl)
{
	//TODO stub
}

void NetworkConnection::onFail(client_t* c, websocketpp::connection_hdl hdl)
{
	//TODO stub
}

void NetworkConnection::onMessage(client_t* c, websocketpp::connection_hdl hdl, message_ptr msg)
{
	//TODO stub
}

void NetworkConnection::onClose(client_t* c, websocketpp::connection_hdl hdl)
{
	//TODO stub
}

void NetworkConnection::send(std::string message)
{
	//TODO stub
}
