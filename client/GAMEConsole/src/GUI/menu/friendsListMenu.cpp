#include "friendsListMenu.h"

FriendsListMenu::FriendsListMenu(sf::RenderWindow* window, Theme* theme)
{
    renderer = window;
    this->theme = theme == NULL ? new Theme() : theme;
}

FriendsListMenu::~FriendsListMenu()
{

}

void FriendsListMenu::render()
{
    
}