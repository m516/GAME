#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <thread>
#include <X11/Xlib.h>

bool temp = true;
void EventHandler(sf::RenderWindow &);

// Testing stuff
int main()
{
	// Need this to do threading with X
	XInitThreads();
	// Create a window with rendoring
	sf::RenderWindow window(sf::VideoMode(256, 256), "G.A.M.E.", sf::Style::Default);

	// Load font
	sf::Font font;
	font.loadFromFile("bitwise.ttf");

	// Scale window up
	window.setSize(sf::Vector2u(1600, 1600));
	
	// Keep running while the app runs
	// Need std::ref to pass by reference
	std::thread thread_obj(EventHandler, std::ref(window));
	// thread_obj.join();
	while (window.isOpen())
	{
		// Update Window //
		// Clear window with color black
		window.clear(sf::Color::Black);
		
		// Get window size
		sf::Vector2u windowSize = window.getSize();

		// Create a rectangle named "rect"
		sf::RectangleShape rect(sf::Vector2f(200.f, 50.f));

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

	return 0;
}

// Event handler with window passed by -reference-
void EventHandler(sf::RenderWindow &window)
{
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event)) /// While events are "queued"
		{
			// Key Down
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Enter)
				{
					temp = !temp;
				}
			}

			// Terminate program
			if (event.type == sf::Event::Closed)
				window.close();
		}
	}
}