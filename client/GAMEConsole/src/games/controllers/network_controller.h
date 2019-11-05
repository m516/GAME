#pragma once

#include <websocketpp/config/asio_no_tls_client.hpp>
#include <websocketpp/client.hpp>
#include <iostream>

#include "controller.h"

#define SERVER_URI "ws://coms-309-sr-5.misc.iastate.edu:8080"

//Define websocket client type
typedef websocketpp::client<websocketpp::config::asio_client> client_t;
//Define message type
typedef websocketpp::config::asio_client::message_type::ptr message_ptr;

//Include some networking stuff
using websocketpp::lib::placeholders::_1;
using websocketpp::lib::placeholders::_2;
using websocketpp::lib::bind;


class NetworkController : public Controller {
public:

	NetworkController();

	int initialize();

	void onOpen(client_t* c, websocketpp::connection_hdl hdl);

	void onFail(client_t* c, websocketpp::connection_hdl hdl);

	void onMessage(client_t* c, websocketpp::connection_hdl hdl, message_ptr msg);

	void onClose(client_t* c, websocketpp::connection_hdl hdl);

	virtual int update();

protected:
	client_t client;
};