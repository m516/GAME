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
	title->setFillColor(theme->color_selected);
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
	Session::clearGame();
}

void JoinCreateMenu::render()
{
	if (renderer != NULL) 
    {
		renderer->draw(*title);
		menu->update();
		menu->render();
	}

	if (Session::getStatus() == Session::OnlineGame::Status::JOINING) 
    {
		//Initialize in network mode
		game->setRenderer(renderer);
		game->beginNetworkGame();
		game->lockRender();
		unlockRender();
	}

	if (!NetworkConnection::isConnected()) {
		Dialog::show(this, "Network disconnected");
		unlockRender();
	}
}

void JoinCreateMenu::joinGame()
{
	OpenGamesMenu ogm(renderer, game, theme);
	ogm.lockRender();
	if (ogm.selectedID == -1) {
		unlockRender();
		std::cout << "No game selected to join" << std::endl;
		return;
	}
	Session::joinGame(ogm.selectedID);
}

void JoinCreateMenu::createGame()
{
	Session::createGame(game->getGameType(), game->getNumPlayers());
	joinGame();
}

JoinCreateMenu::OpenGamesMenu::OpenGamesMenu(sf::RenderWindow* window, Game* game, Theme* theme, int id)
{
	//Set the renderer
	renderer = window;
	this->theme = theme;
	this->game = game;

	//Initialize a new theme if necessary
	if (theme == NULL)  theme = Theme::universal_theme;

	// Create main menu
	title = new sf::Text();
	title->setCharacterSize(window->getSize().y / 6);
	title->setFont(theme->font_standard);
	title->setFillColor(theme->color_selected);
	title->setString("Join " + game->getName());
	title->setPosition((window->getSize().x - title->getGlobalBounds().width) / 2, 5);

	menu = new MenuPane(5, window);
	menu->setPosition(10, window->getSize().y / 3.f);
	menu->setSize(window->getSize().x - 20, window->getSize().y / 4.f);

	MenuItem item(theme, "Pick a game", NULL);
	menu->addItem(item);
}

void JoinCreateMenu::OpenGamesMenu::render()
{
	counter++;
	if (counter == 50)
	{
		//Reset the counter
		counter = 0;

		//Update the menu
		//Clear the menu
		menu->clearItems();
		open_games.clear();
		//Populate the menu with the list of games that are open
		for (int i = 0; i < Session::games.size(); i++) {
			Session::OnlineGame og = Session::games[i];
			if (og.status == Session::OnlineGame::Status::AVAILABLE) {
				open_games.push_back(i);
				MenuItem item(theme, og.getInfo(), NULL);
				item.setPressedFunction(std::bind(&JoinCreateMenu::OpenGamesMenu::acceptButton, this));
				menu->addItem(item);
			}
		}
		menu->setSize(menu->getSize().x, renderer->getSize().y / 12.f * open_games.size());

		//Request the updated list of games from the server again
		Session::updateAvailableGames();
	}

	if (renderer != NULL)
	{
		renderer->draw(*title);
		menu->update();
		menu->render();
	}
}

void JoinCreateMenu::OpenGamesMenu::acceptButton()
{
	selectedID = open_games[menu->selected];
	unlockRender();
}
