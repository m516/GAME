#pragma once

#include <SFML/System/Vector2.hpp>
#include "../GUI/guiElement.h"


class Game : public GUIElement {
public:
	sf::Vector2f camera_location;
	float camera_scale;

	virtual void initialize() = 0;
	virtual void update() = 0;
	virtual void deinitialize() = 0;
};