#include "renderer.h"

#include "../GUI/Menu/menuItem.h"
#include "../GUI/Menu/menuPane.h"
#include "../games/pong/pong.h"

#include <thread>
#include <iostream>

Renderer::Renderer(Application *app)
{
    application = app;
    window = application->window;
    theme = application->theme;
}

/** 
 * Start the rendering thread 
 */
void Renderer::start()
{
	std::thread* renderThread = new std::thread(&Renderer::renderLoop, this);
}

/** 
 * Main render thread
 */
void Renderer::renderLoop()
{
    //Activate the window in this thread
	window->setActive(true);

	Pong pong_game;
	pong_game.setPosition(0, 0);
	pong_game.setSize(window->getSize().x, window->getSize().y);
	pong_game.setRenderer(window);
	pong_game.initialize();

	sf::CircleShape shape(20.f);

	while (window->isOpen())
	{
		window->clear();
		window->draw(shape);

		pong_game.update();
		pong_game.render();

		window->display();

		std::this_thread::sleep_for(std::chrono::milliseconds(16));
	}
}