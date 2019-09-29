#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class Application {
public:
	Application();
	sf::RenderWindow* window;
	int initialize();
	int run();
private:
	sf::CircleShape* shape;
};
