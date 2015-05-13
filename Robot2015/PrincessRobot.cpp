#include "PrincessRobot.h"

#include <exception>
#include <iostream>

PrincessRobot::PrincessRobot() :
	backSensor(SDA, SCL, BACK_SENSOR_ADDRESS),
	leftSensor(SDA, SCL, LEFT_SENSOR_ADDRESS),
	rightSensor(SDA, SCL, RIGHT_SENSOR_ADDRESS),
	directionController(PIN_TX,PIN_RX,ID,BAUD), // ax
	motor(PIN_INA,PIN_INB,PIN_ENDIAG,PIN_CS,PIN_PWM)
{
	this->init();
}

PrincessRobot::~PrincessRobot() {
	this->terminate();
}

void PrincessRobot::init() {
	// Setup serv rotation
	directionController.setCWLimit(0);
	directionController.setCCWLimit(300);
	std::cout << "\rMise à 0 de la position" << std::endl;
	directionController.setGoalSpeed(0);
}

void PrincessRobot::setMoveSpeed(float speed) {
	motor.speed(speed);
}

void PrincessRobot::brake(float strength) {
	motor.brake(strength);
}

void PrincessRobot::setRotation(float angle, bool block) {
	directionController.setGoalPosition(angle, block);
}

bool PrincessRobot::detectFrontOpponent() {
	return leftSensor.detectOpponent() || rightSensor.detectOpponent();
}

bool PrincessRobot::detectBackOpponent() {
	return backSensor.detectOpponent();
}

void PrincessRobot::deployRedCarpet() {
	// TODO
}

void PrincessRobot::terminate() {
	// Stop motors
	motor.stop();
}