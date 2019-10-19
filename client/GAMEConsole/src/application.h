#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "GUI/theme.h"

class Application 
{
	public:
		sf::RenderWindow* window;
		Theme theme;
		// Functions
		Application();
		int run();
		void initEvents();
		void render(sf::RenderWindow *win);
	private:
		sf::CircleShape* shape;
};
