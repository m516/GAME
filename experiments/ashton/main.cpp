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


// Testing stuff
int main()
{
	// Need this to do threading with X
	XInitThreads();
	// Create a window with rendoring
	sf::RenderWindow window(sf::VideoMode(256, 256), "G.A.M.E.", sf::Style::Default);

	// Load font
	
	font.loadFromFile("bitwise.ttf");

	// Scale window up
	window.setSize(sf::Vector2u(1600, 1600));
	
	// Keep running while the app runs
	// Need std::ref to pass by reference
	std::thread thread_obj(EventHandler, std::ref(window));
	std::thread thread_obj2(Renderer, std::ref(window));
	// thread_obj.join();

	while (window.isOpen())
	{
		
	}

	return 0;
}

void Renderer(sf::RenderWindow &window)
{
	sf::Clock framerate;

	do
	{
		if (framerate.getElapsedTime().asMilliseconds() > 1/60)
		{
			delta = 1000.f / myClock.restart().asMicroseconds();
			framerate.restart();
			// Get window size
			sf::Vector2u windowSize = window.getSize();

			// Create a rectangle named "rect"
			sf::RectangleShape rect(sf::Vector2f(20.f, 20.f));
			rect.setFillColor(sf::Color::Green);
			
			window.clear(sf::Color::Black);
			
		
			rect.move(sf::Vector2f(
				x,
				y
			));

			// Draw welcome text
			sf::Text text;
			text.setFont(font);
			text.setString("Welcome to G.A.M.E.");
			text.setPosition((windowSize.x / 2) - 200, (windowSize.y / 2) - 50);
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
				rect.setFillColor(sf::Color(100, 250, 50));
				window.draw(rect);
			}
			else
			{
				text.setString("Option 2");
				text.setPosition(100, 150);
				window.draw(text);
				rect.setFillColor(sf::Color(250, 100, 50));
				window.draw(rect);
			}

			// Display the window
			window.display();
		}
		
	}
	while (window.isOpen());
}

// Event handler with window passed by -reference-
void EventHandler(sf::RenderWindow &window)
{
	sf::Event event;
	while (window.isOpen())
	{
		while (window.pollEvent(event)) /// While events are "queued"
		{
			// Key Down
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Enter)
				{
					temp = !temp;
				}

				float speed = 10;
				switch (event.key.code)
				{
					case sf::Keyboard::Right:
						x += speed * delta;	
						break;
					case sf::Keyboard::Left:
						x -= speed * delta;
						break;
					case sf::Keyboard::Up:
						y -= speed * delta;
						break;
					case sf::Keyboard::Down:
						y += speed * delta;
						break;
				}
			}

			// Terminate program
			if (event.type == sf::Event::Closed)
				window.close();
		}
	}
}