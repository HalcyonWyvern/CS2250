#include "Horse.h"
#include <ctime>
#include <cstdlib>

Horse::Horse() {}; //default constructor, makes all int vars 0
Horse::Horse(string n, string r) {
	//this pointer so we don't need reference variables/pointers in param
	this->name = n;
	this->rider = r;

	//we seed random in the main function later
	this->maxRunningDistPerSecond = rand() % 100 + 1;
	this->distanceTraveled = 0;
}

int Horse::runASecond() {
	//adds 0 - maxRun to distance traveled
	// function to "move" the horse along the track
	distanceTraveled += rand() % (maxRunningDistPerSecond + 1);
	return distanceTraveled;
}

int Horse::getDistance() {
	return distanceTraveled;
}

void Horse::sendToGate() {
	distanceTraveled = 0;
}

void Horse::displayHorse(int goalLength) {
	const int DISPLAY_LENGTH = 100; //Maximum of 100 characters displayed on screen
	cout << "|"; //initial gate

	if (distanceTraveled < goalLength) {
		for (int i = 0; i < DISPLAY_LENGTH; i++) {
			if (i == (distanceTraveled * DISPLAY_LENGTH) / goalLength)
				cout << ">";
			else
				cout << "-";
		}
		cout << "| " << name << ", ridden by " << rider << endl;
	} else {
		for (int i = 0; i <= DISPLAY_LENGTH; i++) {
			cout << "-";
		}
		cout << "|> " << name << ", ridden by " << rider << endl;
	}
}

void Horse::winnerDisplay() {
	cout << name << " has won " << racesWon << "/" << races << " races." << endl;
}

void Horse::won() {
	racesWon++;
}

void Horse::increaseRaceCount() {
	races++;
}


Horse::~Horse() {}


