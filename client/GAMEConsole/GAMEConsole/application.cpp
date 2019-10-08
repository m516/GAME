#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "GUI/Menu/menuItem.h"
#include "GUI/Menu/menuPane.h"
#include "GUI/theme.h"

#include "cereal/archives/json.hpp"

#include "application.h"


Application::Application(){

}

int Application::initialize(){
	//Establish a new windowd
	//window = new sf::RenderWindow(sf::VideoMode(200, 200), "Hello");
	
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	window = new sf::RenderWindow(sf::VideoMode(400, 400), "Testing...", sf::Style::Default, settings);

	//Create a test shape
	shape = new sf::CircleShape(100.f);
	shape->setFillColor(sf::Color::Green);

	//Initialize the generic font for the theme
	theme.loadGenericFont();

	return 0;
}


int Application::run() {
	//Initial Menu test

	MenuItem menuItem2(&theme, "Don't pick me!", NULL);
	menuItem2.selected = 1;
	
	MenuItem menuItem(&theme, "Pick me!", NULL);
	menuItem.selected = 0;

	MenuPane menu(5);
	menu.setPosition(100, 100);
	menu.setSize(200, 32);
	menu.addItem(menuItem);
	menu.addItem(menuItem2);


	

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

		menu.update();
		menu.render(window);
		//menuItem.render(window);
		//menuItem2.render(window);
		window->display();
	}

	return 0;
}