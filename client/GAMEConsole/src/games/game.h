#pragma once

#include <SFML/System/Vector2.hpp>
#include "../GUI/lockingElement.h"


class Game : public LockingElement {
public:
	sf::Vector2f camera_location;
	float camera_scale;

	virtual void beginNetworkGame() = 0;
	virtual void beginOfflineGame() = 0;
	virtual void beginSpectateGame() = 0;

	virtual std::string getName();
};