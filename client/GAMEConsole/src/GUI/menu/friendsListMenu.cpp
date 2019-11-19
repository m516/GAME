#include "friendsListMenu.h"

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
    MenuItem friendItem(theme, "ASTRELION", NULL);
    // friendItem.setPressedFunction(std::bind(NULL, this)); // TODO replace NULL with calling function that displays user profile
    friendsMenu->addItem(friendItem);

    friendItem = MenuItem(theme, "YodaSpock", NULL);
    friendsMenu->addItem(friendItem);

    friendItem = MenuItem(theme, "mmundy", NULL);
    friendsMenu->addItem(friendItem);

    friendItem = MenuItem(theme, "Parker", NULL);
    friendsMenu->addItem(friendItem);

    friendItem = MenuItem(theme, "Remove Friend", NULL);
    friendItem.setPressedFunction(std::bind(&FriendsListMenu::toggleFriendRemove, this));
    friendsMenu->addItem(friendItem);
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
 * Toggles friend deletion mode
 * When TRUE, selecting a friend will rmeove them as a friend
 */
void FriendsListMenu::toggleFriendRemove()
{
    removingFriend = !removingFriend;
}