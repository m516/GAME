#pragma once

#include "../lockingElement.h"

class PartyMenu : public LockingElement
{
    public:
        PartyMenu(sf::RenderWindow* window, Theme* theme);
        ~PartyMenu();
        void render();

    private:
        sf::Text title = sf::Text();
        sf::Text partyMembers = sf::Text();
        sf::Text partySize = sf::Text();
        sf::Text partySizeLabel = sf::Text();
};