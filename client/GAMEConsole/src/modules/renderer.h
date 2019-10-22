#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "../application.h"
#include "../GUI/theme.h"

class Renderer 
{
	public:
        Application* application;
        Theme* theme;
		sf::RenderWindow* window;
		// Functions
		Renderer(Application *app);
        void start();
        void renderLoop();
		sf::View getLetterboxView(sf::View view, int windowWidth, int windowHeight);
	private:
	protected:
};