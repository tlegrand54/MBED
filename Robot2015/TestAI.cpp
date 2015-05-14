#include "TestAI.h"

TestAI::TestAI() : AbstractAI(),
  robot()
{

}

TestAI::~TestAI() {

}


void TestAI::init() {
	printf("\n\rTESTS TESTS TESTS");
}

void TestAI::start(Match* match) {
	this->match = match;
}

void TestAI::run() {
	printf("\n\r\n\r=== MOTOR TESTS ===\n\r");

	robot.setRotation(0);

	printf("\n\r=> +1.0");
	robot.setMoveSpeed(+1.0);
	wait(2);

	printf("\n\r=> +0.5");
	robot.setMoveSpeed(+0.5);
	wait(2);

	printf("\n\r=> +0");
	robot.setMoveSpeed(0);
	wait(2);

	printf("\n\r=> -0.5");
	robot.setMoveSpeed(-0.5);
	wait(2);

	printf("\n\r=> -1.0");
	robot.setMoveSpeed(-1.0);
	wait(2);

	robot.setMoveSpeed(0);
	printf("\n\r\n\r=== ROTATION TESTS ===");

	printf("\n\r=> 0");
	robot.setRotation(0);
	wait(2);

	printf("\n\r=> 60");
	robot.setRotation(60);
	wait(2);

	printf("\n\r=> 150");
	robot.setRotation(150);
	wait(2);

	printf("\n\r=> 220");
	robot.setRotation(220);
	wait(2);

	printf("\n\r=> 300");
	robot.setRotation(300);
	wait(2);

	robot.setRotation(0);
	printf("\n\r\n\r=== SENSOR TESTS ===");

	printf("\n\r=> Front");
	for(int i = 0; i < 5; i++) {
		if(robot.detectFrontOpponent())
			printf("\n\rEnemy detected");
		else
			printf("\n\rNo enemy detected");
		wait(2);
	}

	printf("\n\r=> Back");
	for(int i = 0; i < 5; i++) {
		if(robot.detectBackOpponent())
			printf("\n\rEnemy detected");
		else
			printf("\n\rNo enemy detected");
		wait(2);
	}
}

void TestAI::end() {

}