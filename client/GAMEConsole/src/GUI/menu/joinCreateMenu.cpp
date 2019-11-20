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
	item.setPressedFunction(std::bind(&JoinCreateMenu::createGame, this));
	menu->addItem(item);

	item = MenuItem(theme, "Join an existing game", NULL);
	item.setPressedFunction(std::bind(&JoinCreateMenu::joinGame, this));
	menu->addItem(item);

	NetworkConnection::send("?");
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

	if (Session::getStatus() == Session::OnlineGame::Status::AVAILABLE) {
		//Initialize in network mode
		Session::joinGame(Session::currentGame());
		game->setRenderer(renderer);
		game->beginNetworkGame();
		game->lockRender();
		unlockRender();
	}
}

void JoinCreateMenu::joinGame()
{
	//Begin game
	gameID = 0; //TODO get list
}

void JoinCreateMenu::createGame()
{
	Session::createGame(game->getGameType(), game->getNumPlayers());
}