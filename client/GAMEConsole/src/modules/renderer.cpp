#include "renderer.h"

#include "../GUI/menu/components/menuItem.h"
#include "../GUI/menu/components/menuPane.h"
#include "../GUI/menu/menu.h"
#include "events.h"

#include <thread>
#include <iostream>
#include <chrono>

Renderer::Renderer(Application *app)
{
    application = app;
	window = app->window;
	theme = &app->theme;

	main_menu = new MainMenu(window, theme);
}

Renderer::~Renderer()
{
	delete main_menu;
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
	main_menu->lockRender();
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
