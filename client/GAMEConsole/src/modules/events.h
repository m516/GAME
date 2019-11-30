#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "../application.h"

class Events 
{
	public:
        Application* application;
		sf::RenderWindow* window;
		// Functions
		Events(Application *app);
        void start();
        void eventLoop();
};