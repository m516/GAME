#pragma once
#include <SFML/Graphics.hpp>

class Theme {
public:
	sf::Color color_selected = sf::Color(255, 255, 255);
	sf::Color color_deselected = sf::Color(64, 64, 64);
	sf::Color color_background = sf::Color::Black;
	sf::Color color_border = color_selected;
	float border_size = 1.0;
	int sharpenFactor = 2;
	sf::Font font_standard;
	/** test header */
	Theme();
	void loadGenericFont();
	sf::Text sharpenText(sf::Text text);
	Theme clone();
};