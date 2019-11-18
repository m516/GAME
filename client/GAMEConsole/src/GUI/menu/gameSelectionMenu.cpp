#include "gameSelectionMenu.h"


GameSelectionMenu::GameSelectionMenu(sf::RenderWindow* window, Theme* theme = 0)
{
	//Set the renderer
	renderer = window;
	this->theme = theme;

	//Initialize a new theme if necessary
	if (theme == NULL)  theme = Theme::universal_theme;


	// Create main menu
	title = new sf::Text();
	title->setCharacterSize(window->getSize().y / 4);
	title->setFont(theme->font_standard);
	title->setColor(theme->color_selected);
	title->setString("Play a game");
	title->setPosition((window->getSize().x - title->getGlobalBounds().width) / 2, 5);

	menu = new MenuPane(5, window);
	menu->setPosition(10, window->getSize().y / 3.f);
	menu->setSize(window->getSize().x - 20, window->getSize().y / 3.f);

	MenuItem item(theme, "Pong", NULL);
	item.setPressedFunction(std::bind(&GameSelectionMenu::runPong, this));
	menu->addItem(item);

	item = MenuItem(theme, "Back...", NULL);
	item.setPressedFunction(std::bind(&GameSelectionMenu::goBack, this));
	menu->addItem(item);
}

GameSelectionMenu::~GameSelectionMenu()
{
	delete menu;
	delete title;
}

void GameSelectionMenu::render()
{
	if (renderer != NULL) {
		renderer->draw(*title);
		menu->update();
		menu->render();
	}
}

void GameSelectionMenu::runPong() {
	//Create Pong instance
	Pong* pong_game = new Pong();
	GameMenu g(renderer, pong_game, theme);
	g.lockRender();
	delete pong_game;
}
void GameSelectionMenu::goBack() {
	unlockRender();
}