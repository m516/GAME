#include "session.h"

namespace Session {

	OnlineGame* current_game;
	OnlineGame::Interaction current_role;
	User current_user;

	std::vector<OnlineGame> games;
	std::vector<User> friends;

	OnlineGame::OnlineGame(int id, int inital_max_players, Status inital_status)
	{
		this->id = id;
		this->max_players = inital_max_players;
		this->status = inital_status;
	}
	std::string OnlineGame::getInfo()
	{
		//TODO stub
		return std::string();
	}


	void initialize()
	{
	}
	void updateAvailableGames()
	{
		NetworkConnection::send("GS");
	}
	void createGame(int game_type, int num_players)
	{
		NetworkConnection::send("C" + std::to_string(game_type) + std::to_string(num_players));
	}
	void connectToGame(OnlineGame* game)
	{
		NetworkConnection::addListener(NetworkConnection::LISTENER::MESSAGE, &networkMessageListener);
	}

	void networkMessageListener() {

	}
}
