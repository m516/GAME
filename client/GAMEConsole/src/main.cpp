//Source: https://www.sfml-dev.org/tutorials/2.5/start-linux.php
#include "application.h"
#include <X11/Xlib.h>

int main()
{
	XInitThreads();
	Application app;
	app.run();
}
