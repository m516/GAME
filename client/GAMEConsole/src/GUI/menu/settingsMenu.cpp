#include "settingsMenu.h"

SettingsMenu::SettingsMenu(sf::RenderWindow* window, Theme* theme)
{
    renderer = window;
    this->theme = theme == NULL ? new Theme() : theme;

    title.setCharacterSize(window->getSize().y / 8);
    title.setFont(theme->font_standard);
    title.setColor(theme->color_selected);
    title.setString("Settings");
    title.setPosition(5, 5);
    title = theme->sharpenText(title);

    settingsItems = new MenuPane(5, window);
    settingsItems->setPosition(5, title.getGlobalBounds().height + 30);
    settingsItems->setSize(window->getSize().x - 5, window->getSize().y - title.getGlobalBounds().height - 100);

    MenuItem settingsItem(theme, "Volume");
    settingsItems->addItem(settingsItem);

    settingsItem = MenuItem(theme, "Logout");
    settingsItems->addItem(settingsItem);

    settingsItem = MenuItem(theme, "Credits");
    settingsItems->addItem(settingsItem);

    settingsItem = MenuItem(theme, "Logout");
    settingsItems->addItem(settingsItem);

    settingsItem = MenuItem(theme, "Back");
    settingsItems->addItem(settingsItem);
}

SettingsMenu::~SettingsMenu()
{

}

void SettingsMenu::render()
{
    if (renderer != NULL)
    {
        renderer->draw(title);
        settingsItems->update();
        settingsItems->render();
    }
}