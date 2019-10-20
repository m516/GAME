#pragma once

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include "../GUI/GUIElement.h"

class Game : public GUIElement {
public:

	sf::Vector2f camera_scale;
	sf::Vector2f camera_location;

	virtual void initiaize() = 0;
	virtual void update() = 0;
	virtual void denitialize() = 0;

};