#include "mainMenu.h"


MainMenu::MainMenu(sf::RenderWindow* window, Theme* theme = 0)
{
	//Set the renderer
	renderer = window;
	this->theme = theme;

	//Initialize a new theme if necessary
	if (theme == NULL)  theme = new Theme();

	// Create main menu
	title = new sf::Text();
	title->setCharacterSize(66);
	title->setFont(theme->font_standard);
	title->setColor(theme->color_selected);
	title->setString("G.A.M.E.");
	title->setPosition(5, 5);

	menu = new MenuPane(5, window);
	menu->setPosition(5, 90);
	menu->setSize(150, 150);

	MenuItem item(theme, "PLAY", NULL);
	item.setPressedFunction(std::bind(&MainMenu::play, this));
	menu->addItem(item);

	item = MenuItem(theme, "PARTY", NULL);
	menu->addItem(item);

	item = MenuItem(theme, "FRIENDS", NULL);
	menu->addItem(item);

	item = MenuItem(theme, "PROFILE", NULL);
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
	if (renderer != NULL) {
		renderer->draw(*title);
		menu->update();
		menu->render();
	}
}

void MainMenu::play() {
	//Create Pong instance
	Pong* pong_game = new Pong();
	pong_game->setPosition(0, 0);
	pong_game->setSize((float)(renderer->getSize().x), 
		(float)(renderer->getSize().y));
	pong_game->setRenderer(renderer);
	pong_game->setTheme(theme);

	pong_game->lockRender();
	delete pong_game;
}