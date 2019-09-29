#pragma once

class MenuItem {
public:
	/**
	Initializes the MenuItem with the things it needs to have.
	@param text the text to display on the menu
	@param function the function to call when the menu item is activated
	*/
	MenuItem(char* text, int (*function) ());
	~MenuItem();
	//true if selected, false if not selected
	int selected = 0;
	//true if pressed, false if otherwise
	int pressed = 0;
	//string of text to display
	char *text;
	//function to call when this menu item is pressed
	int (*pressedFunction) ();
	//renders the item as a box with text in it
	void render(int x, int y, int width, int height);
private:
};
