#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

// Testing stuff
int main()
{
	// Create a window with rendoring
	sf::RenderWindow window(sf::VideoMode(800, 800), "My Window", sf::Style::Default);
	window.setTitle("G.A.M.E.");
	// Create a rectangle named "rect"
	sf::RectangleShape rect(sf::Vector2f(120.f, 50.f));
	rect.setFillColor(sf::Color(100, 250, 50));

	// Load font
	sf::Font font;
	font.loadFromFile("BitScript.ttf");

	bool temp = true;
	// Keep running while the app runs
	while (window.isOpen())
	{
		// Close the window on close
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

		// Update Window //
		// Clear window with color black
		window.clear(sf::Color::Black);
		// Draw rectangle
		window.draw(rect);
		sf::Vector2u windowSize = window.getSize();
		sf::Text text;
		text.setFont(font);
		text.setString("Welcome to G.A.M.E.");
		text.setPosition((windowSize.x / 2) - 200, (windowSize.y / 2) - 50);
		text.setCharacterSize(32); // In Pixels
		text.setFillColor(sf::Color::White);
		window.draw(text);

		if (temp)
		{
			text.setString("Option 1");
			text.setPosition(200, 200);
			window.draw(text);
		}
		else
		{
			text.setString("Option 2");
			text.setPosition(200, 300);
			window.draw(text);
		}
		

		// Display the window
		window.display();
	}

	return 0;
}