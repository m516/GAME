#include "profileMenu.h"

ProfileMenu::ProfileMenu(sf::RenderWindow* window, Theme* theme)
{
    renderer = window;
    this->theme = theme == NULL ? new Theme() : theme;

    // Create main menu
	title.setCharacterSize(32);
	title.setFont(theme->font_standard);
	title.setColor(theme->color_selected);
	title.setString("User Profile");
	title.setPosition(5, 5);
    title = theme->sharpenText(title);
}

ProfileMenu::~ProfileMenu()
{
    
}

void ProfileMenu::render()
{
	if (renderer != NULL) 
    {
		renderer->draw(title);
	}
}