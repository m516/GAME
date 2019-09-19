#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <thread>
#include <chrono>
#include <X11/Xlib.h>

bool temp = true;
float x = 0;
float y = 0;
float delta = 0;
sf::Font font;
sf::Clock myClock;

void EventHandler(sf::RenderWindow &);
void Renderer(sf::RenderWindow &);
sf::View getLetterboxView(sf::View, int, int);
void Rainbow(sf::RectangleShape &, sf::RenderWindow &);

sf::RectangleShape rect(sf::Vector2f(20.f, 20.f));

uint32_t color_palette[16] = {
	0xFFffffff,
	0xFF6df7c1,
	0xFF11adc1,
	0xFF606c81,
	0xFF393457,
	0xFF1e8875,
	0xFF5bb361,
	0xFFa1e55a,
	0xFFf7e476,
	0xFFf99252,
	0xFFcb4d68,
	0xFF6a3771,
	0xFFc92464,
	0xFFf48cb6,
	0xFFf7b69e,
	0xFF9b9c82
};

// Testing stuff
int main()
{
	// Need this to do threading with X
	XInitThreads();
	// Create a window with rendoring
	sf::RenderWindow window(sf::VideoMode(256, 256), "G.A.M.E.", sf::Style::Default);
	
	int screenWidth = sf::VideoMode::getDesktopMode().width;
	int screenHeight = sf::VideoMode::getDesktopMode().height;
	window.setPosition(sf::Vector2i(screenWidth / 2, screenHeight / 2));
	
	// window.setFramerateLimit(120);
	// Load font
	font.loadFromFile("bitwise.ttf");

	// Scale window up
	window.setSize(sf::Vector2u(1920, 1080));
	
	// Keep running while the app runs
	// Need std::ref to pass by reference
	// std::thread thread_obj(EventHandler, std::ref(window));
	std::thread thread_obj2(Renderer, std::ref(window));
	std::thread thread_obj1(Rainbow, std::ref(rect), std::ref(window));
	// thread_obj.join();

	while (window.isOpen())
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
		EventHandler(window);
	}

	return 0;
}

// https://github.com/SFML/SFML/wiki/Source:-Letterbox-effect-using-a-view
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
    if (windowRatio < viewRatio)
        horizontalSpacing = false;

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

    view.setViewport( sf::FloatRect(posX, posY, sizeX, sizeY) );

    return view;
}

sf::View view;
const sf::Time timePerFrame = sf::milliseconds(1.f); // 1/60 ~ 60FPS
sf::Time timeSinceLastUpdate = sf::Time::Zero;

void Rainbow(sf::RectangleShape &rect, sf::RenderWindow &window)
{
	int i = 0;
	while (true)
	{
		if (i >= 16)
		{
			i = 0;
		}

		std::this_thread::sleep_for(std::chrono::seconds(1));
		rect.setFillColor(sf::Color(color_palette[i]));

		i++;
	}
}

void Renderer(sf::RenderWindow &window)
{
	sf::Clock framerate;

	view.setSize(256, 256);
	view.setCenter(128, 128);
	view = getLetterboxView(view, 256, 256);

	while (window.isOpen())
	{
		// Calculate time since last updated frame
		sf::Time elapsedTime = myClock.restart();
		timeSinceLastUpdate += elapsedTime;
		std::this_thread::sleep_for(std::chrono::milliseconds(1));

		// Update frame
		while (timeSinceLastUpdate > timePerFrame)
		{
			delta = timeSinceLastUpdate.asSeconds();
			window.clear(sf::Color(100, 100, 100));
			window.setView(view);

			sf::Vector2u windowSize = window.getSize();
			
			sf::Vector2f movePos(x, y);
			rect.setPosition(movePos * delta);

			// Draw welcome text
			sf::Text text;
			text.setFont(font);
			text.setString("Welcome to G.A.M.E.");
			text.setPosition(100, 50);
			text.setCharacterSize(12); // In Pixels
			text.setFillColor(sf::Color::White);
			window.draw(text);

			if (temp)
			{
				// Change text and draw
				text.setString("Option 1");
				text.setPosition(100, 100);
				window.draw(text);
				// Change rectangle color & draw
				// rect.setFillColor(sf::Color(100, 250, 50));
				window.draw(rect);
			}
			else
			{
				text.setString("Option 2");
				text.setPosition(100, 150);
				window.draw(text);
				// rect.setFillColor(sf::Color(250, 100, 50));
				window.draw(rect);
			}


			// Display the window
			window.display();
		}
	}
}

// Event handler with window passed by -reference-
void EventHandler(sf::RenderWindow &window)
{
	sf::Event event;
	while (window.pollEvent(event)) /// While events are "queued"
	{
		if (event.type == sf::Event::Resized)
		{
			view = getLetterboxView(view, event.size.width, event.size.height);
		}

		// Key Down
		if (event.type == sf::Event::KeyPressed)
		{
			float speed = 100;
			switch (event.key.code)
			{
				// ENTER
				case sf::Keyboard::Enter:
					temp = !temp;
					break;
				// CONTROLS	
				case sf::Keyboard::Right:
					x += speed;	
					break;
				case sf::Keyboard::Left:
					x -= speed;
					break;
				case sf::Keyboard::Up:
					y -= speed;
					break;
				case sf::Keyboard::Down:
					y += speed;
					break;
			}
		}

		// Terminate program
		if (event.type == sf::Event::Closed)
			window.close();
	}
}