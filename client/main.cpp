#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <thread>
#include <chrono>
#include <X11/Xlib.h>

/** Minimum frame time (1 millisecond)*/
const sf::Time FRAME_TIME = sf::milliseconds(1.f);
/** Time since last frame update */
sf::Time timeSinceLastUpdate = sf::Time::Zero;
/** Map used to create main menu */
std::map<int, std::string> menu;
/** Index of currently selected menu item */
int menuSelection = 0;
/** Main font */
sf::Font font;

void EventHandler(sf::RenderWindow &);
void Renderer(sf::RenderWindow &);
sf::View getLetterboxView(sf::View view, int windowWidth, int WindowHeight);

/**
 * First function to be called
 */
int main()
{
    // Enabled threading with X graphics
    XInitThreads();

    // Create window
    sf::RenderWindow window(
        sf::VideoMode(256, 256),
        "G.A.M.E.",
        sf::Style::Fullscreen
    );
    
    sf::View view;
    view.setSize(256, 256);
    view.setCenter(128, 128);
    view = getLetterboxView(view, 256, 256);
    window.setView(view);
    font.loadFromFile("assets/fonts/alien_encounters/Alien-Encounters-Regular.ttf");

    // Init menu
    menu[0] = "Play";
    menu[1] = "Party";
    menu[2] = "Friends";
    menu[3] = "Profile";
    menu[4] = "Settings";

    // Start renderer
    std::thread renderThread(Renderer, std::ref(window));

    // Event loop
    while (window.isOpen())
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        EventHandler(window);
    }

    return 0;
}

/**
 * Returns a view with black boxes to keep aspect ratio.
 * https://github.com/SFML/SFML/wiki/Source:-Letterbox-effect-using-a-view
 */
sf::View getLetterboxView(sf::View view, int windowWidth, int windowHeight) 
{
    // Compares the aspect ratio of the window to the aspect ratio of the view,
    // and sets the view's viewport accordingly in order to archieve a letterbox effect.
    // A new view (with a new viewport set) is returned.
    float windowRatio = windowWidth / (float) windowHeight;
    float viewRatio = view.getSize().x / (float) view.getSize().y;
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

/**
 * Renders current frame.
 */
void Renderer(sf::RenderWindow &window)
{
    sf::Clock myClock;

    while (window.isOpen())
    {
        // Calculate time since last updated frame
		sf::Time elapsedTime = myClock.restart();
		timeSinceLastUpdate += elapsedTime;
		std::this_thread::sleep_for(std::chrono::milliseconds(1));

        while (timeSinceLastUpdate > FRAME_TIME)
        {
            // Clear window
            window.clear(sf::Color::Black);

            // Draw window border
            sf::RectangleShape border(sf::Vector2f(254, 254));
            border.setPosition(sf::Vector2f(1.f, 1.f));
            border.setOutlineColor(sf::Color::White);
            border.setFillColor(sf::Color::Black);
            border.setOutlineThickness(1.f);
            window.draw(border);

            sf::Text title;
            title.setFont(font);
            title.setCharacterSize(66 * 2);
            title.scale(sf::Vector2f(0.5, 0.5));
            title.setString("G.A.M.E.");
            title.setPosition(5, 5);
            window.draw(title);

            // Draw menu
            for (int i = 0; i < menu.size(); i++)
            {
                sf::Text text;
                text.setFont(font);

                // Move selector
                if (i == menuSelection)
                {
                    sf::RectangleShape shape(sf::Vector2f(3, 25));
                    shape.setPosition(5, 102 + (25 * i));
                    window.draw(shape);

                    text.setStyle(sf::Text::Bold);
                }

                // Draw menu item
                text.setCharacterSize(24 * 2);
                text.scale(sf::Vector2f(0.5, 0.5));
                text.setString(menu[i]);
                text.setPosition(10, 100 + (25 * i));
                window.draw(text);
            }

            // Render objects on window
            window.display();
        }
    }
}

/**
 * Handles window events.
 */
void EventHandler(sf::RenderWindow &window)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::KeyPressed)
        {
            switch (event.key.code)
            {
                case sf::Keyboard::Up:
                    menuSelection--;
                    if (menuSelection < 0) menuSelection = menu.size() - 1;
                    break;
                case sf::Keyboard::Down:
                    menuSelection++;
                    if (menuSelection >= menu.size()) menuSelection = 0;
            }
        }

        // Re-calculate view on resize
        if (event.type == sf::Event::Resized)
        {
            window.setView(
                getLetterboxView(window.getView(), event.size.width, event.size.height)
            );
        }

        // End program on close or escape press
        if (event.type == sf::Event::Closed ||
            (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
        {
            window.close();
        }
    }
}