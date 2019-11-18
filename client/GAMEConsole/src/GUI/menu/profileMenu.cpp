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


ProfileMenu::ProfileMenu(sf::RenderWindow* window, Theme* theme)
{
    renderer = window;
    this->theme = theme == NULL ? new Theme() : theme;

    levelSquare.setSize(sf::Vector2f(.25 * 256, .25 * 256));
    levelSquare.setPosition(5, 5);
    levelSquare.setFillColor(sf::Color::Blue);

    level.setCharacterSize(24);
    level.setFont(theme->font_standard);
    level.setColor(theme->color_selected);
    level.setString("1");
    level.setPosition(32, 24);
    level = theme->sharpenText(level);

	username.setCharacterSize(18);
	username.setFont(theme->font_standard);
	username.setColor(theme->color_selected);
	username.setString("ASTRELION");
	username.setPosition(78, 5);
    username = theme->sharpenText(username);

    usernameLabel.setCharacterSize(8);
    usernameLabel.setFont(theme->font_standard);
    usernameLabel.setColor(theme->color_selected);
    usernameLabel.setString("Username");
    usernameLabel.setPosition(78, 25);
    usernameLabel = theme->sharpenText(usernameLabel);

    userID.setCharacterSize(8);
    userID.setFont(theme->font_standard);
    userID.setColor(theme->color_selected);
    userID.setString("ABCD EFGH");
    userID.setPosition(78, 46);
    userID = theme->sharpenText(userID);
    
    userIDLabel.setCharacterSize(8);
    userIDLabel.setFont(theme->font_standard);
    userIDLabel.setColor(theme->color_selected);
    userIDLabel.setString("User ID");
    userIDLabel.setPosition(78, 60);
    userIDLabel = theme->sharpenText(userIDLabel);

    friends.setCharacterSize(8);
    friends.setFont(theme->font_standard);
    friends.setColor(theme->color_selected);
    friends.setString("ASTRELION\nYodaSpock\nmmundy\nParker");
    friends.setPosition(5, 114);
    friends = theme->sharpenText(friends);

    friendsLabel.setCharacterSize(14);
    friendsLabel.setFont(theme->font_standard);
    friendsLabel.setColor(theme->color_selected);
    friendsLabel.setString("Friends");
    friendsLabel.setPosition(5, 90);
    friendsLabel = theme->sharpenText(friendsLabel);

    games.setCharacterSize(8);
    games.setFont(theme->font_standard);
    games.setColor(theme->color_selected);
    games.setString("Pong\nGalaga\nSnake");
    games.setPosition(164, 114);
    games = theme->sharpenText(games);

    gamesLabel.setCharacterSize(14);
    gamesLabel.setFont(theme->font_standard);
    gamesLabel.setColor(theme->color_selected);
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