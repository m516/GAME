#include "settingsMenu.h"
#include "fontSelectMenu.h"

SettingsMenu::SettingsMenu(sf::RenderWindow* window, Theme* theme)
{
    renderer = window;
    this->theme = theme == NULL ? new Theme() : theme;

    title.setCharacterSize(window->getSize().y / 8);
    title.setFont(theme->font_standard);
    title.setFillColor(theme->color_selected);
    title.setString("Settings");
    title.setPosition(5, 5);
    title = theme->sharpenText(title);

    settingsItems = new MenuPane(5, window);
    settingsItems->setPosition(5, title.getGlobalBounds().height + 30);
    settingsItems->setSize(0, 50 * 2);

    MenuItem settingsItem(theme, "Menu Font");
    settingsItem.setPressedFunction(std::bind(&SettingsMenu::showFontSelect, this));
    settingsItems->addItem(settingsItem);

    settingsItem = MenuItem(theme, "Credits");
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

void SettingsMenu::showFontSelect()
{
    FontSelectMenu f(renderer, theme);
    f.lockRender();
}