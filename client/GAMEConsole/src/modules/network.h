#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include "../application.h"

class Network 
{
	public:
        Application* application;
		sf::RenderWindow* window;
		// Functions
		Network(Application *app);
        void start();
        void networkLoop();
	private:
	protected:
};