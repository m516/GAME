#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "GUI/theme.h"

class Application {
public:
	Application();
	sf::RenderWindow* window;
	Theme theme;
	int run();
private:
	// sf::CircleShape* shape;
};
