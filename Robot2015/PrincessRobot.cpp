#include "PrincessRobot.h"

#include <exception>
#include <iostream>

PrincessRobot::PrincessRobot() :
	backSensor(SDA, SCL, BACK_SENSOR_ADDRESS, 25),
	leftSensor(SDA, SCL, LEFT_SENSOR_ADDRESS, 25),
	rightSensor(SDA, SCL, RIGHT_SENSOR_ADDRESS, 25),
	directionController(PIN_TX,PIN_RX,ID,BAUD), // ax
	motor(PIN_INA,PIN_INB,PIN_PWM)
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
	setRotation(ANGLE_OFFSET);
}

void PrincessRobot::setMoveSpeed(float speed) {
	motor.speed(speed);
	lastSpeed = speed;
}

void PrincessRobot::brake(float strength) {
	motor.brake(strength);
}

void PrincessRobot::setRotation(float angle, bool block) {
	directionController.setGoalPosition(angle + ANGLE_OFFSET, block);
	lastAngle = angle;
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