#include "PrincessMatchAI.h"

PrincessMatchAI::PrincessMatchAI() : AbstractAI(),
  robot(),
  currentStep(FORWARD)
{

}

PrincessMatchAI::~PrincessMatchAI() {

}


void PrincessMatchAI::init() {

}

void PrincessMatchAI::start(Match* match) {
	this->match = match;
	currentStep.start();

	// The angle depends on our color team
	switch (match->getRobotColor()) {
	case ColorSide::Type::YELLOW:
		rotateAngle = -ROTATE_ANGLE; // Left
		break;
	case ColorSide::Type::GREEN:
		rotateAngle = ROTATE_ANGLE; // Right
		break;
	default:
		break;
	}
}

void PrincessMatchAI::run() {
	switch(currentStep.getState()) {
	case AIStep::FORWARD:
		processForward();
		break;
	case AIStep::START_ROTATE:
		processStartRotate();
		break;
	case AIStep::ROTATE:
		processRotate();
		break;
	case AIStep::END_ROTATE:
		processEndRotate();
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

void PrincessMatchAI::processForward() {
	// Check if an opponent is in front of us
	if(robot.detectFrontOpponent()) {
		robot.brake(1);
		currentStep.pause();
	}
	else {
		// Move forward during FORWARD_TIME
	    currentStep.start(); // Do nothing if already started
		robot.setMoveSpeed(1);
	}
	// Check if step is accomplished
	if (currentStep.isFinished(FORWARD_TIME)) {
		currentStep.change(AIStep::START_ROTATE);
	}
}

void PrincessMatchAI::processStartRotate() {
	// No speed when turning
	robot.setMoveSpeed(0);

	// Set rotation angle;
	robot.setRotation(robot.getRotation() + rotateAngle, true);

	currentStep.change(AIStep::ROTATE);
}

void PrincessMatchAI::processRotate() {
	// Check if an opponent is in front of us
	if(robot.detectFrontOpponent()) {
		robot.brake(1);
		currentStep.pause();
		return;
	}

	// End of rotate
	if(currentStep.isFinished(ROTATE_TIME)) {
		currentStep.change(AIStep::END_ROTATE);
		return;
	}

	// Just go on
	robot.setMoveSpeed(0.5);
}

void PrincessMatchAI::processEndRotate() {
	// No speed when turning
	robot.setMoveSpeed(0);

	// Set rotation angle;
	robot.setRotation(robot.getRotation() - rotateAngle, true);

	currentStep.change(AIStep::STARES);
}

void PrincessMatchAI::processStares() {
	// Check if an opponent is in front of us
	if(robot.detectFrontOpponent()) {
		robot.brake(1);
		currentStep.pause();
	}
	else {
		// Move forward during STARES_TIME
	    currentStep.start(); // Do nothing if already started
		robot.setMoveSpeed(1);
	}
	// Check if step is accomplished
	if (currentStep.isFinished(STARES_TIME)) {
		currentStep.change(AIStep::CARPET);
	}
}

void PrincessMatchAI::processCarpet() {
	// TODO
	currentStep.change(AIStep::END);
}

void PrincessMatchAI::processEnd() {
	// Check if an opponent is in front of us
	if(robot.detectFrontOpponent()) {
		robot.brake(1);
		currentStep.pause();
	}
	else {
		// Move forward during END_TIME
	    currentStep.start(); // Do nothing if already started
		robot.setMoveSpeed(1);
	}
	// Check if step is accomplished
	if (currentStep.isFinished(END_TIME)) {
		// Lolilol, we finished with a dance! :)
		robot.setRotation(-180, true);
		robot.setRotation(180, true);
	}
}
