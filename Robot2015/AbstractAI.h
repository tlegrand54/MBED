#pragma once

#include "Match.h"

class AbstractAI {
public:
	AbstractAI() {};
	virtual ~AbstractAI() {};

	virtual void init() = 0;
	virtual void start(Match* match) = 0;
	virtual void run() = 0;
	virtual void end() = 0;
};