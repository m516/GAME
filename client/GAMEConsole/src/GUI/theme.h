#pragma once
#include <SFML/Graphics.hpp>

class Theme {
public:
	sf::Color color_selected = sf::Color::White;
	sf::Color color_deselected = sf::Color::Black;
	sf::Color color_border = sf::Color::White;
	float border_size = 1.0;
	int sharpenFactor = 2;
	sf::Font font_standard;
	/** test header */
	Theme();
	void loadGenericFont();
	sf::Text sharpenText(sf::Text text);
	Theme clone();
};