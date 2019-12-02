#include "session.h"

#ifdef TEST_SYSTEM
#define SESSION_DEBUG 1
#endif

namespace Session 
{
	OnlineGame::Interaction current_role;
	User current_user;

	OnlineGame current_game;

	std::vector<OnlineGame> games;
	std::vector<User> friends;

	OnlineGame::OnlineGame() 
    {
        // Empty constructor
	}

	OnlineGame::OnlineGame(int id, Status inital_status)
	{
		this->id = id;
		this->status = inital_status;
	}

	std::string OnlineGame::getInfo()
	{
		return "Game "+std::to_string(id)+
			" with "+ 
			std::to_string(num_players)+
			" of "+
			std::to_string(max_players)+
			" players";
	}

	int OnlineGame::getID()
	{
		return id;
	}

	int OnlineGame::getType()
	{
		return type;
	}

	OnlineGame* currentGame()
	{
		if (current_game.getID() < 0) return nullptr;
		return &current_game;
	}

	void initialize()
	{
		NetworkConnection::addListener(NetworkConnection::LISTENER::MESSAGE, &networkMessageListener);
	}

	void updateAvailableGames()
	{
		games.clear();
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

	void startGame()
	{
		NetworkConnection::send("G");
	}

	void joinGame(int id) {
		OnlineGame* og = getGame(id);
		if (og == nullptr) {
			current_game = OnlineGame(id);
			updateAvailableGames();
		}
		else {
			joinGame(og);
		}
	}

	void joinGame(OnlineGame* game)
	{
		if (game == nullptr) {
			std::cerr << "Cannot join a null game!" << std::endl;
			return;
		}

		current_game = OnlineGame(*game);
		current_game.status = OnlineGame::Status::JOINING;
		//Create join command
		std::string join_command = "J";
		if (game->getID() < 10) join_command += "0";
		join_command += std::to_string(game->getID());
		join_command += std::to_string(game->getType());
		join_command += "00000000";
		NetworkConnection::send(join_command);

		std::cout << "Switched game: " << current_game.getInfo() << std::endl;
	}

	OnlineGame* getGame(int id)
	{
		for (int i = 0; i < games.size(); i ++) 
        {
			OnlineGame* og = &games[i];
			if (og->getID() == id) return og;
		}

		return nullptr;
	}

	OnlineGame::Status getStatus()
	{
		return current_game.status;
	}

	void networkMessageListener() 
    {
		std::string s = NetworkConnection::getString();

		//If returning a Game instance (always 6 characters)
		if (s.size() == 6) 
        {
			int index = std::stoi(s.substr(0, 2));
			bool is_open = s[2] == 'O';
			int num_players = s[3] - '0';
			int max_players = s[5] - '0';

			OnlineGame og(index, is_open ? Session::OnlineGame::Status::AVAILABLE:Session::OnlineGame::Status::IN_PROGRESS);
			og.num_players = num_players;
			og.max_players = max_players;
			std::cout << og.getInfo() << std::endl;

			//Add to the list of games available
			games.push_back(og);

			//Update the current game if necessary
			if (current_game.getID() == index) 
            {
				std::cout << "Found game that matches current one: " + og.getInfo();
				current_game = og;
			}
		}
		//If a Game ID has been received
		else if (s.substr(0,3) == "GID") 
        {
			//Extract the index
			int id = std::stoi(s.substr(3, 2));
			//Set it to the current game
			OnlineGame* og = getGame(id);

			if (og == nullptr) 
            {
				std::cout << "Warning, connecting to Null game!" << std::endl;
				current_game = OnlineGame(id);
			}
			else 
            {
				current_game = OnlineGame(*og);
			}

			updateAvailableGames();
		}
		else if (s == "Successfully Joined") 
        {
			current_game.status = OnlineGame::Status::WAITING_FOR_START;
		}
        #ifdef SESSION_DEBUG
		else {
			std::cout << "unrecognized command " << s << std::endl;
		}
        #endif
	}
    
	void clearGame()
	{
		current_game = OnlineGame();
		current_role = OnlineGame::Interaction::NONE;
	}
}
