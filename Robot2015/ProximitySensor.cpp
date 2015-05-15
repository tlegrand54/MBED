#include "ProximitySensor.h"

ProximitySensor::ProximitySensor(PinName sda,
								 PinName scl,
								 int i2cAddress,
								 int opponentThreshold) :
	sensor(sda, scl, i2cAddress),
	opponentThreshold(opponentThreshold)
{

}

ProximitySensor::~ProximitySensor() {

}


bool ProximitySensor::detectOpponent() {
	// Multiple tests to avoid false negatives
	// We still consider we have an enemy until the sensor
	// says we have nothing during DETECT_TEST_NUMBER times
	for(int i = 0 ; i < DETECT_TEST_NUMBER ; i++) {
		int distance = mesureOpponentDistance();
		if(distance < opponentThreshold)
			return true;
	}
	return false;
}

int ProximitySensor::mesureOpponentDistance() {
	sensor.startRanging();
	while (!sensor.rangingFinished()) wait(0.01);
	printf("\n\rDEBUG sensor distance => %i", sensor.getRange());
	return sensor.getRange();
}