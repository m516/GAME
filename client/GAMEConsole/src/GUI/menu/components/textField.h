#pragma once

#include "../../guiElement.h"
#include <functional>
#include <SFML/Window/Keyboard.hpp>

class TextField : public GUIElement
{
    public:
        /**
        Initializes the TextField with the things it needs to have.
        @param text the text to display on the menu
        @param function the function to call when the menu item is activated
        */
        TextField(Theme* theme, const std::string& text = "", std::function<void()> pressed = 0);
        /**
        Deconstructor for MenuItem
        */
        ~TextField();
        /**
        true if pressed, false if otherwise
        */
        bool pressed = false;
        /**
        Sets the text to display
        */
        void setText(const std::string& text);
        std::string getText();

        //Overridden from GUIElement
        /**
        Set the size of the menuItem rendered on the screen
        */
        void setSize(float x, float y);
        void setSize(sf::Vector2f& new_size);

        /**
        Set the size of the menuItem rendered on the screen
        */
        void setPosition(float x, float y);
        void setPosition(sf::Vector2f& new_position);

        /**
        Set the Pressed Function after selecting a button
        */
        void setPressedFunction(std::function<void()> pressed);

        void callPressedFunction();

        /**
        renders the item as a box with text in it
        @param target the window onto which this MenuItem renders
        */
        void render();
    private:
        //string of text to display
        sf::Text label;
        //Instance of rectangle border
        sf::RectangleShape border;
        /**
        function to call when this menu item is pressed
        */
        std::function<void()> pressed_function;

        /*The string containing the text that the user typed*/
        std::string text;

        typedef enum class STATUS 
        {
            UP = 0,
            PRESSED = 1,
            DOWN = 2,
            RELEASED = 3,
            DISABLED = 4
        } Status;

