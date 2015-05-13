#pragma once

#include "AbstractAI.h"

#include "configuration.h"

#include "PrincessRobot.h"
#include "Match.h"
#include "Timer.h"

class PrincessMatchAI : public AbstractAI {	
public:
	enum AIStep {
		FORWARD,
		TURN,
		STARES,
		CARPET,
		END
	};

	PrincessMatchAI();
	~PrincessMatchAI();

	void init();
	void start(Match* match);
	void run();
	void end();

private:
	const int FORWARD_TIME = 5000; // In msec
	const int STARES_TIME = 4000;
	const int END_TIME = 4000;

	PrincessRobot robot;
	Match* match;

	PrincessMatchAI::AIStep currentStep = FORWARD;
	Timer stepTimer;

	void processForward();
	void processTurn();
	void processStares();
	void processCarpet();
	void processEnd();

	bool isStepAccomplished(int maxTime);
	void changeStep(PrincessMatchAI::AIStep step);
};