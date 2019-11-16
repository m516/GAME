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
                (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::BackSlash))
			{
				window->close();
			}

            if (event.type == sf::Event::Resized)
            {
				window->setView(application->renderer->getLetterboxView(window->getView(), event.size.width, event.size.height));
            }

			/*
			if (event.type == sf::Event::KeyPressed)
			{
				for (int i = 0; i < panes.size(); i++)
				{
					panes[i]->update();
				}
			}
			*/
		}//end while

		std::this_thread::sleep_for(std::chrono::milliseconds(10));

	}//end while
}//end eventLoop