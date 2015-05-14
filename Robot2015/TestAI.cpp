#include "TestAI.h"

TestAI::TestAI() : AbstractAI(),
  robot()
{

}

TestAI::~TestAI() {

}


void TestAI::init() {
	printf("je suis là\n");
}

void TestAI::start(Match* match) {
	this->match = match;
}

void TestAI::run() {
	printf("mise en route des moteurs\n");

	robot.setRotation(0);

	robot.setMoveSpeed(-0.5);

	wait(5);

	printf("stop des moteurs\n");

	robot.setRotation(300);

	robot.setMoveSpeed(0);

	wait(5);
}

void TestAI::end() {

}