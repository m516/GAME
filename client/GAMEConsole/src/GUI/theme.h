#pragma once
#include <SFML/Graphics.hpp>

class Theme {
public:
	sf::Color color_selected = sf::Color::White;
	sf::Color color_deselected = sf::Color::Black;
	sf::Color color_border = sf::Color::White;
	float border_size = 1.0;
	sf::Font font_standard;
	/** test header */
	void loadGenericFont();
	Theme clone();
};