#include "textField.h"

TextField::TextField(Theme* theme, const std::string& text, std::function<void()> pressed)
{
	// Set theme
	this->theme = theme;

	//Set description text
	label.setString(text);
	label.setCharacterSize(25);
	label = theme->sharpenText(label);
	label.setFont(theme->font_standard);

	pressed_function = pressed;
	//Configure border
	border.setPosition(position);
	border.setSize(size);
	border.setOutlineThickness(1.f);

	//Reset all statuses
	for (int i = 0; i < sf::Keyboard::KeyCount; i++) {
		control_status[i] = Status::UP;
	}
}

TextField::~TextField()
{
}


//renders the item as a box with text in it
void TextField::render()
{
	//Update the keys
	updateKeys();

	//Set colors based on whether or not this item is selected
	if (selected)
	{
		label.setFillColor(theme->color_selected);
		border.setOutlineColor(theme->color_selected);
	}
	else
	{
		label.setFillColor(theme->color_deselected);
		border.setOutlineColor(theme->color_deselected);
	}


	border.setFillColor(theme->color_background);
	renderer->draw(border);
	renderer->draw(label); //TODO doesn't check if the text is longer than the border!
}

void TextField::updateKeys() {
	for (int i = sf::Keyboard::Key::A; i != sf::Keyboard::KeyCount; i++) {
		sf::Keyboard::Key curr_key = (sf::Keyboard::Key)i;
		if (sf::Keyboard::isKeyPressed(curr_key)) {
			if (control_status[i] == Status::UP) control_status[i] = Status::PRESSED;
			else if (control_status[i] == Status::RELEASED) control_status[i] = Status::PRESSED;
			else if (control_status[i] == Status::PRESSED) control_status[i] = Status::DOWN;
		}
		else {
			if (control_status[i] == Status::DOWN) control_status[i] = Status::RELEASED;
			else if (control_status[i] == Status::PRESSED) control_status[i] = Status::RELEASED;
			else if (control_status[i] == Status::RELEASED) control_status[i] = Status::UP;
		}

		bool shift = control_status[sf::Keyboard::LShift] == Status::DOWN ||
			control_status[sf::Keyboard::RShift] == Status::DOWN;

		char c = characters[i][shift ? 1 : 0];
		if (control_status[i] == Status::PRESSED && c) {
			text += c;
			label.setString(text);
		}
	}

	if (control_status[sf::Keyboard::Key::Backspace] == Status::PRESSED) {
		if(text.size()>0) text.pop_back();
		label.setString(text);
	}

	if (control_status[sf::Keyboard::Key::Enter] == Status::PRESSED) {
		callPressedFunction();
	}
}



void TextField::setText(const std::string& text)
{
	this->text = text;
	label.setString(text);
}

std::string TextField::getText()
{
	return text;
}

/**
Set the size of the menuItem rendered on the screen
*/
void TextField::setSize(float x, float y)
{
	GUIElement::setSize(x, y);
	border.setSize(size);
	label.setCharacterSize(y - 4.f);
	label.setCharacterSize((int)(y - 4.0f));
}

void TextField::setSize(sf::Vector2f& new_size)
{
	GUIElement::setSize(new_size);
	border.setSize(size);
	label.setCharacterSize(new_size.y - 4.f);
	label.setCharacterSize((int)(new_size.y - 4.0f));
}

/**
Set the size of the menuItem rendered on the screen
*/
void TextField::setPosition(float x, float y)
{
	GUIElement::setPosition(x, y);
	border.setPosition(position);
	label.setPosition(position);
}

void TextField::setPosition(sf::Vector2f& new_position)
{
	GUIElement::setPosition(new_position);
	border.setPosition(position);
	label.setPosition(position);
}

void TextField::setPressedFunction(std::function<void()> pressed) {
	pressed_function = pressed;
}

void TextField::callPressedFunction() {
	if (pressed_function != NULL)
		pressed_function();
}
