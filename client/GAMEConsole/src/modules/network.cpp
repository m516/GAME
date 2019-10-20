#include "network.h"

#include <thread>
#include <iostream>

Network::Network(Application *app)
{
    application = app;
    window = application->window;
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
    std::cout << "Running..." << std::endl;
	sf::UdpSocket socket;
	sf::IpAddress ip("10.24.226.130"); // 10.24.226.130
	unsigned short port = 8080;
	//if (socket.bind(port) != sf::Socket::Done) std::cout << "Could not bind." << std::endl;
	char data[6] = "hello";
	int i = 0;

	//while (w->isOpen())
	while (false)
	{
		if (socket.send(data, sizeof(data), ip, port) != sf::Socket::Done)
		{
			std::cout << "Cannot connect" << std::endl;
		}
		else
		{
			std::cout << "Sent " << i++ << std::endl;
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}
}