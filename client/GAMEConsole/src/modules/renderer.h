#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "../application.h"
#include "../GUI/theme.h"
#include "../games/pong/pong.h"
#include "../GUI/menu/mainMenu.h"

class Renderer 
{
	public:
		Renderer(Application *app);
		~Renderer();

        void start();
        void renderLoop();
		sf::View getLetterboxView(sf::View view, int windowWidth, int windowHeight);

		//Graphics-related fields
		Application* application;
		Theme* theme;
		sf::RenderWindow* window;
	private:

		MainMenu* main_menu = 0;
};