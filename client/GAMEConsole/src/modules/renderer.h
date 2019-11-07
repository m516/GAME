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
		/** Minimum frame time (essentially highest fps possible)*/
		const sf::Time FRAME_TIME = sf::milliseconds(10.f);
		/** Time since the last time the frame updated */
		sf::Time timeSinceLastFrame = sf::Time::Zero;
		/** Frame clock to use for tracking frame time */
		sf::Clock frameClock;
	protected:
};