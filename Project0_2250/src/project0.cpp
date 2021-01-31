#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

const int ARRAY_SIZE = 5; //size of our array for correct guesses
int distanceToClosest(const int [], int, int);
void sortArray(int [], int); //bubble sort function
void initializeArray(int [], int); //creates the array of random numbers
void swap(int*, int*); //function to swap vaues
int inputValidation(); //easy input validation


int main() {
	int correctAnswers[ARRAY_SIZE];
	int guess, distance;
	initializeArray(correctAnswers, ARRAY_SIZE);
	sortArray(correctAnswers, ARRAY_SIZE);

	cout << "There are five numbers hidden. Try to find one!" << endl;
	cout << "Choose a number between 1 and 1000: " << endl;
	guess = inputValidation();
	distance = distanceToClosest(correctAnswers, ARRAY_SIZE, guess);

	if(distance == 0) {
		cout << "You guessed correctly on your first try! Great job!";
		return 0;
	}
	else
		cout << "You guessed incorrectly on your first try. Please try again!" << endl;

	//loop as long as the guess is not right
	while(distance != 0) {
		cout << "Please guess a number: " << endl;
		guess = inputValidation();

		if(distanceToClosest(correctAnswers, ARRAY_SIZE, guess) == 0){
			cout << "You guessed the correct number!" << endl;
			return 0;
		}
		else if(distanceToClosest(correctAnswers, ARRAY_SIZE, guess) <= distance) {
			cout << "You are getting WARMER!" << endl;
		}
		else {
			cout << "You are getting COLDER!!" << endl;
		}
		distance = distanceToClosest(correctAnswers, ARRAY_SIZE, guess);
	}

	return 0;
}

//Function used inside of Bubble Sort
void swap(int *xp, int *yp) {
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

//Initializes the array with random numbers each time
void initializeArray(int newArray[], int size) {
	unsigned seed = time(0);
	srand(seed);
	for(int i = 0; i < size; i++){
		newArray[i] = 1 + (rand() % 1000);
	}
}

//Bubble Sort to sort the Array from lowest to highest value
void sortArray(int unsortedArray[], int size) {
	int i, j;
	for(i = 0; i < (size - 1); i++) {


	for(j = 0; j < (size - i - 1); j++)
		if(unsortedArray[j] > unsortedArray[j + 1])
			swap(&unsortedArray[j], &unsortedArray[j + 1]);
	}
}

int distanceToClosest(const int sortedArray[], int size, int guess) {
	int distance;
	distance = abs(sortedArray[0] - guess);

	for(int i = 1; i < size; i++) {
		if(abs(sortedArray[i] - guess) < distance) {
			distance = abs(sortedArray[i] - guess);
		}
	}
	return distance;
}

int inputValidation() {
	int numValid = 0;
		while (!(cin >> numValid) || numValid < 1 || numValid > 1000) {
			cout
					<< "There was an error in your input.\n Please select a number within the proper range.";
			cin.clear();
			cin.sync();
		}
		return numValid;
}
