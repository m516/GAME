#pragma once

#include "components/menuPane.h"
#include "../lockingElement.h"

class FriendsListMenu : public LockingElement
{
    public:
        FriendsListMenu(sf::RenderWindow* window, Theme* theme);
        ~FriendsListMenu();
        void render();

    private:
        bool removingFriend;
        std::string titleString;
        sf::Text title;
        MenuPane* friendsMenu;

        void toggleFriendRemove();
        void viewProfile(int userID);
        void removeFriend(int userID);
};