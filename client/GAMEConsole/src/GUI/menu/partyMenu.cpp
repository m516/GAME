#include "partyMenu.h"

PartyMenu::PartyMenu(sf::RenderWindow* window, Theme* theme)
{
    renderer = window;
    this->theme = theme == NULL ? new Theme() : theme;

    title.setCharacterSize(window->getSize().y / 8);
	title.setFont(theme->font_standard);
	title.setColor(theme->color_selected);
	title.setString("Your Party");
	title.setPosition(5, 5);
    title = theme->sharpenText(title);

    partyMembers.setCharacterSize(18);
    partyMembers.setFont(theme->font_standard);
    partyMembers.setColor(theme->color_selected);
    partyMembers.setString("ASTRELION\nYodaSpock");
    partyMembers.setPosition(5, 100);
    partyMembers = theme->sharpenText(partyMembers);

    partySize.setCharacterSize(18);
    partySize.setFont(theme->font_standard);
    partySize.setColor(theme->color_selected);
    partySize.setString("2");
    partySize.setPosition(window->getSize().x / 2 - 18, window->getSize().y * (3.f / 5.f));
    partySize = theme->sharpenText(partySize);

    partySizeLabel.setCharacterSize(24);
    partySizeLabel.setFont(theme->font_standard);
    partySizeLabel.setColor(theme->color_selected);
    partySizeLabel.setString("Party Size");
    partySizeLabel.setPosition(partySize.getPosition().x - 50, partySize.getPosition().y - 30);
    partySizeLabel = theme->sharpenText(partySizeLabel);
}

PartyMenu::~PartyMenu()
{

}

void PartyMenu::render()
{
    if (renderer != NULL)
    {
        renderer->draw(title);
        renderer->draw(partyMembers);
        renderer->draw(partySize);
        renderer->draw(partySizeLabel);
    }
}