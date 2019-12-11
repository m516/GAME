#include "theme.h"
#include <iostream>

Theme* Theme::universal_theme = new Theme();

Theme::Theme()
{
    userFont = 0;

    // Load all fonts into font vector
    for (int i = 0; i < fontFiles.size(); i++)
    {
        sf::Font font;
        font.loadFromFile(fontDirectory + fontFiles[i]);
        fonts.push_back(sf::Font(font));
    }
}

/**
 * Get the set user's font
 */
sf::Font Theme::getUserFont()
{
    return fonts.at(userFont);
}

/**
 * Set the new font
 */
void Theme::setUserFont(int f)
{
    userFont = f;
}

/**
 * Set font standard to Alien-Encounters-Regular.ttf
 */
bool Theme::loadGenericFont()
{
    font_standard = fonts.at(userFont);
    return true;
	// return font_standard.loadFromFile("assets/fonts/bitwise.ttf");
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