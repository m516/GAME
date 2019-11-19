#pragma once

#include <string>
#include <vector>
#include "network.h"

namespace Session {

	class OnlineGame {
	public:

		typedef enum class Status {
			DISCONNECTED = 0,
			AVAILABLE,
			JOINING,
			WAITING_FOR_START,
			IN_PROGRESS,
			CLOSING,
			FAILED,
			NUM_STATES
		}Status;

		typedef enum class Interaction {
			CREATOR = 0,
			PLAYER,
			SPECTATOR,
			NUM_STATES
		}Interaction;


		OnlineGame(int id, int max_players = 2, Status inital_status = Status::DISCONNECTED);


		int num_players = -1;
		Status status;

		std::string getInfo();

	private:
		int id = -1;
		int max_players = -1;
	};

	typedef struct User {
		std::string username;
		int level = -1;
		int wins = -1;
		int losses = -1;
	} User;

	extern OnlineGame* current_game;
	extern OnlineGame::Interaction current_role;
	extern User current_user;

	extern std::vector<OnlineGame> games;
	extern std::vector<User> friends;

	void initialize();
	void updateAvailableGames();
	void createGame(int game_type, int num_players);
	void connectToGame(OnlineGame* game); 
	void networkMessageListener();
}