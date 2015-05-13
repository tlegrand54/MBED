#pragma once

#include "configuration.h"

class ColorSide {
public:
	enum Type {
		NONE,
		GREEN,
		YELLOW
	};

	ColorSide();
	~ColorSide();

	bool isGreen();
	bool isYellow();
	ColorSide::Type getSide();

private:
	DigitalOut buttonOut;
	// Permet de connaître sa couleur si on a 0 on est jaune sinon on est vert
	DigitalIn buttonIn;
};