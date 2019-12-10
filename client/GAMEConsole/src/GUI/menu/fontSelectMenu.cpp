#include "fontSelectMenu.h"

#include <iostream>
#include <string>

FontSelectMenu::FontSelectMenu(sf::RenderWindow* window, Theme* theme)
{
    renderer = window;
    this->theme = theme == NULL ? new Theme() : theme;

    title.setString("Select a Font");
    title.setCharacterSize(window->getSize().y / 8);
    title.setFont(theme->font_standard);
    title.setFillColor(theme->color_selected);
    title.setPosition(5, 5);
    title = theme->sharpenText(title);

    fontPane = new MenuPane(5, window);
	fontPane->setPosition(10, window->getSize().y / 3.f);
	fontPane->setSize(window->getSize().x - 20, window->getSize().y / 3.f);
    
    for (int i = 0; i < theme->fonts.size(); i++)
    {
        MenuItem item(theme, "Font " + std::to_string(i), NULL);
        item.setPressedFunction(std::bind(&FontSelectMenu::setFont, this, i));
        fontPane->addItem(item);
    }
}

FontSelectMenu::~FontSelectMenu()
{

}

void FontSelectMenu::render()
{
    if (renderer != NULL)
    {
        renderer->draw(title);
        fontPane->update();
        fontPane->render();
    }
}

void FontSelectMenu::setFont(int fontIndex)
{
    std::cout << "Font set to " << fontIndex << std::endl;
    theme->setUserFont(fontIndex);
    theme->loadGenericFont();
}