//Source: https://www.sfml-dev.org/tutorials/2.5/start-linux.php
#include "application.h"
#include <iostream>

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


