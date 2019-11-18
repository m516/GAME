#include "mainMenu.h"

#include "profileMenu.h"

MainMenu::MainMenu(sf::RenderWindow* window, Theme* theme = 0)
{
	// set the renderer
	renderer = window;
	this->theme = theme;

	//Initialize a new theme if necessary
	if (theme == NULL)  theme = Theme::universal_theme;

	// Create main menu
	title = new sf::Text();
	title->setCharacterSize(window->getSize().y / 4);
	title->setFont(theme->font_standard);
	title->setColor(theme->color_selected);
	title->setString("G.A.M.E.");
	title->setPosition((window->getSize().x - title->getGlobalBounds().width) / 2, 5);

	menu = new MenuPane(5, window);
	menu->setPosition(10, window->getSize().y / 3.f);
	menu->setSize(window->getSize().x - 20, window->getSize().y / 3.f);

	MenuItem item(theme, "PLAY", NULL);
	item.setPressedFunction(std::bind(&MainMenu::play, this));
	menu->addItem(item);

	item = MenuItem(theme, "PARTY", NULL);
	menu->addItem(item);

	item = MenuItem(theme, "FRIENDS", NULL);
	menu->addItem(item);

	item = MenuItem(theme, "PROFILE", NULL);
    item.setPressedFunction(std::bind(&MainMenu::profile, this));
	menu->addItem(item);

	item = MenuItem(theme, "SETTINGS", NULL);
	menu->addItem(item);
}

MainMenu::~MainMenu()
{
	delete menu;
	delete title;
}

void MainMenu::render()
{
	if (renderer != NULL) 
    {
		renderer->draw(*title);
		menu->update();
		menu->render();
	}
}

void MainMenu::profile()
{
}

void MainMenu::play() {
	GameSelectionMenu g(renderer, theme);
	g.lockRender();
}