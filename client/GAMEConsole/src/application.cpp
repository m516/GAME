#include <thread>
#include <chrono>

#include "application.h"
#include "modules/renderer.h"
#include "modules/events.h"
#include "modules/network.h"

Application::Application()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	
	window = new sf::RenderWindow(
		sf::VideoMode(800, 480),
		"G.A.M.E.",
		sf::Style::Default, 
		settings
	);

	//Let the hardware synchronize this window to its graphics output
	window->setVerticalSyncEnabled(true);

	//Deactivate the window so it can be used in the render thread
	window->setActive(false);

	//Initialize the generic font for the theme
	theme.border_size = 0;
	theme.color_border = sf::Color::Black;
	theme.color_deselected = sf::Color::Black;
	theme.color_selected = sf::Color::White;
	theme.loadGenericFont();
}

/**
 * Start application threads and run the app
 */
void Application::run()
{
	renderer = new Renderer(this);
	events = new Events(this);
	network = new Network(this);

	renderer->start();
    network->start();
	events->start(); // Events must start last
}