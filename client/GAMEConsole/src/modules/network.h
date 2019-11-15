#pragma once
#include <websocketpp/config/asio_no_tls_client.hpp>
#include <websocketpp/client.hpp>
#include <iostream>

#define NETWORK_SERVER_URI "ws://coms-309-sr-5.misc.iastate.edu:8080"

//Define websocket client type
typedef websocketpp::client<websocketpp::config::asio_client> client_t;
//Define message type
typedef websocketpp::config::asio_client::message_type::ptr message_ptr;
//Define thread type
typedef websocketpp::lib::shared_ptr<websocketpp::lib::thread> thread_t;

//Include some networking stuff
using websocketpp::lib::placeholders::_1;
using websocketpp::lib::placeholders::_2;
using websocketpp::lib::bind;

//See https://en.cppreference.com/w/cpp/utility/functional/function

std::vector<std::function<void()>> onMessage_listeners;

int network_initialize();

void network_onOpen(client_t* c, websocketpp::connection_hdl hdl);

void network_onFail(client_t* c, websocketpp::connection_hdl hdl);

void network_onMessage(client_t* c, websocketpp::connection_hdl hdl, message_ptr msg);

void network_onClose(client_t* c, websocketpp::connection_hdl hdl);

void network_send(std::string message);



thread_t network_client_thread;
client_t network_client;
websocketpp::connection_hdl network_hdl;