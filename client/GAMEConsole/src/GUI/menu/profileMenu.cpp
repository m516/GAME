#include "profileMenu.h"

#include <iostream>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string>

#if !(defined _WIN32 || defined _WIN64)
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <unistd.h>
#endif

ProfileMenu::ProfileMenu(sf::RenderWindow* window, Theme* theme, int user_id)
{
	renderer = window;
	this->theme = theme == NULL ? new Theme() : theme;
	int id = user_id;

	//MAKE THE GET REQUEST TO GET ALL THE DATA FROM THE DATABASE
	sf::Http http;
	http.setHost("coms-309-sr-5.misc.iastate.edu", 8080);

	std::string strId = std::to_string(id);
	std::string path = ("user/" + strId);
	sf::Http::Request request(path, sf::Http::Request::Get);
	sf::Http::Response response = http.sendRequest(request);
	std::string responseString = response.getBody();
	std::string shortenedString = responseString.substr(1, (responseString.length()));
	int size = shortenedString.length();
	std::cout << shortenedString << std::endl;

	std::string delimeter = ",";

	size_t pos = 0;
	std::string token;
	std::string user_name;
	std::string user_level; 
	std::string user_address;
	int count = 0;

	while ((count < 3))
    {
		std::cout << "COUNT IS" << std::endl;
		std::cout << count << std::endl;
        
		if ((pos = shortenedString.find(delimeter)) != std::string::npos)
        {
			switch (count) 
            {
				case 0: 
                {//USER LEVEL - DON'T CHANGE
					token = shortenedString.substr(0, pos);
					user_level = token.substr(12, pos);
					break;
				}
				case 1: 
                {//USER ADDRESS - DON'T CHANGE
					token = shortenedString.substr(0, pos);
					user_address = token.substr(11, pos - 12);
					break;
				}
				case 2:
                {//USER NAME - DON'T CHANGE
					token = shortenedString.substr(0, pos);
					user_name = token.substr(12, pos - 13);
					break;
				}
				default: 
                {//USER ID - DON'T CHANGE
					token = shortenedString.substr(0, pos);
				}
			}
		}

		count++;
		shortenedString.erase(0, pos + delimeter.length());
	}

	levelSquare.setSize(sf::Vector2f(.25 * 256, .25 * 256));
	levelSquare.setPosition(5, 5);
	levelSquare.setFillColor(sf::Color::Blue);

    level.setCharacterSize(24);
    level.setFont(theme->font_standard);
    level.setFillColor(theme->color_selected);
    level.setString(user_level);
    level.setPosition(32, 24);

	level = theme->sharpenText(level);

	username.setCharacterSize(18);
	username.setFont(theme->font_standard);
	username.setFillColor(theme->color_selected);
	username.setString(user_name);
	username.setPosition(78, 5);
    username = theme->sharpenText(username);

    usernameLabel.setCharacterSize(8);
    usernameLabel.setFont(theme->font_standard);
    usernameLabel.setFillColor(theme->color_selected);
    usernameLabel.setString("Username");
    usernameLabel.setPosition(78, 25);
    usernameLabel = theme->sharpenText(usernameLabel);

    userID.setCharacterSize(8);
    userID.setFont(theme->font_standard);
    userID.setFillColor(theme->color_selected);
    userID.setString(strId);
    userID.setPosition(78, 46);
    userID = theme->sharpenText(userID);
    
    userIDLabel.setCharacterSize(8);
    userIDLabel.setFont(theme->font_standard);
    userIDLabel.setFillColor(theme->color_selected);
    userIDLabel.setString("User ID");
    userIDLabel.setPosition(78, 60);
    userIDLabel = theme->sharpenText(userIDLabel);

    friends.setCharacterSize(8);
    friends.setFont(theme->font_standard);
    friends.setFillColor(theme->color_selected);
	//TODO DON'T HARDCODE THIS
    friends.setString("ASTRELION\nYodaSpock\nmmundy\nParker");
    friends.setPosition(5, 114);
    friends = theme->sharpenText(friends);

    friendsLabel.setCharacterSize(14);
    friendsLabel.setFont(theme->font_standard);
    friendsLabel.setFillColor(theme->color_selected);
    friendsLabel.setString("Friends");
    friendsLabel.setPosition(5, 90);
    friendsLabel = theme->sharpenText(friendsLabel);

    games.setCharacterSize(8);
    games.setFont(theme->font_standard);
    games.setFillColor(theme->color_selected);
	//TODO DON'T HARDCODE THIS
    games.setString("Pong");
    games.setPosition(164, 114);
    games = theme->sharpenText(games);

    gamesLabel.setCharacterSize(14);
    gamesLabel.setFont(theme->font_standard);
    gamesLabel.setFillColor(theme->color_selected);
    gamesLabel.setString("Games");
    gamesLabel.setPosition(164, 90);
    gamesLabel = theme->sharpenText(gamesLabel);
}

ProfileMenu::~ProfileMenu()
{

}

void ProfileMenu::render()
{
	if (renderer != NULL)
	{
		renderer->draw(levelSquare);
		renderer->draw(level);
		renderer->draw(usernameLabel);
		renderer->draw(username);
		renderer->draw(userID);
		renderer->draw(userIDLabel);
		renderer->draw(friends);
		renderer->draw(friendsLabel);
		renderer->draw(games);
		renderer->draw(gamesLabel);
	}
}


/*
// https://www.includehelp.com/cpp-programs/get-mac-address-of-linux-based-network-device.aspx
std::string ProfileMenu::getMacAddress()
{
	std::string macAddress;
	int fd;
	struct ifreq ifr;
	char *iface = "wlan0";
	char *mac;

	fd = socket(AF_INET, SOCK_DGRAM, 0);

	ifr.ifr_addr.sa_family = AF_INET;
	strncpy((char *)ifr.ifr_name , (const char *)iface , IFNAMSIZ-1);

	ioctl(fd, SIOCGIFHWADDR, &ifr);

	close(fd);

	mac = (char *)ifr.ifr_hwaddr.sa_data;
	int test1 = mac[0];
	printf("%02X ", test1 & 0xFF);
	printf("%02X ", mac[1]);

	for (int i = 0; i <= 5; i++)
	{
		macAddress += mac[i] & 0xff;
	}

	//display mac address
	//sprintf((char *)uc_Mac,(const char *)"%.2x:%.2x:%.2x:%.2x:%.2x:%.2x\n" , mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
	return macAddress;
}
*/