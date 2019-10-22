#include "events.h"

#include <thread>
#include <iostream>
#include "renderer.h"

Events::Events(Application *app)
{
    application = app;
	window = app->window;
}

/** 
 * Start the rendering thread 
 */
void Events::start()
{
	eventLoop(); // Use main thread for events
}

/** 
 * Main render thread
 */
void Events::eventLoop()
{
    while (window->isOpen())
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed ||
                (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
			{
				window->close();
			}

            if (event.type == sf::Event::Resized)
            {
				Renderer* r = application->renderer;
				window->setView(r->getLetterboxView(window->getView(), event.size.width, event.size.height));
            }
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(16));
	}
}