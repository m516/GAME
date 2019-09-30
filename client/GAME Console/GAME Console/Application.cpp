#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Application.h"
#include "GUI/Menu/menuItem.h"


Application::Application(){

}

int Application::initialize(){
	//Establish a new window
	//window = new sf::RenderWindow(sf::VideoMode(200, 200), "Hello");

	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	window = new sf::RenderWindow(sf::VideoMode(800, 600), "Testing...", sf::Style::Default, settings);

	//Create a test shape
	shape = new sf::CircleShape(100.f);
	shape->setFillColor(sf::Color::Green);

	return 0;
}


int Application::run() {
	//Initial MenuItem test
	MenuItem menuItem("Pick me!", NULL);
	menuItem.setPosition(10, 10);
	menuItem.setSize(180, 32);
	menuItem.selected = 0;

	while (window->isOpen())
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();
		}

		window->clear();
		window->draw(*shape);
		menuItem.render(window);
		window->display();
	}
}