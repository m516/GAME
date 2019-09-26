
//Source: https://riptutorial.com/sfml

#include <SFML/Graphics.hpp>
#include <thread>
#include <chrono>

int x = 0;
sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!", sf::Style::Fullscreen);


int gameThread() {
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	printf("%d %d", window.getSize().x, window.getSize().y);

	while (window.isOpen()) {
		x++;
		if (x >= 800)x = 0;
		std::this_thread::sleep_for(std::chrono::milliseconds(30));
	}
}


int main()
{
	
	sf::CircleShape shape(50.f);
	shape.setFillColor(sf::Color::Green);

	std::thread mechanicsThread(gameThread);



	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		
		shape.setPosition(x, 0);

		window.clear(sf::Color::Magenta);
		window.draw(shape);
		window.display();
	}

	return 0;
}
