using namespace std;
#ifndef HORSE_H
#define HORSE_H
#include <iostream>
#include <string>


class Horse {
private:
	string name; //User input
	string rider; //User input
	int maxRunningDistPerSecond = 0; //randomly assigned to each horse
	int distanceTraveled = 0;
	int racesWon = 0; //automatically starts at zero no matter what and increments after each win
	int races = 0; //race counter for our winnerDisplay at the end of each race
public:
	Horse(); //default constructor
	Horse(string, string); //constructor that accepts name and rider
	int runASecond(); //returns an int between zero and maxRunningDist
	int getDistance(); //return distance traveled
	void sendToGate(); //Resets horse to start of race by setting distanceTraveled to 0
	void displayHorse(int); //scaled ascii graphics to show where the horse is relative to others
	void winnerDisplay(); //easy display of racesWon and horse/rider.
	void won(); //increases racesWon by one if the horse has won
	void increaseRaceCount(); //increases races by one after each new race

	~Horse(); //destructor
};

#endif /* HORSE_H */
