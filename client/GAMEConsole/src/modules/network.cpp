#include "network.h"

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
	/*
	// TCP TESTING //
	sf::TcpSocket socket;
	sf::Socket::Status status = socket.connect(
		"10.24.226.130", 
		8080
	);

	if (status != sf::Socket::Done)
	{
		std::cout << "Cannot connect" << std::endl;
	}
	else
	{
		char data[6] = "hello";
		int numbers = 7;
		//while (true)
		{
			if (socket.send(data, sizeof(data)) != sf::Socket::Done)
			{
				std::cout << "Could not send" << std::endl;
			}
			else
			{
				std::cout << "SENT" << std::endl;
			}

			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		}
	}
	*/

	// UDP TESTING //
	
    std::cout << "Running..." << std::endl;
	sf::UdpSocket socket;
	sf::IpAddress ip("10.24.226.130"); // 10.24.226.130
	unsigned short port = 12345;
	//if (socket.bind(port) != sf::Socket::Done) std::cout << "Could not bind." << std::endl;
	char data[6] = "hello";
	int i = 0;

	//while (w->isOpen())
	while (true)
	{
		sf::Socket::Status result = socket.send(data, sizeof(data), ip, port);
		if (result != sf::Socket::Done)
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