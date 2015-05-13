#include "Match.h"

Match::Match(int duration) :
	duration(duration)
{
}

Match::~Match() {
	// Stop stopwatch
	stopwatch.stop();
}

void Match::waitStart() {
	while(pullStart.isWaiting()){
		; // On attend que la tirette soit enlevée
	}
	// Start Timer
	stopwatch.start();
}

ColorSide::Type Match::getRobotColor() {
	return colorSide.getSide();
}

int Match::getCurrentTime() {
	return stopwatch.read();
}
int Match::getTotalTime() {
	return duration;
}
bool Match::isEnd() {
	return getCurrentTime() >= getTotalTime();
}