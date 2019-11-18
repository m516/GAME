#include "profileMenu.h"

ProfileMenu::ProfileMenu(sf::RenderWindow* window, Theme* theme)
{
    renderer = window;
    this->theme = theme == NULL ? new Theme() : theme;

    levelSquare.setSize(sf::Vector2f(25.f, 25.f));
    levelSquare.setPosition(5, 5);
    levelSquare.setFillColor(sf::Color::Blue);

	title.setCharacterSize(24);
	title.setFont(theme->font_standard);
	title.setColor(theme->color_selected);
	title.setString("ASTRELION");
	title.setPosition(5, 20);
    title = theme->sharpenText(title);

    username.setCharacterSize(12);
    username.setFont(theme->font_standard);
    username.setColor(theme->color_selected);
    username.setString("ASTRELION");
    username.setPosition(5, 50);
    username = theme->sharpenText(username);
}

ProfileMenu::~ProfileMenu()
{
    
}

void ProfileMenu::render()
{
	if (renderer != NULL) 
    {
        renderer->draw(levelSquare);
		renderer->draw(title);
        renderer->draw(username);
	}
}