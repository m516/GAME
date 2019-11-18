#include "mainMenu.h"

#include "profileMenu.h"

MainMenu::MainMenu(sf::RenderWindow* window, Theme* theme = 0)
{
	// set the renderer
	renderer = window;
    this->theme = theme == NULL ? new Theme() : theme;

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
    item.setPressedFunction(std::bind(&MainMenu::profile, this));
	menu->addItem(item);

	item = MenuItem(theme, "SETTINGS", NULL);
	menu->addItem(item);

	pong_game = 0;
}

MainMenu::~MainMenu()
{
	delete menu;
	delete title;
	delete pong_game;
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

void MainMenu::play() 
{
	if (pong_game != NULL) delete pong_game;

	//Create Pong instance
	pong_game = new Pong();
	pong_game->setPosition(0, 0);
	pong_game->setSize((float)(renderer->getSize().x), 
		(float)(renderer->getSize().y));
	pong_game->setRenderer(renderer);
	pong_game->setTheme(theme);

	pong_game->lockRender();
}

void MainMenu::profile()
{
    ProfileMenu* profileMenu = new ProfileMenu(renderer, theme);
    profileMenu->lockRender();
}