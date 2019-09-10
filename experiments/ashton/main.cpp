#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "My Window", sf::Style::Default);
	sf::RectangleShape rect(sf::Vector2f(120.f, 50.f));
	rect.setFillColor(sf::Color(100, 250, 50));

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color::Black);
		window.draw(rect);
		window.display();
	}

	return 0;
}
