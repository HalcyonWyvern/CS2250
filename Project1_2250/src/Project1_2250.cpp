#include <iostream>
#include <ctime>
#include <cstdlib>

void initialize_array(int[], int);
int inputValidation(); //additional function added for ensuring size numbers are in the correct bounds and getting user input
void swap(int*, int*); //Swap function used in the shuffle_array and selection sort functions
int* shuffle_array(const int[], int);
void print_array(const int[], int);
int* createOddArray(const int[], int, int&);
int* createEvenArray(const int[], int, int&);
void array_war(int*, int, int*, int);
void sort_array(int*, int);

using namespace std;

int main() {
	//Ask user for size of the array and verify their input
	cout << "Enter the size of your Array. Sizes up to 52 are accepted."
			<< endl;
	int arraySize = inputValidation();

	//Create pointer for dynamically allocated array and then initialize an array using the initialize func
	int *arrayOne = nullptr;
	arrayOne = new int[arraySize];
	initialize_array(arrayOne, arraySize);

	//display the original array
	cout << "The original array is:";
	print_array(arrayOne, arraySize);
	cout << endl;

	//shuffle original array and return new array
	int *arrayTwo = shuffle_array(arrayOne, arraySize);

	//delete arrayOne since we no longer use it in the program
	delete[] arrayOne;
	arrayOne = nullptr;

	//Output new shuffled array
	cout << "The shuffled array is:";
	print_array(arrayTwo, arraySize);
	cout << endl;

	//Create odd array from the shuffled array and print it
	int oddSize;
	int *oddArray = createOddArray(arrayTwo, arraySize, oddSize);

	cout << "The odd array is:";
	print_array(oddArray, oddSize);
	cout << endl;

	//Create even array from shuffled array and print it
	int evenSize;
	int *evenArray = createEvenArray(arrayTwo, arraySize, evenSize);

	cout << "The even array is:";
	print_array(evenArray, evenSize);
	cout << endl;

	//input even and odd array into fight function
	array_war(oddArray, oddSize, evenArray, evenSize);

	//delete remaining arrays (not necessary but good practice)
	delete[] arrayTwo, delete[] oddArray, delete[] evenArray;
	arrayTwo = nullptr, oddArray = nullptr, evenArray = nullptr;

	return 0;
}

void initialize_array(int unfilledArray[], int arraySize) {
	for (int i = 0; i < arraySize; i++) {
		unfilledArray[i] = i;
	}

}

int inputValidation() {
	int numValid = 0;
	while (!(cin >> numValid) || numValid < 1 || numValid > 52) {
		cout
				<< "There was an error in your input.\nPlease select a number within the proper range.";
		cin.clear();
		cin.sync();
	}
	return numValid;
}

void swap(int *a, int *b) //function to swap two values
		{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int* shuffle_array(const int arr[], int n) {
	//different seed for new shuffle each time, even if numbers are same
	srand(time(0));

	//create new dynamic array
	int *arrayTwo = nullptr;
	arrayTwo = new int[n];

	//read original array into new array
	for (int i = 0; i < n; i++) {
		arrayTwo[i] = arr[i];
	}

	for (int i = n - 1; i > 0; i--) {
		//select random array index from 0 to n
		int j = rand() % (i + 1);
		swap(&arrayTwo[i], &arrayTwo[j]);
	}
	return arrayTwo;
}

void print_array(const int array[], int arraySize) {
	cout << "[ ";
	for (int i = 0; i < arraySize; i++) {
		cout << array[i] << " ";
	}
	cout << "]";
}

int* createOddArray(const int arr[], int n, int &oddN) {
	//count odd numbers
	oddN = 0; //works like a counter
	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 != 0)
			oddN++;
	}

	//create new dynamically allocated array
	int *oddArray = nullptr;
	oddArray = new int[oddN];

	//populate array
	int holder = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 != 0)
			oddArray[holder++] = arr[i];
	}
	return oddArray;
}

int* createEvenArray(const int arr[], int n, int &evenN) {
	//count even numbers
	evenN = 0; //works like a counter
	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 == 0)
			evenN++;
	}

	int *evenArray = nullptr;
	evenArray = new int[evenN];

	//populate array
	int holder = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 == 0)
			evenArray[holder++] = arr[i];
	}
	return evenArray;
}

void array_war(int *arrayOne, int sizeOne, int *arrayTwo, int sizeTwo) {
	//Determine size of array by comparing the two array sizes
	int arraySize = 0;
	if (sizeOne > sizeTwo) {
		arraySize = sizeOne;
	} else {
		arraySize = sizeTwo;
	}

	//create new array using the determined size
	int *arrayWinner = nullptr;
	arrayWinner = new int[arraySize];

	//running counter
	int i = 0;
	for (; i < sizeOne && i < sizeTwo; i++) {
		if (arrayOne[i] > arrayTwo[i])
			arrayWinner[i] = arrayOne[i];
		else
			arrayWinner[i] = arrayTwo[i];
	}

	//adds any leftovers to the array if the two arrays aren't the same size
	for (; i < sizeOne; i++)
		arrayWinner[i] = arrayOne[i];
	for (; i < sizeTwo; i++)
		arrayWinner[i] = arrayTwo[i];

	//prints the unsorted winners
	cout << "The winners of the array war (unsorted):";
	print_array(arrayWinner, arraySize);
	cout << endl;

	//sorts the winners and prints them out
	cout << "The sorted winners of the array war:";
	sort_array(arrayWinner, arraySize);
	print_array(arrayWinner, arraySize);
	cout << endl;

}

void sort_array(int *arr, int arraySize) //selection sort similar to the book's algorithm
		{
	int i, j, min_index;

	//finds smallest element in arr[0...n] and places at beginning first
	for (i = 0; i < arraySize - 1; i++) {
		min_index = i;
		for (j = i + 1; j < arraySize; j++)
			if (arr[j] < arr[min_index])
				min_index = j;
		//swap function swaps the values
		swap(&arr[min_index], &arr[i]);
	}
}
