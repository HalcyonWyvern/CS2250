//C++ program to convert a sentence to Pig Latin using string funcs and structs
#include <iostream>
#include <cctype>
#include <string>

using namespace std;

struct Word {
	string english;
	string piglatin;
};

//function prototypes
Word* splitSentence(const string, int&);
bool vowelCheck(char); //function used inside of convertToPigLatin
void convertToPigLatin(Word[], int);
void displayPigLatin(const Word[], int);

int main() {

	//Declare variables used in splitSentence function
	string userInput;
	int size = 0;

	//Get user sentence input
	cout << "Please enter a sentence to convert to Pig Latin!" << endl;
	getline(cin, userInput);

	//Creation of ptr to word
	Word *wordptr = splitSentence(userInput, size);

	//Conversion of individual words to pig latin
	convertToPigLatin(wordptr, size);

	//Display new sentence
	displayPigLatin(wordptr, size);

	//delete since we no longer need it
	delete [] wordptr;
	wordptr = nullptr;

	return 0;
}

Word* splitSentence(const string words, int &size) {

	//Variable declarations
	bool space = true;
	int wordCount = 0;
	char ch;

	//For loop to count the number of words for our dynamic array
	for (unsigned int i = 0; i < words.length(); i++) {
		ch = words[i];
		if (isspace(ch) || !isalpha(ch))
			space = true;

		else if (space) {
			space = false;
			++wordCount;
		}
	}

	//Create new Word with dynamic mem allocation
	size = wordCount;
	Word *engWords = new Word[wordCount];

	//Counters reset and index for word created [start at -1 because our first element is 0]
	space = true;
	int wordNumber = -1;

	//For loop to actually read the words into the new Word
	for (unsigned int i = 0; i < words.length(); i++) {
		ch = words[i];
		if (isspace(ch) || !isalpha(ch)) {
			space = true;
		} else if (isalpha(ch)) {
			if (space) {
				++wordNumber;
				space = false;
			}
			if (isupper(ch)) {
				ch = tolower(ch);
			}
			engWords[wordNumber].english += ch;
		}
	}
	return engWords;
}

bool vowelCheck(char c) {
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
		return true;
	else
		return false;
}

void convertToPigLatin(Word wordArr[], int size) {

	for (int i = 0; i < size; i++) {

		//Appends "way" if a vowel and "ay" if a consonant
		if (vowelCheck(wordArr[i].english[0])) {
			wordArr[i].piglatin = wordArr[i].english.append("way");
		} else {
			wordArr[i].piglatin = wordArr[i].english.substr(1, wordArr[i].english.length() - 1)
					+ wordArr[i].english.front() + "ay";
		}
	}

}

void displayPigLatin(const Word wordArr[], int size) {
	//Loop to go through each word with a space between them
	for (int i = 0; i < size; i++) {
		cout << wordArr[i].piglatin << " ";
	}

}
