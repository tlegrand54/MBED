#pragma once

#include "Timer.h"

template<typename T>
class Step {
public:
	Step(T initStep) {};
	~Step() {};

	void start() {
		timer.start();
	}

	void pause() {
		timer.stop();
	}

	bool isFinished(int maxTime) {
		return timer.read_ms() >= maxTime;
	}

	inline T getState() {
		return currentStep;
	}

	// In ms
	int getTime() {
		return timer.read_ms();
	}

	void change(T step) {
		// Reset timer
		timer.stop();
		timer.reset();

		// Change step
		currentStep = step;

		// Start timer
		timer.start();
	}

private:
	T currentStep;
	Timer timer; 
};