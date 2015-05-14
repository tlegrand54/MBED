#pragma once

#include "AbstractAI.h"

#include "configuration.h"
#include "Match.h"
#include "PrincessRobot.h"

class TestAI : public AbstractAI{
public:
	void init();
	void start(Match *match);
	void run();
	void end();

	TestAI();
	~TestAI();

private:
	PrincessRobot robot;
	Match *match;
};