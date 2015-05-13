#include "PullStart.h"

PullStart::PullStart() :
	pullOut(PIN_TIRETTE_OUT),
	pullIn(PIN_TIRETTE_IN)
{
	// On envoie 1 pour savoir si on a la tirette ou non
	pullOut = 1;
}

bool PullStart::isWaiting() {
	return pullIn;
}

PullStart::~PullStart() {

}