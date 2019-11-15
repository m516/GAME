#include "renderer.h"

#include "../GUI/menu/menuItem.h"
#include "../GUI/menu/menuPane.h"
#include "../games/pong/pong.h"
#include "../GUI/panel.h"
#include "events.h"

#include <thread>
#include <iostream>
#include <chrono>

Renderer::Renderer(Application *app)
{
    application = app;
	window = app->window;
	theme = &app->theme;
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
	// Init window
	sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
	sf::View view;
    view.setSize(256, 256);
    view.setCenter(128, 128);
    view = getLetterboxView(view, desktop.width, desktop.height);
    window->setView(view);
	
	Pong pong_game;
	pong_game.setPosition(0, 0);
	pong_game.setSize((float)(window->getSize().x), (float)(window->getSize().y));
	pong_game.setRenderer(window);
	pong_game.setTheme(theme);

	// Create main menu
	sf::Text title;
	title.setFont(theme->font_standard);
	title.setCharacterSize(66);
	title = theme->sharpenText(title);
	title.setString("G.A.M.E.");
	title.setPosition(5, 5);

	MenuPane mainMenu(5, window);
	mainMenu.setPosition(5, 90);
	mainMenu.setSize(150, 150);

	std::vector<std::string> menuItems = {"PLAY", "PARTY", "FRIENDS", "PROFILE", "SETTINGS"};
	for (unsigned int i = 0; i < menuItems.size(); i++)
	{
		MenuItem item(theme, menuItems[i], NULL);
		item.selected = i == 0 ? 1 : 0;
		item.setPosition(0, (float)(25 * i));
		mainMenu.addItem(item);
	}

	application->events->panes.push_back(&mainMenu);

	while (window->isOpen())
	{
		sf::Time elapsedTime = frameClock.restart();
		timeSinceLastFrame += elapsedTime;
		std::this_thread::sleep_for(std::chrono::milliseconds(FRAME_TIME.asMilliseconds()));

		while (timeSinceLastFrame > FRAME_TIME)
		{
			timeSinceLastFrame = sf::Time::Zero;
			window->clear();

			if (mainMenu.selected == 3)
			{
				pong_game.setSize(window->getView().getSize().x, window->getView().getSize().y);
				pong_game.update();
				pong_game.render();
			}
			else
			{
				window->draw(title);
				mainMenu.update();
				mainMenu.render();
			}
			
			window->display();
		}
	}
}

void testFunc()
{
	std::cout << "Hey!" << std::endl;
}

/**
 * Returns a view with black boxes to keep aspect ratio.
 * https://github.com/SFML/SFML/wiki/Source:-Letterbox-effect-using-a-view
 */
sf::View Renderer::getLetterboxView(sf::View view, int windowWidth, int windowHeight) 
{
    // Compares the aspect ratio of the window to the aspect ratio of the view,
    // and sets the view's viewport accordingly in order to archieve a letterbox effect.
    // A new view (with a new viewport set) is returned.
    float windowRatio = windowWidth / (float) (windowHeight);
    float viewRatio = view.getSize().x / view.getSize().y;
    float sizeX = 1;
    float sizeY = 1;
    float posX = 0;
    float posY = 0;

    bool horizontalSpacing = true;
    if (windowRatio < viewRatio) horizontalSpacing = false;

    // If horizontalSpacing is true, the black bars will appear on the left and right side.
    // Otherwise, the black bars will appear on the top and bottom.
    if (horizontalSpacing) // Right/left bars
	{
        sizeX = viewRatio / windowRatio;
        posX = (1 - sizeX) / 2.f;
    }
    else // Top/bottom bars
	{
        sizeY = windowRatio / viewRatio;
        posY = (1 - sizeY) / 2.f;
    }

    view.setViewport(sf::FloatRect(posX, posY, sizeX, sizeY));
    return view;
}
