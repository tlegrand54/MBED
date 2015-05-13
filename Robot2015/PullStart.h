#pragma once

#include "configuration.h"

class PullStart {
public:
	PullStart();
	~PullStart();
	
	bool isWaiting();

private:
	DigitalOut pullOut;
	// Permet de connaître si le match est lancé si on a 0 le match n'est pas lancé sinon il l'est
	DigitalIn pullIn;
};