#include <thread>
#include <chrono>

#include "application.h"
#include "modules/renderer.h"
#include "modules/network.h"
#include "modules/events.h"

Application::Application()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	window = new sf::RenderWindow(
		sf::VideoMode(256, 256),
		"G.A.M.E.",
		sf::Style::Fullscreen, settings
	);

	//Let the hardware synchronize this window to its graphics output
	window->setVerticalSyncEnabled(true);

	//Deactivate the window so it can be used in the render thread
	window->setActive(false);

	//Initialize the generic font for the theme
	theme = new Theme();
	theme->loadGenericFont();
}

/**
 * Start application threads and run the app
 */
void Application::run()
{
	// Start threads
	Renderer* renderer = new Renderer(this);
	renderer->start();
	Network* network = new Network(this);
	network->start();
	Events* events = new Events(this);
	events->start();
}