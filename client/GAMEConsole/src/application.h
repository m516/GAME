#pragma once

#include <SFML/Graphics.hpp>


#include "GUI/theme.h"

class Renderer;
class Network;
class Events;


class Application 
{
	public:
		Application();

		// Functions
		void run();

		sf::RenderWindow* window;
		Theme theme;
		Renderer* renderer;
		Events* events;
};