        Status control_status[sf::Keyboard::Key::KeyCount];
        const char characters[sf::Keyboard::Key::KeyCount][2] = {
            {'a','A'},   // A = 0,        ///< The A key
            {'b','B'},   // B,            ///< The B key
            {'c','C'},   // C,            ///< The C key
            {'d','D'},   // D,            ///< The D key
            {'e','E'},   // E,            ///< The E key
            {'f','F'},   // F,            ///< The F key
            {'g','G'},   // G,            ///< The G key
            {'h','H'},   // H,            ///< The H key
            {'i','I'},   // I,            ///< The I key
            {'j','J'},   // J,            ///< The J key
            {'k','K'},   // K,            ///< The K key
            {'l','L'},   // L,            ///< The L key
            {'m','M'},   // M,            ///< The M key
            {'n','N'},   // N,            ///< The N key
            {'o','O'},   // O,            ///< The O key
            {'p','P'},   // P,            ///< The P key
            {'q','Q'},   // Q,            ///< The Q key
            {'r','R'},   // R,            ///< The R key
            {'s','S'},   // S,            ///< The S key
            {'t','T'},   // T,            ///< The T key
            {'u','U'},   // U,            ///< The U key
            {'v','V'},   // V,            ///< The V key
            {'w','W'},   // W,            ///< The W key
            {'x','X'},   // X,            ///< The X key
            {'y','Y'},   // Y,            ///< The Y key
            {'z','Z'},   // Z,            ///< The Z key
            {'0',')'},   // Num0,         ///< The 0 key
            {'1','!'},   // Num1,         ///< The 1 key
            {'2','@'},   // Num2,         ///< The 2 key
            {'3','#'},   // Num3,         ///< The 3 key
            {'4','$'},   // Num4,         ///< The 4 key
            {'5','%'},   // Num5,         ///< The 5 key
            {'6','^'},   // Num6,         ///< The 6 key
            {'7','&'},   // Num7,         ///< The 7 key
            {'8','*'},   // Num8,         ///< The 8 key
            {'9','('},   // Num9,         ///< The 9 key
            { 0 , 0 },   // Escape,       ///< The Escape key
            { 0 , 0 },   // LControl,     ///< The left Control key
            { 0 , 0 },   // LShift,       ///< The left Shift key
            { 0 , 0 },   // LAlt,         ///< The left Alt key
            { 0 , 0 },   // LSystem,      ///< The left OS specific key: window (Windows and Linux), apple (MacOS X), ...
            { 0 , 0 },   // RControl,     ///< The right Control key
            { 0 , 0 },   // RShift,       ///< The right Shift key
            { 0 , 0 },   // RAlt,         ///< The right Alt key
            { 0 , 0 },   // RSystem,      ///< The right OS specific key: window (Windows and Linux), apple (MacOS X), ...
            { 0 , 0 },   // Menu,         ///< The Menu key
            {'[','{'},   // LBracket,     ///< The [ key
            {']','}'},   // RBracket,     ///< The ] key
            {';',':'},   // Semicolon,    ///< The ; key
            {',','<'},   // Comma,        ///< The , key
            {'.','>'},   // Period,       ///< The . key
            {'\'','\"'}, // Quote,        ///< The ' key
            {'/','?'},   // Slash,        ///< The / key
            {'\\','\\'}, // Backslash,    ///< The \ key
            {'`','~'},   // Tilde,        ///< The ~ key
            {'=','+'},   // Equal,        ///< The = key
            {'-','_'},   // Hyphen,       ///< The - key (hyphen)
            {' ',' '},   // Space,        ///< The Space key
            { 0 , 0 },   // Enter,        ///< The Enter/Return keys
            { 0 , 0 },   // Backspace,    ///< The Backspace key
            {'\t', 0},// Tab,          ///< The Tabulation key
            { 0 , 0 }, // PageUp,       ///< The Page up key
            { 0 , 0 }, // PageDown,     ///< The Page down key
            { 0 , 0 }, // End,          ///< The End key
            { 0 , 0 }, // Home,         ///< The Home key
            { 0 , 0 }, // Insert,       ///< The Insert key
            { 0 , 0 }, // Delete,       ///< The Delete key
            {'+','+'}, // Add,          ///< The + key
            {'-','-'}, // Subtract,     ///< The - key (minus, usually from numpad)
            {'*','*'}, // Multiply,     ///< The * key
            {'/','/'}, // Divide,       ///< The / key
            { 0 , 0 }, // Left,         ///< Left arrow
            { 0 , 0 }, // Right,        ///< Right arrow
            { 0 , 0 }, // Up,           ///< Up arrow
            { 0 , 0 }, // Down,         ///< Down arrow
            {'0','0'}, // Numpad0,      ///< The numpad 0 key
            {'1','1'}, // Numpad1,      ///< The numpad 1 key
            {'2','2'}, // Numpad2,      ///< The numpad 2 key
            {'3','3'}, // Numpad3,      ///< The numpad 3 key
            {'4','4'}, // Numpad4,      ///< The numpad 4 key
            {'5','5'}, // Numpad5,      ///< The numpad 5 key
            {'6','6'}, // Numpad6,      ///< The numpad 6 key
            {'7','7'}, // Numpad7,      ///< The numpad 7 key
            {'8','8'}, // Numpad8,      ///< The numpad 8 key
            {'9','9'}, // Numpad9,      ///< The numpad 9 key
            { 0 , 0 }, // F1,           ///< The F1 key
            { 0 , 0 }, // F2,           ///< The F2 key
            { 0 , 0 }, // F3,           ///< The F3 key
            { 0 , 0 }, // F4,           ///< The F4 key
            { 0 , 0 }, // F5,           ///< The F5 key
            { 0 , 0 }, // F6,           ///< The F6 key
            { 0 , 0 }, // F7,           ///< The F7 key
            { 0 , 0 }, // F8,           ///< The F8 key
            { 0 , 0 }, // F9,           ///< The F9 key
            { 0 , 0 }, // F10,          ///< The F10 key
            { 0 , 0 }, // F11,          ///< The F11 key
            { 0 , 0 }, // F12,          ///< The F12 key
            { 0 , 0 }, // F13,          ///< The F13 key
            { 0 , 0 }, // F14,          ///< The F14 key
            { 0 , 0 }, // F15,          ///< The F15 key
            { 0 , 0 }  // Pause,        ///< The Pause key
        };

        void updateKeys();
};

