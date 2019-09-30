#include "theme.h"


void Theme::loadGenericFont() {
	font_standard.loadFromFile("/usr/share/fonts/truetype/liberation/LiberationMono-Regular.ttf");
}

Theme Theme::clone() {
	Theme newTheme;
	newTheme.border_size = border_size;
	newTheme.color_border = color_border;
	newTheme.font_standard = font_standard;
	newTheme.color_deselected = color_deselected;
	newTheme.color_selected = newTheme.color_selected;
	return newTheme;
}