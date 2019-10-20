#include "events.h"

#include <thread>
#include <iostream>

Events::Events(Application *app)
{
    application = app;
    window = application->window;
}

/** 
 * Start the rendering thread 
 */
void Events::start()
{
	eventLoop();
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
			if (event.type == sf::Event::Closed)
			{
				window->close();
			}
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(16));
	}
}