#pragma once

#include "AbstractAI.h"

#include "configuration.h"

#include "PrincessRobot.h"
#include "Match.h"
#include "Timer.h"

#include "Step.h"

class PrincessMatchAI : public AbstractAI {	
public:
	enum AIStep {
		FORWARD,
		START_ROTATE,
		ROTATE,
		END_ROTATE,
		STARES,
		CARPET,
		END
	};

	const int ROTATE_ANGLE = 50;

	PrincessMatchAI();
	~PrincessMatchAI();

	void init();
	void start(Match* match);
	void run();
	void end();

private:
	const int FORWARD_TIME = 5000; // In msec
	const int ROTATE_TIME = 3000;
	const int STARES_TIME = 4000;
	const int END_TIME = 4000;

	PrincessRobot robot;
	Match* match;

	Step<AIStep> currentStep;

	int rotateAngle = 0;

	void processForward();
	void processStartRotate();
	void processRotate();
	void processEndRotate();
	void processStares();
	void processCarpet();
	void processEnd();
};
