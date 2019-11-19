#include "settingsMenu.h"

SettingsMenu::SettingsMenu(sf::RenderWindow* window, Theme* theme)
{
    renderer = window;
    this->theme = theme == NULL ? new Theme() : theme;
}

SettingsMenu::~SettingsMenu()
{

}

void SettingsMenu::render()
{
    
}