#include "PrincessMatchAI.h"

PrincessMatchAI::PrincessMatchAI() : AbstractAI(),
  robot(),
  currentStep(AIStep::NONE)
{

}

PrincessMatchAI::~PrincessMatchAI() {

}

void PrincessMatchAI::log(std::string msg) {
	int time = match == nullptr ? 0 : match->getCurrentTime();
    printf("[%i] %s\n\r",time, msg.c_str());
}

void PrincessMatchAI::init() {
	log("=== INIT ===");
}

void PrincessMatchAI::start(Match* match) {
	log("=== START MATCH! ===");
	this->match = match;
	currentStep.start();

	// The angle depends on our color team
	switch (match->getRobotColor()) {
	case ColorSide::Type::YELLOW:
		rotateAngle = ROTATE_ANGLE; // Left
		break;
	case ColorSide::Type::GREEN:
		rotateAngle = -ROTATE_ANGLE; // Right
		break;
	default:
		break;
	}
	log("=> FORWARD");
	currentStep.change(AIStep::FORWARD);
}

void PrincessMatchAI::run() {
	switch(currentStep.getState()) {
	case AIStep::FORWARD:
		processForward();
		break;
	case AIStep::ROTATE:
		processRotate();
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
	default:
		robot.setMoveSpeed(0);
		break;
	}
}

void PrincessMatchAI::end() {
	log("=== END ===");
}

void PrincessMatchAI::processForward() {
	// Check if an opponent is in front of us
	if(robot.detectFrontOpponent()) {
		robot.brake(1);
		currentStep.pause();
		return;
	}
	// Move forward during FORWARD_TIME
    currentStep.start(); // Do nothing if already started
	robot.setMoveSpeed(MAX_SPEED);

	// Check if step is accomplished
	if (currentStep.isFinished(FORWARD_TIME)) {
		log("=> END");
		currentStep.change(AIStep::END);
	}
}

void PrincessMatchAI::processRotate() {
	// Check if an opponent is in front of us
	if(robot.detectFrontOpponent()) {
		robot.brake(1);
		currentStep.pause();
		return;
	}
	currentStep.start();

	// Set rotation angle
	robot.setRotation(robot.getRotation() + rotateAngle);
	robot.setMoveSpeed(MAX_SPEED);
	
	// End of rotate
	if(currentStep.isFinished(ROTATE_TIME)) {
		currentStep.change(AIStep::STARES);
		log("=> STARES");
		return;
	}
}

void PrincessMatchAI::processStares() {
	// Check if an opponent is in front of us
	if(robot.detectBackOpponent()) {
		robot.brake(1);
		currentStep.pause();
		return;
	}
	// Move backward during STARES_TIME
    currentStep.start(); // Do nothing if already started
	robot.setMoveSpeed(-MAX_SPEED);

	// Check if step is accomplished
	if (currentStep.isFinished(STARES_TIME)) {
		currentStep.change(AIStep::CARPET);
		log("=> CARPET");
	}
}

void PrincessMatchAI::processCarpet() {
	// TODO
	currentStep.change(AIStep::END);
	log("=> END");
}

void PrincessMatchAI::processEnd() {
	// Check if an opponent is in front of us
	if(robot.detectBackOpponent()) {
		robot.brake(1);
		currentStep.pause();
		return;
	}
	// Move forward during END_TIME
    currentStep.start(); // Do nothing if already started
	robot.setMoveSpeed(-MAX_SPEED);

	// Check if step is accomplished
	if (currentStep.isFinished(END_TIME)) {
		// Lolilol, we finished with a dance! :)
		// TODO
		log("=> All done, robot is now in a unstate mode.");
		currentStep.change(AIStep::NONE);
	}
}
