#pragma once

#include "configuration.h"
#include "ColorSide.h"

class PrincessRobot {

public:
	const int BACK_SENSOR_ADDRESS = 0xE2;
	const int LEFT_SENSOR_ADDRESS = 0xE4;
	const int RIGHT_SENSOR_ADDRESS = 0xE6;

	PrincessRobot();
	~PrincessRobot();

	// Wait for match to be start
	void init();

	// 1 => full speed, 0 => stop, -1 => backward
	void setMoveSpeed(float speed);
	void brake(float strength);

	void setRotation(float angle, bool block = false);
	void deployRedCarpet();

	void terminate();

	inline void setColorSide(ColorSide::Type colorSide) {
		this->colorSide = colorSide;
	}

private:
	SRF08 backSensor; // SRF08 ranging module 1 capteur arrière
	SRF08 leftSensor; // SRF08 ranging module 2 capteur gauche
	SRF08 rightSensor; // SRF08 ranging module 3 capteur droit

	AX12 directionController; // Permet de contrôler l'AX12 pour faire la direction du robot

	VNH5019 motor; // Permet de contrôler le moteur

	ColorSide::Type colorSide;

	// True if carpet already deployed
	// TODO
	// bool carpetDeployed = false;
};