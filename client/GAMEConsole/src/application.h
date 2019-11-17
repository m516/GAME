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

		sf::RenderWindow* window = 0;
		Theme theme;
		Renderer* renderer = 0;
		Events* events = 0;
};
