#include "lockingElement.h"
#include "../modules/network.h"

#include <thread>

void LockingElement::lockRender()
{
	locked = true;
	escape_pressed = false;

	//Reconnect if necessary
	if (!NetworkConnection::isConnected()) NetworkConnection::connect();

	while (locked)
	{
		//Sleep to not hog the CPU and to maintain a marginally steady frame rate
		std::this_thread::sleep_for(std::chrono::milliseconds(frame_time.asMilliseconds()));

		//Unlock manually if the escape key is pressed
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			escape_pressed = true;
		}
		else if (escape_pressed) {
			unlockRender();
		}
		else {
			//Render
			renderer->clear();
			render();
			renderer->display();
		}
	}
}

void LockingElement::unlockRender()
{
	locked = false;

	//Call the unlock function
	if (unlock_function != NULL) {
		unlock_function();
	}
}
