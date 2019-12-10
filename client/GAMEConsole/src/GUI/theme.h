#pragma once
#include <SFML/Graphics.hpp>

class Theme 
{
    public:
        sf::Color color_selected = sf::Color(255, 255, 255);
        sf::Color color_deselected = sf::Color(64, 64, 64);
        sf::Color color_background = sf::Color::Black;
        sf::Color color_border = color_selected;
        float border_size = 1.0;
        int sharpenFactor = 2;

        /** Default font */
        sf::Font font_standard;
        /** Array of all available fonts */
        std::vector<sf::Font> fonts;
        /** Index of the user-set font */
        int userFont;

        static Theme* universal_theme;

        std::string fontDirectory = "assets/fonts/";

        std::vector<std::string> fontFiles = {
            "bitwise.ttf",
            "ka1.ttf",
            "DS-DIGI.ttf",
			"comicbd.ttf",
            "IHATCS.ttf",
            "Halo.ttf",
            "minecraft.ttf"
        };

        Theme();
        bool loadGenericFont();
        void setUserFont(int f);
        sf::Font getUserFont();
        sf::Text sharpenText(sf::Text text);
        Theme clone();
};