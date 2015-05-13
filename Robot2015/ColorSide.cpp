#include "ColorSide.h"

ColorSide::ColorSide() :
	buttonOut(PIN_COULEUR_OUT),
	buttonIn(PIN_COULEUR_IN)
{
	// On envoie pour savoir dans quelle couleur on est
	buttonOut = 1;
}

bool ColorSide::isGreen() {
	return getSide() == Type::GREEN;
}

bool ColorSide::isYellow() {
	return getSide() == Type::YELLOW;
}

ColorSide::Type ColorSide::getSide() {
	return buttonIn ? Type::GREEN : Type::YELLOW;
}


ColorSide::~ColorSide() {
	// :)
}