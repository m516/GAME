#include "application.h"
#include <iostream>

#ifdef TEST_SYSTEM

int main() {
	std::cout << "Hello testing environment!" << std::endl;
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


