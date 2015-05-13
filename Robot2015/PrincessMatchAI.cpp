#include "PrincessMatchAI.h"

PrincessMatchAI::PrincessMatchAI() : AbstractAI(),
  robot()
{

}

PrincessMatchAI::~PrincessMatchAI() {

}


void PrincessMatchAI::init() {

}

void PrincessMatchAI::start(Match* match) {
	this->match = match;
	stepTimer.start();
}

void PrincessMatchAI::run() {
	switch(currentStep) {
	case AIStep::FORWARD:
		processForward();
		break;
	case AIStep::TURN:
		processTurn();
		break;
	case AIStep::STARES:
		processStares();
		break;
	case AIStep::CARPET:
		processCarpet();
		break;
	case AIStep::END:
		processEnd();
		break;
	}
}

void PrincessMatchAI::end() {

}

bool PrincessMatchAI::isStepAccomplished(int maxTime) {
	return stepTimer.read_ms() >= maxTime;
}

void PrincessMatchAI::changeStep(PrincessMatchAI::AIStep step) {
	// Reset timer
	stepTimer.stop();
	stepTimer.reset();

	// Change step
	currentStep = step;

	// Start timer
	stepTimer.start();
}

void PrincessMatchAI::processForward() {
	// Check if an opponent is in front of us
	if(robot.detectFrontOpponent()) {
		robot.brake(1);
		stepTimer.stop();
	}
	else {
		// Move forward during FORWARD_TIME
	    stepTimer.start(); // Do nothing if already started
		robot.setMoveSpeed(1);
	}
	// Check if step is accomplished
	if (isStepAccomplished(FORWARD_TIME)) {
		changeStep(AIStep::TURN);
	}
}

void PrincessMatchAI::processTurn() {
	// The angle depends on our color team
	float angle = 0.0f;
	switch (match->getRobotColor()) {
	case ColorSide::Type::YELLOW:
		angle = -90; // Left
		break;
	case ColorSide::Type::GREEN:
		angle = 90; // Right
		break;
	default:
		break;
	}

	// Rotate (blocking state) the robot
	robot.setRotation(angle);
	changeStep(AIStep::STARES);
}

void PrincessMatchAI::processStares() {
	// Check if an opponent is in front of us
	if(robot.detectFrontOpponent()) {
		robot.brake(1);
		stepTimer.stop();
	}
	else {
		// Move forward during STARES_TIME
	    stepTimer.start(); // Do nothing if already started
		robot.setMoveSpeed(1);
	}
	// Check if step is accomplished
	if (isStepAccomplished(STARES_TIME)) {
		changeStep(AIStep::CARPET);
	}
}

void PrincessMatchAI::processCarpet() {
	// TODO
	changeStep(AIStep::END);
}

void PrincessMatchAI::processEnd() {
	// Check if an opponent is in front of us
	if(robot.detectFrontOpponent()) {
		robot.brake(1);
		stepTimer.stop();
	}
	else {
		// Move forward during END_TIME
	    stepTimer.start(); // Do nothing if already started
		robot.setMoveSpeed(1);
	}
	// Check if step is accomplished
	if (isStepAccomplished(END_TIME)) {
		// Lolilol, we finished with a dance! :)
		robot.setRotation(-180, true);
		robot.setRotation(180, true);
	}
}
