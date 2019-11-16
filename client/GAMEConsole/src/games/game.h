#pragma once

#include <SFML/System/Vector2.hpp>
#include "../GUI/lockingElement.h"


class Game : public LockingElement {
public:
	sf::Vector2f camera_location;
	float camera_scale;

	virtual void initialize() = 0;
	virtual void update() = 0;
	virtual void deinitialize() = 0;
};