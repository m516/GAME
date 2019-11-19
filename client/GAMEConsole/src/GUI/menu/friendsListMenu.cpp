#include "friendsListMenu.h"

#include "iostream"

FriendsListMenu::FriendsListMenu(sf::RenderWindow* window, Theme* theme)
{
    renderer = window;
    this->theme = theme == NULL ? new Theme() : theme;

    titleString = "Friends";
    removingFriend = false;
    title.setCharacterSize(window->getSize().y / 8);
    title.setFont(theme->font_standard);
    title.setColor(theme->color_selected);
    title.setString(titleString);
    title.setPosition(5, 5);
    title = theme->sharpenText(title);

    friendsMenu = new MenuPane(5, window);
    friendsMenu->setPosition(5, title.getGlobalBounds().height + 30);
    friendsMenu->setSize(window->getSize().x - 10, 200);

    // TODO: loop through user's friends instead
    char* friends[] = {
        "ASTRELION", 
        "YodaSpock", 
        "mmundy", 
        "Parker"
    };

    for (int i = 0; i < sizeof(friends) / sizeof(friends[0]); i++)
    {
        MenuItem friendItem(theme, friends[i], NULL);
        friendItem.setPressedFunction(std::bind(&FriendsListMenu::viewProfile, this, i));
        friendsMenu->addItem(friendItem);
    }

    MenuItem removeItem(theme, "Remove Friend", NULL);
    removeItem.setPressedFunction(std::bind(&FriendsListMenu::toggleFriendRemove, this));
    friendsMenu->addItem(removeItem);
}

FriendsListMenu::~FriendsListMenu()
{

}

void FriendsListMenu::render()
{
    if (renderer != NULL)
    {
        if (removingFriend)
        {
            title.setString("REMOVING " + titleString);
            title.setColor(sf::Color::Red);
        }
        else
        {
            title.setString(titleString);
            title.setColor(theme->color_selected);
        }
        
        renderer->draw(title);
        friendsMenu->update();
        friendsMenu->render();
    }
}

/**
 * View selected user's profile
 */
void FriendsListMenu::viewProfile(int userID)
{
    std::cout << "Viewing user with ID " << userID << std::endl;

    // TODO get associated user and display profile
}

/**
 * Remove selected friend and switch to normal mode
 */
void FriendsListMenu::removeFriend(int userID)
{
    std::cout << "Removing user with ID " << userID << std::endl;

    // TODO remove associated user

    toggleFriendRemove();
}

/** 
 * Toggles friend deletion mode
 * When TRUE, selecting a friend will rmeove them as a friend
 */
void FriendsListMenu::toggleFriendRemove()
{
    removingFriend = !removingFriend;
}