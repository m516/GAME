#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "../application.h"
#include "../GUI/menu/menuPane.h"

class Events 
{
	public:
        Application* application;
		sf::RenderWindow* window;
		std::vector<MenuPane*> panes;
		// Functions
		Events(Application *app);
        void start();
        void eventLoop();
	private:
	protected:
};