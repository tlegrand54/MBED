#pragma once

#include "configuration.h"

class ProximitySensor {
public:

	const static int DEFAULT_THRESHOLD = 15; // In cm
	const static int DETECT_TEST_NUMBER = 3; // Avoir false negatives

	ProximitySensor(PinName sda,
					PinName scl,
					int i2cAddress,
					int opponentThreshold = DEFAULT_THRESHOLD);
	~ProximitySensor();

	int mesureOpponentDistance();
	bool detectOpponent();

private:
	SRF08 sensor;
	int opponentThreshold;
};