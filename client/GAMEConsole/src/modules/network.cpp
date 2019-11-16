#include "network.h"

#include <SFML/Network.hpp>

#include <thread>
#include <iostream>

Network::Network(Application *app)
{
    application = app;
	//window = &app->window;
}

/** 
 * Start the rendering thread 
 */
void Network::start()
{
	std::thread* networkThread = new std::thread(&Network::networkLoop, this);
}

/** 
 * Main render thread
 */
void Network::networkLoop()
{

}