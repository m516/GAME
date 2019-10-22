#include "sprite.h"

Sprite::~Sprite() {

}

void Sprite::updateScreenDimensions() {

	screen_size.x = size.x * game->camera_scale * game->getSize().y; //getSize().y ensures a square image regardless of aspect ratio
	screen_size.y = size.y * game->camera_scale * game->getSize().y;


	screen_position.x = (position.x + game->camera_location.x + game->getPosition().x)*game->getSize().x;
	screen_position.y = (position.y + game->camera_location.y + game->getPosition().y)*game->getSize().y;
}