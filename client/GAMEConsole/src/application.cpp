#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "GUI/menu/menuItem.h"
#include "GUI/menu/menuPane.h"
#include "GUI/theme.h"
#include "GUI/button.h"

#include <SFML/Network.hpp>

#include "games/pong/pong.h"

#include "cereal/archives/json.hpp"

#include <thread>
#include <chrono>

#include "application.h"


Application::Application()
{

	shape = new sf::CircleShape(100., 8);

	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	window = new sf::RenderWindow(
		sf::VideoMode(256, 256),
		"G.A.M.E.",
		sf::Style::Default, settings
	);

	//Let the hardware synchronize this window to its graphics output
	window->setVerticalSyncEnabled(true);

	//Deactivate the window so it can be used in the render thread
	window->setActive(false);

	//Initialize the generic font for the theme
	theme.loadGenericFont();
}

void Application::run()
{
	// Start render and networking threads
	std::thread renderThread(&Application::initRenderer, this, window);
	std::thread networkThread(&Application::initNetworks, this, window);

	while (window->isOpen())
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window->close();
			}

		}

		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}
}

/**
 * Init the rendering thread
 */
void Application::initRenderer(sf::RenderWindow *w)
{

	/*
	//Initial Menu test
	//MenuItem item = new MenuItem(&theme, "Test Item", NULL);
	MenuItem menuItem2(&theme, "Don't pick me!", NULL);
	menuItem2.selected = 1;

	MenuItem menuItem(&theme, "Pick me!", NULL);
	menuItem.selected = 0;

	MenuPane menu(5);
	menu.setPosition(100, 100);
	menu.setSize(200, 32);
	menu.setRenderer(w);
	menu.addItem(menuItem);
	menu.addItem(menuItem2);

	//Activate the window in this thread
	w->setActive(true);

	while (w->isOpen())
	{
		w->clear();
		sf::CircleShape shape(100.f);
		w->draw(shape);

		menu.update();
		menu.render();
		w->display();
	}

	*/




	//Activate the window in this thread
	w->setActive(true);

	Pong pong_game;
	pong_game.setPosition(0, 0);
	pong_game.setSize(w->getSize().x, w->getSize().y);
	pong_game.setRenderer(w);
	pong_game.initialize();


	sf::CircleShape shape(20.f);

	while (w->isOpen())
	{
		w->clear();
		w->draw(shape);

		pong_game.update();
		pong_game.render();

		w->display();

		std::this_thread::sleep_for(std::chrono::milliseconds(16));
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