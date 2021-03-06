#include "application.h"
#include <iostream>

#ifdef TEST_SYSTEM

#include "GUI/menu/components/menuItem.h"
#include "GUI/menu/components/menuPane.h"
#include "modules/network.h"
#include "modules/session.h"
#include <exception>

MenuPane mp;
volatile bool clicked = false;
void onClicked() 
{
	clicked = true;
}


int testMenuSystem() {
	/*Create menu item*/
	MenuItem i(nullptr, "test", &onClicked);
	mp.addItem(i);

	/*Test click functionality*/
	i.callPressedFunction();
	if(!clicked) 
    {
		std::cout << "Menu system didn't respond to click" << std::endl;
		return 1;
	}

	return 0;
}

int testTheme() 
{
	/*Test theme components that are critical to menus, games*/
	if (Theme::universal_theme == nullptr) 
    {
		std::cout << "Universal theme doesn't exist. This will cause GUI elements without a reference to a theme to break" << std::endl;
		return 1;
	}
	if (!Theme::universal_theme->loadGenericFont()) 
    {
		std::cout << "Universal font doesn't exist. This will cause GUI elements with a reference to the universal theme to break" << std::endl;
		return 2;
	}

	return 0;
}

int testNetwork() 
{
	clicked = false;
	try 
    {
		/*Test the network connection with the listener created above*/
		NetworkConnection::addListener(NetworkConnection::Listener::OPEN, &onClicked);
		/*Attempt to connect to the server*/
		NetworkConnection::connect();
		/*Send something to the server*/
		NetworkConnection::send("blah");
	}
	catch (const std::exception & ex) 
    {
		std::cout << "Exception thrown" << std::endl;
		std::cout << ex.what() << std::endl;
		return 1;
	}
	catch (const std::string & ex) 
    {
		std::cout << "Exception thrown" << std::endl;
		std::cout << ex << std::endl;
		return 2;
	}
	catch(...)
    {
		std::cout << "Failed for some unknown reason" << std::endl;
		return 3;
	}

	/*Check for a response from the server*/
	if (!clicked) 
    {
		std::cout << "Failed to set flag" << std::endl;
		return 4;
	}

	/*Close the connection*/
	NetworkConnection::disconnect();
	return 0;
}

int testSession() {
	try {
		/*Begin by attempting to initialize the session. 
		If we can't, we're in trouble*/
		Session::initialize();
		/*Create a new game, which tests all the features 
		of the connection between the session and the network*/
		Session::startGame();
		return 0;
	}
	catch (...) {
		return 1;
	}
}

int error_code = 0;
int main() 
{
	std::cout << std::endl;
	std::cout << "Hello testing environment!" << std::endl;

	//Menu
	std::cout << "Testing menu system" << std::endl;
	if (testMenuSystem()) 
    {
		std::cout << "Menu system failed" << std::endl;
		error_code = 1;
	}
	else 
    {
		std::cout << "Menu system passed" << std::endl;
	}

	//Theme
	std::cout << std::endl;
	std::cout << "Testing theme" << std::endl;
	if (testTheme()) 
    {
		std::cout << "Theme failed" << std::endl;
		error_code = 2;
	}
	else 
    {
		std::cout << "Theme passed" << std::endl;
	}

	//Network
	std::cout << std::endl;
	std::cout << "Testing Newtork module" << std::endl;
	if (testNetwork()) 
    {
		std::cout << "Network failed (ignoring)" << std::endl;
	}
	else 
    {
		std::cout << "Network passed" << std::endl;
	}
	std::cout << "Testing Newtork module again" << std::endl;
	if (testNetwork())
	{
		std::cout << "Network failed (ignoring)" << std::endl;
	}
	else
	{
		std::cout << "Network passed" << std::endl;
	}

	//Session
	std::cout << std::endl;
	std::cout << "Testing Session module" << std::endl;
	if (testSession())
	{
		std::cout << "Session failed (ignoring)" << std::endl;
	}
	else
	{
		std::cout << "Session passed" << std::endl;
	}

	std::cout << std::endl;
	std::cout << "Done" << std::endl;
	return error_code;
}

#else

//Run the program normally
//Windows
#if defined(_WIN32) || defined(_WIN64) 
int main()
{
	Application app;
	app.run();
}

//Linux
#else
#include <X11/Xlib.h>
int main()
{
	XInitThreads();
	Application app;
	app.run();
}
#endif

#endif // TEST_SYSTEM


