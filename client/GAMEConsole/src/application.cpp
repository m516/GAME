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
#include "modules/renderer.h"
#include "modules/network.h"
#include "modules/events.h"

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
	theme = new Theme();
	theme->loadGenericFont();
}

void Application::run()
{
	Renderer* renderer = new Renderer(this);
	renderer->start();

	Network* network = new Network(this);
	network->start();

	Events* events = new Events(this);
	events->start();
}