#include "gameMenu.h"


GameMenu::GameMenu(sf::RenderWindow* window, Game* game, Theme* theme = 0)
{
	//Set the renderer
	renderer = window;
	this->theme = theme;
	this->game = game;

	//Initialize a new theme if necessary
	if (theme == NULL)  theme = Theme::universal_theme;


	// Create main menu
	title = new sf::Text();
	title->setCharacterSize(window->getSize().y/4);
	title->setFont(theme->font_standard);
	title->setColor(theme->color_selected);
	title->setString("Play " + game->getName());
	title->setPosition((window->getSize().x-title->getGlobalBounds().width)/2, 5);

	menu = new MenuPane(5, window);
	menu->setPosition(10, window->getSize().y / 3.f);
	menu->setSize(window->getSize().x - 20, window->getSize().y/3.f);

	MenuItem item(theme, "Online game", NULL);
	item.setPressedFunction(std::bind(&GameMenu::startOnlineGame, this));
	menu->addItem(item);

	item = MenuItem(theme, "Offline game", NULL);
	item.setPressedFunction(std::bind(&GameMenu::startOfflineGame, this));
	menu->addItem(item);

	item = MenuItem(theme, "Spectate", NULL);
	item.setPressedFunction(std::bind(&GameMenu::startSpectateGame, this));
	menu->addItem(item);
}

GameMenu::~GameMenu()
{
	delete menu;
	delete title;
}

void GameMenu::render()
{
	if (renderer != NULL) {
		renderer->draw(*title);
		menu->update();
		menu->render();
	}
}

void GameMenu::startOnlineGame()
{
	//Create Game instance
	game->setPosition(0, 0);
	game->setSize((float)(renderer->getSize().x),
		(float)(renderer->getSize().y));
	game->setRenderer(renderer);
	game->setTheme(theme);

	//Go to join menu
	JoinCreateMenu jcm(renderer, game, theme);
	jcm.lockRender();
	unlockRender();
}

void GameMenu::startOfflineGame()
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
	unlockRender();
}

void GameMenu::startSpectateGame()
{
	
	//Create Game instance
	game->setPosition(0, 0);
	game->setSize((float)(renderer->getSize().x),
		(float)(renderer->getSize().y));
	game->setRenderer(renderer);
	game->setTheme(theme);

	//Initialize in network spectate mode
	game->beginSpectateGame();
	//Begin game
	game->lockRender();
	unlockRender();
}