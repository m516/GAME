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
	window.setFramerateLimit(120);
	// Load font
	
	font.loadFromFile("bitwise.ttf");

	// Scale window up
	window.setSize(sf::Vector2u(1600, 1600));
	
	// Keep running while the app runs
	// Need std::ref to pass by reference
	// std::thread thread_obj(EventHandler, std::ref(window));
	std::thread thread_obj2(Renderer, std::ref(window));
	// thread_obj.join();

	while (window.isOpen())
	{
		EventHandler(window);
	}

	return 0;
}

const sf::Time timePerFrame = sf::seconds(1.f/60.f); // 1/60 ~ 60FPS
sf::Time timeSinceLastUpdate = sf::Time::Zero;

void Renderer(sf::RenderWindow &window)
{
	sf::Clock framerate;

	while (window.isOpen())
	{
		// Calculate time since last updated frame
		sf::Time elapsedTime = myClock.restart();
		timeSinceLastUpdate += elapsedTime;

		// Update frame
		while (timeSinceLastUpdate > timePerFrame)
		{
			delta = timeSinceLastUpdate.asSeconds();
			window.clear(sf::Color::Black);

			sf::Vector2u windowSize = window.getSize();

			sf::RectangleShape rect(sf::Vector2f(20.f, 20.f));
			rect.setFillColor(sf::Color::Green);
			
			sf::Vector2f movePos(x, y);
			rect.move(movePos * delta);

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
}

// Event handler with window passed by -reference-
void EventHandler(sf::RenderWindow &window)
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

			float speed = 100;
			switch (event.key.code)
			{
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