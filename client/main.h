#pragma once

void EventHandler(sf::RenderWindow &);
void Renderer(sf::RenderWindow &);
sf::View getLetterboxView(sf::View view, int windowWidth, int WindowHeight);