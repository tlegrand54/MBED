#pragma once

#include "AbstractAI.h"

#include "configuration.h"

#include "PrincessRobot.h"
#include "Match.h"
#include "Timer.h"

#include "Step.h"

#include <string>

class PrincessMatchAI : public AbstractAI {	
public:
	enum AIStep {
		FORWARD,
		ROTATE,
		STARES,
		CARPET,
		END,
		NONE
	};

	const float MAX_SPEED = 0.75;
	const int ROTATE_ANGLE = 15;

	PrincessMatchAI();
	~PrincessMatchAI();

	void log(std::string msg);

	void init();
	void start(Match* match);
	void run();
	void end();

private:
	const int FORWARD_TIME = 9000; // In msec
	const int ROTATE_TIME = 3000;
	const int STARES_TIME = 4000;
	const int END_TIME = 4000;

	PrincessRobot robot;
	Match* match;

	Step<AIStep> currentStep;

	int rotateAngle = 0;

	void processForward();
	void processRotate();
	void processStares();
	void processCarpet();
	void processEnd();
};
