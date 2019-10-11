#include "theme.h"

/**
 * Set font standard to Alien-Encounters-Regular.ttf
 */
void Theme::loadGenericFont()
{
	font_standard.loadFromFile("assets/fonts/alien_encounters/Alien-Encounters-Regular.ttf");
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