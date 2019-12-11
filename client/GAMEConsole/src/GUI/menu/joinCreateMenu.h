#pragma once

#include <vector>

#include "../lockingElement.h"
#include "../../games/game.h"
#include "../../application.h"
#include "components/menuPane.h"
#include "../../modules/network.h"
#include "../../modules/session.h"
#include "components/dialog.h"

/**
 * This menu is made to call websocket op-codes that tell the server to create a new online game
 * or to join an existing one. Note that will only run preexisting games and WILL NOT create 
 * and configure new ones
 */
class JoinCreateMenu : public LockingElement
{
    public:
        JoinCreateMenu(sf::RenderWindow* window, Game* game, Theme* theme);
        ~JoinCreateMenu();

        //Inherited from GUIElement
        void render();

    private:
        MenuPane* menu = 0;
        sf::Text* title = 0;
        Game* game;

        /** Minimum frame time (essentially highest fps possible)*/
        const sf::Time frame_period = sf::milliseconds(10.f);

        //private menu-specific functions
        void joinGame();
        void createGame();

		class OpenGamesMenu : public LockingElement {
		public:
			OpenGamesMenu(sf::RenderWindow* window, Game* game, Theme* theme, int id = 0);
			int selectedID = -1;
			void render();
		private:
			std::vector<int> open_games;
			int counter = 0;
			MenuPane* menu = 0;
			Game* game = 0;
			sf::Text* title = 0;
			void acceptButton();
		};
};

