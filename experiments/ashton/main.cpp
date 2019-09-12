#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <thread>
#include <X11/Xlib.h>

void EventHandler(sf::RenderWindow &);

bool temp = true;

// Testing stuff
int main()
{
	XInitThreads();
	// Create a window with rendoring
	sf::RenderWindow window(sf::VideoMode(256, 256), "G.A.M.E.", sf::Style::Default);
	// Create a rectangle named "rect"
	sf::RectangleShape rect(sf::Vector2f(200, 50.f));

	// Load font
	sf::Font font;
	// font.loadFromFile("BitScript.ttf");
	font.loadFromFile("bitwise.ttf");
	window.setSize(sf::Vector2u(1600, 1600));
	// bool temp = true;
	// Keep running while the app runs
	std::thread thread_obj(EventHandler, std::ref(window));
	// thread_obj.join();
	while (window.isOpen())
	{
		// Close the window on close
		

		// Update Window //
		// Clear window with color black
		window.clear(sf::Color::Black);
		
		// Get window size
		sf::Vector2u windowSize = window.getSize();

		// Draw welcome text
		sf::Text text;
		text.setFont(font);
		text.setString("Welcome to G.A.M.E.");
		text.setPosition((windowSize.x / 2) - 200, (windowSize.y / 2) - 50);
		text.setCharacterSize(32); // In Pixels
		text.setFillColor(sf::Color::White);
		window.draw(text);

		if (temp)
		{
			// Change text and draw
			text.setString("Option 1");
			text.setPosition(200, 200);
			window.draw(text);
			// Change rectangle color & draw
			rect.setFillColor(sf::Color(100, 250, 50));
			window.draw(rect);
		}
		else
		{
			text.setString("Option 2");
			text.setPosition(200, 300);
			window.draw(text);
			rect.setFillColor(sf::Color(250, 100, 50));
			window.draw(rect);
		}

		// Display the window
		window.display();
	}

	return 0;
}

void EventHandler(sf::RenderWindow &window)
{
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Enter)
				{
					temp = !temp;
				}
			}

			if (event.type == sf::Event::Closed)
				window.close();
		}
	}
}