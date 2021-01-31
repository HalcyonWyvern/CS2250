#include<iostream>
#include<string>
#include "Stack.h"
using namespace std;

//struct to hold delimiter info if we pop for output using printf
struct tempHolder {
	char character;
	int lineNum;
	int charCount;
};

void checkForDelimiter(int, int, string, tempHolder*, Stack*); //pops if right delimiter!

int main() {
	//variable declarations
	Stack *delimStack = new Stack();
	tempHolder *temp = new tempHolder;
	string currentLine = "";
	int count = 1;

	cout << "Enter lines of text and to check for proper delimitation:\n";
	do {
		//get user line input
		getline(cin, currentLine, '\n');

		//for loop to check each character for a left delimiter and push to stack if found
		for (unsigned int i = 0; i < currentLine.length(); i++) {
			if (currentLine.at(i) == '[' || currentLine.at(i) == '{' || currentLine.at(i) == '(') {
				delimStack->push(currentLine.at(i), count, i);
			}
			//function checks for matching delimiters and missing left delimiter
			checkForDelimiter(i, count, currentLine, temp, delimStack);
		}
		//increase line count
		count++;

		//code block for missing right delimiter
		while (!delimStack->isEmpty()) {
				delimStack->pop(temp->character, temp->lineNum, temp->charCount);
				printf(
						"Left delimiter %c at line %d, char %d had no right delimiter!\n",
						temp->character, temp->lineNum, temp->charCount);
			}
	} while (currentLine != "DONE");
	cout << "End of Program.";
	return 0;
}

void checkForDelimiter(int i, int count, string currentLine, tempHolder *temp, Stack *delimStack) {
	if (currentLine.at(i) == ']' || currentLine.at(i) == '}' || currentLine.at(i) == ')') {
		//report missing right delimiter!
		if (delimStack->isEmpty()) {
			printf(
					"Right delimiter %c found at line %i, character %i had no left delimiter!\n",
					currentLine.at(i), count, i + 1);
			temp->character = '\0';
			delimStack->pop(temp->character, temp->lineNum, temp->charCount);
			return;
		}
		//pop stack if right delimiter is found
		delimStack->pop(temp->character, temp->lineNum, temp->charCount);

		//checking for mismatched delimiters
		//very messy code section, sorry!
		if (currentLine.at(i) == ')' && temp->character == '(' && temp->character != '\0')
			return;
		else if(currentLine.at(i) == ']' && temp->character == '[' && temp->character != '\0')
			return;
		else if(currentLine.at(i) == '}' && temp->character == '{' && temp->character != '\0')
			return;
		else {
			printf(
					"Mismatched delimiter %c found at line %i, character %i does not match %c found at line %i, character %i\n",
					temp->character, temp->lineNum, temp->charCount,
					currentLine.at(i), count, i + 1);
		}
	}
}

