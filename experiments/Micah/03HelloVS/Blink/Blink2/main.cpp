
/*#include <wiringPi.h>

// LED Pin - wiringPi pin 0 is BCM_GPIO 17.
// we have to use BCM numbering when initializing with wiringPiSetupSys
// when choosing a different pin number please use the BCM numbering, also
// update the Property Pages - Build Events - Remote Post-Build Event command 
// which uses gpio export for setup for wiringPiSetupSys
#define	LED	17

int main(void)
{
	wiringPiSetupSys();

	pinMode(LED, OUTPUT);

	while (true)
	{
		digitalWrite(LED, HIGH);  // On
		delay(500); // ms
		digitalWrite(LED, LOW);	  // Off
		delay(500);
	}
	return 0;
}
*/
//Source: https://riptutorial.com/sfml

#include <SFML/Graphics.hpp>

int x = 0;

int main()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape shape(50.f);


	shape.setFillColor(sf::Color::Green);


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			shape.setPosition(x++, 0);
			if (x >= 200)x = 0;
		}

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}
