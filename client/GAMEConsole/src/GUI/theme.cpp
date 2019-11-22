#include "theme.h"
#include <iostream>

Theme* Theme::universal_theme = new Theme();

Theme::Theme()
{

}

/**
 * Set font standard to Alien-Encounters-Regular.ttf
 */
bool Theme::loadGenericFont()
{
	return font_standard.loadFromFile("assets/fonts/alien_encounters/Alien-Encounters-Regular.ttf");
}

/**
 * Returns this theme as a copy
 */
Theme Theme::clone() 
{
	Theme newTheme;
	newTheme.border_size = border_size;
	newTheme.color_border = color_border;
	newTheme.font_standard = font_standard;
	newTheme.color_deselected = color_deselected;
	newTheme.color_selected = newTheme.color_selected;
	return newTheme;
}

/**
 * Sharpens text by a factor of `sharpenFactor`
 * Sets character size to `original * sharpenFactor` and scales down accordingly
 */
sf::Text Theme::sharpenText(sf::Text text)
{
	text.setCharacterSize(text.getCharacterSize() * sharpenFactor);
	text.scale(sf::Vector2f(1.f / (float)sharpenFactor, 1.f / (float)sharpenFactor));
	return text;
}