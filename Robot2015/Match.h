#pragma once

#include "ColorSide.h"
#include "PullStart.h"

class Match {
public:
	const static int DEFAULT_DURATION = 90;

	Match(int duration = DEFAULT_DURATION);
	~Match();

	void waitStart();

	ColorSide::Type getRobotColor();

	int getCurrentTime();
	int getTotalTime();
	bool isEnd();

private:
	// Match duration
	int duration;

	// Tirette de démarrage
	PullStart pullStart;
	// Couleur du match (Jaune/Vert)
	ColorSide colorSide;
	// Permet de connaître le temps du match
	Timer stopwatch;
};