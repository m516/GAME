#include "controller.h"

Controller::~Controller(){

}

void Controller::enable() {
	enabled = true;
}
void Controller::disable() {
	enabled = false;
}

bool Controller::is_enabled() {
	return enabled;
}