#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "guiElement.h"

class Panel : public GUIElement
{
    public:
        /** Render panel onto parent render target */
        void render();
        /** Add a GUI element to the panel */
        void addElement(sf::RenderTarget* element);
        /** Remove GUI element from the panel */
        void removeElement(sf::RenderTarget* element);
        /** Return an array of elements associated with this panel */
        std::vector<sf::RenderTarget> getElements();

        /** Set this panel's parent element to given render target */
        void setParent(sf::RenderTarget* parent);
        /** Get this panel's parent render target */
        sf::RenderTarget* getParent();
    private:
    protected:
};