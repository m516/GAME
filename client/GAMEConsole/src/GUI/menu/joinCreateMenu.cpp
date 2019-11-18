#include "joinCreateMenu.h"


JoinCreateMenu::JoinCreateMenu(sf::RenderWindow* window, Game* game, Theme* theme = 0)
{
	//Set the renderer
	renderer = window;
	this->theme = theme;
	this->game = game;

	//Initialize a new theme if necessary
	if (theme == NULL)  theme = Theme::universal_theme;


	// Create main menu
	title = new sf::Text();
	title->setCharacterSize(window->getSize().y/6);
	title->setFont(theme->font_standard);
	title->setColor(theme->color_selected);
	title->setString("Create/Join" + game->getName());
	title->setPosition((window->getSize().x-title->getGlobalBounds().width)/2, 5);

	menu = new MenuPane(5, window);
	menu->setPosition(10, window->getSize().y / 3.f);
	menu->setSize(window->getSize().x - 20, window->getSize().y/4.f);

	MenuItem item(theme, "Create a new game", NULL);
	item.setPressedFunction(std::bind(&JoinCreateMenu::startOnlineGame, this));
	menu->addItem(item);

	item = MenuItem(theme, "Join an existing game", NULL);
	item.setPressedFunction(std::bind(&JoinCreateMenu::startOfflineGame, this));
	menu->addItem(item);
}

JoinCreateMenu::~JoinCreateMenu()
{
	delete menu;
	delete title;
}

void JoinCreateMenu::render()
{
	if (renderer != NULL) {
		renderer->draw(*title);
		menu->update();
		menu->render();
	}
}

void JoinCreateMenu::joinGame()
{
	//Create Game instance
	game->setPosition(0, 0);
	game->setSize((float)(renderer->getSize().x),
		(float)(renderer->getSize().y));
	game->setRenderer(renderer);
	game->setTheme(theme);

	//Initialize in network mode
	game->beginNetworkGame();
	//Begin game
	game->lockRender();
}

void JoinCreateMenu::createGame()
{
	//Create Game instance
	game->setPosition(0, 0);
	game->setSize((float)(renderer->getSize().x),
		(float)(renderer->getSize().y));
	game->setRenderer(renderer);
	game->setTheme(theme);

	//Initialize in network mode
	game->beginOfflineGame();
	//Begin game
	game->lockRender();
}
