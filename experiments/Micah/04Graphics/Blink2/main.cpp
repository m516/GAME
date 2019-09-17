
//Source: https://riptutorial.com/sfml

#include <SFML/Graphics.hpp>
#include <thread>
#include <chrono>

int x = 0;
sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");


int gameThread() {
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	

	while (window.isOpen()) {
		x++;
		if (x >= 200)x = 0;
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

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}
