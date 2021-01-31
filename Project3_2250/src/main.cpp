//This program simulates a horse race using Horse.h and Horse.cpp
//created by Luke Ledermann
//program makes use of objects, dynamic allocation, and pointers

#include<iostream>
#include<string>
#include<ctime>
#include "Horse.h"

using namespace std;

void inputValid(int&, int);
void inputValid(char&);
Horse * winner(int, int, Horse *); //Finds the winner if any horses have passed the finish



int main() {
	srand(time(0));
	int numHorses = 0, raceLength;
	char next, cont;

	//ask user for number of horses and race length
	cout << "Please enter the number of horses you want: ";
	inputValid(numHorses, 2);
	cout << "Please enter the length of the race. It must be greater than 100.";
	inputValid(raceLength, 100);

	//dynamically allocate horse array using number of horses
	Horse *horses = new Horse[numHorses];

	//loop to get horse names and riders
	for(int i = 0; i < numHorses; i++) {
		string name, rider;
		cout << "Enter the name of horse " << i + 1 << ": ";
		cin.clear();
		cin.sync();
		getline(cin, name);
		cout << "Enter rider " << i + 1 << "'s name: ";
		cin.clear();
		cin.sync();
		getline(cin, rider);

		//call constructor
		horses[i] = Horse(name, rider);
	}

	do {
		//start of the race and ask to continue
		cout << "\nThe start!\n";
		for(int i = 0; i < numHorses; i++)
			horses[i].displayHorse(raceLength);
		cout << "Are you ready for the next second? (y/n): ";
		inputValid(next);

		while (next == 'y') { //race loop
			for(int i = 0; i < numHorses; i++)
				horses[i].runASecond();
			for(int i = 0; i < numHorses; i++)
				horses[i].displayHorse(raceLength);
			if(winner(numHorses, raceLength, horses)->getDistance() >= raceLength) //winner function returns a pointer that we can use member variables with!
				break; // end the race if a horse is a winner

			//cout asking for next second and take input
			cout << "Are you ready for the next second? (y/n): ";
			inputValid(next);
			if(next == 'n')
				break;
		}

		//increase race count after a race has been run
		if(next == 'y') {
			for(int i = 0; i < numHorses; i++)
				horses[i].increaseRaceCount();
		}

		//increase winner win count after a race has been run or ended abruptly by user entering NO during a race
		if(winner(numHorses, raceLength, horses)->getDistance() >= raceLength && next == 'y')
			winner(numHorses, raceLength, horses)->won(); //increment win count of winner

		//reset distanceTraveled for everyone and display the win board
		for(int i = 0; i < numHorses; i++) {
			horses[i].sendToGate();
			horses[i].winnerDisplay();
		}

		//ask user if they want to race these horses again
		cout << "Would you like to race with these horses again? (y/n): ";
		inputValid(cont);


	} while (cont == 'y');

	//delete dynamically allocated horse array;
	delete [] horses;
	return 0;
}

void inputValid(int &input, int minimum) {
	while (!(cin >> input) || input < minimum) {
		cout << "Incorrect number entered. Please choose a valid number." << endl;
		cout << "Races must have more than one horse and a length of 100 or greater!";
		cin.clear();
		cin.sync();
	}
}

void inputValid(char &input) {
	cin >> input;
	input = tolower(input);
	while(input != 'y' && input != 'n') {
		cout << "Please enter lowercase y or lowercase n: ";
		cin.clear();
		cin.sync();
	}
}

Horse * winner(int numHorses, int raceLength, Horse *horsePtr) {
	int horseWinnerNum = 0;
	int highestDistance = 0;

	for(int i = 0; i < numHorses; i++) {
		if(horsePtr[i].getDistance() > highestDistance) {
			highestDistance = horsePtr[i].getDistance();
			horseWinnerNum = i;
		} else if (horsePtr[i].getDistance() == highestDistance) {
			horseWinnerNum = i + (rand() % 2);
			highestDistance = horsePtr[i + (rand() % 2)].getDistance();
		}
	}
	return &horsePtr[horseWinnerNum];
}
