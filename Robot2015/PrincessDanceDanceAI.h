#pragma once

#include "AbstractAI.h"

class PrincessDanceDanceAI : public AbstractAI {
public:
	PrincessDanceDanceAI();
	~PrincessDanceDanceAI();

	void init();
	void start(Match* match);
	void run();
	void end();

private:

};