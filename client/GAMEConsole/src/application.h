#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "GUI/theme.h"

class Renderer;
class Network;
class Events;

class Application 
{
	public:
		sf::RenderWindow* window;
		Theme theme;
		Renderer* renderer;
		Network* network;
		Events* events;
		// Functions
		Application();
		void run();
	private:
	protected:
};
