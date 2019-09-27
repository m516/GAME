#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Application.h"


Application::Application(){

}

int Application::initialize(){

	window = new sf::RenderWindow(sf::VideoMode(200, 200), "SFML works!");
	shape = new sf::CircleShape(100.f);
	shape->setFillColor(sf::Color::Green);

	

	return 0;
}


int Application::run() {
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
		window->display();
	}
}