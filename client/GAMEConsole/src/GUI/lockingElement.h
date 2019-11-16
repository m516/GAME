#pragma once

#include "guiElement.h"

#include <functional>


class LockingElement : public GUIElement
{
public:

	void lockRender();

	/** Unlocks this RenderLock. Must be called in a 
	subclass's update() function or by another thread */
	void unlockRender();

protected:

	/** Minimum frame time (essentially highest fps possible)*/
	const sf::Time frame_time = sf::milliseconds(10.f);

	/** Function called when this RenderLock is unlocket*/
	std::function<void()> unlock_function = 0;

private:

	/** True when locked */
	volatile bool locked = false;

	/** True when escape key was pressed during the last frame */
	volatile bool escape_pressed = false;
};

