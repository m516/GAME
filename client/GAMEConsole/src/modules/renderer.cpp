#include "renderer.h"

#include "../GUI/Menu/menuItem.h"
#include "../GUI/Menu/menuPane.h"

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
    //Initial Menu test
	//MenuItem item = new MenuItem(&theme, "Test Item", NULL);
    MenuItem menuItem2(theme, "Don't pick me!", NULL);
	menuItem2.selected = 1;
    
	MenuItem menuItem(theme, "Pick me!", NULL);
	menuItem.selected = 0;

	MenuPane menu(5);
	menu.setPosition(100, 100);
	menu.setSize(200, 32);
	menu.setRenderer(window);
	menu.addItem(menuItem);
	menu.addItem(menuItem2);
    
	//Activate the window in this threadd
	window->setActive(true);
    
	while (window->isOpen())
	{
		window->clear();
		sf::CircleShape shape(100.f);
		window->draw(shape);

		menu.update();
		menu.render();
		window->display();
	}
}