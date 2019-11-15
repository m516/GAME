#include "network.h"

#include <thread>
#include <iostream>

int network_initialize()
{
	return 0;
	//TODO stub
}

void network_onOpen(client_t* c, websocketpp::connection_hdl hdl)
{
	//TODO stub
}

void network_onFail(client_t* c, websocketpp::connection_hdl hdl)
{
	//TODO stub
}

void network_onMessage(client_t* c, websocketpp::connection_hdl hdl, message_ptr msg)
{
	//TODO stub
}

void network_onClose(client_t* c, websocketpp::connection_hdl hdl)
{
	//TODO stub
}

void network_send(std::string message)
{
	//TODO stub
}
