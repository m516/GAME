#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "GUI/Menu/menuItem.h"
#include "GUI/Menu/menuPane.h"
#include "GUI/theme.h"
#include "GUI/button.h"

#include <SFML/Network.hpp>

#include "cereal/archives/json.hpp"

#include <thread>
#include <chrono>

#include "application.h"


Application::Application()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	window = new sf::RenderWindow(
		sf::VideoMode(256, 256), 
		"G.A.M.E.", 
		sf::Style::Default, settings
	);

	//Initialize the generic font for the theme
	theme.loadGenericFont();
}

void Application::run() 
{
	// Start render and networking threads
	std::thread renderThread(&Application::initRenderer, this, window);
	std::thread networkThread(&Application::initNetworks, this, window);
	initEvents(window); // Event threads exist on the main thread
}

/**
 * Init the rendering thread
 */
void Application::initRenderer(sf::RenderWindow *w)
{
	//Initial Menu test
	//MenuItem item = new MenuItem(&theme, "Test Item", NULL);
	MenuItem menuItem2(&theme, "Don't pick me!", NULL);
	menuItem2.selected = 1;

	MenuItem menuItem(&theme, "Pick me!", NULL);
	menuItem.selected = 0;

	MenuPane menu(5);
	menu.setPosition(100, 100);
	menu.setSize(200, 32);
	menu.addItem(menuItem);
	menu.addItem(menuItem2);

	while (w->isOpen())
	{
		w->clear();
		sf::CircleShape shape(100.f);
		w->draw(shape);

		menu.update();
		menu.render(w);
		w->display();
	}
}

/**
 * Init the networking thread
 */
void Application::initNetworks(sf::RenderWindow *w)
{
	std::cout << "Running..." << std::endl;
	sf::UdpSocket socket;
	sf::IpAddress ip("10.24.226.130"); // 10.24.226.130
	unsigned short port = 8080;
	//if (socket.bind(port) != sf::Socket::Done) std::cout << "Could not bind." << std::endl;
	char data[6] = "hello";
	int i = 0;

	while (w->isOpen())
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

/**
 * Init the events thread
 */
void Application::initEvents(sf::RenderWindow *w)
{
	//EventHandler eventHandler(w);
	//eventHandler.run();

	while (w->isOpen())
	{
		sf::Event event;
		while (w->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				w->close();
			}
		}
	}
}