#include <iostream>
#include <fstream>
#include <string>
#include "BinaryTree.h"

using namespace std;

int inputValid();

int main() {
	//get user input of string length and allocate mem for binary tree
	int k = inputValid();
	BinaryTree *charTree = new BinaryTree;

	//open file to read characters from
	ifstream *file = new ifstream("input.txt");
	if(!file)
		cout << "Unable to find input. Please try again.";

	//read individual chars into fileInput string
	string x;
	string fileInput = "";
	while(*file >> x) {
		*file >> x;
		fileInput.append(x);
	}

	//whitespace removal
	for(unsigned int i = 0; i < fileInput.length(); i++) {
		if(!isalpha(fileInput[i]))
			fileInput.erase(i);
	}

	//cout to ensure input went through correctly
	cout << "File Input:" << fileInput << endl;

	//read file input into binary tree
	for(int i = 1; i <= k; i++) {
		for(unsigned int j = 1; j <= fileInput.length()-(i-1); j++) {
			charTree->inputChars(charTree->root, fileInput.substr((j-1), i));
		}
	}

	charTree->printChars(charTree->root);
	delete charTree;
	return 0;
}

int inputValid() {
	int k = 0;
	cout << "Please enter the max length of letter sequences you would like displayed: ";
	while (!(cin >> k) || k < 1) {
		cout << "There was an error in your input.\n Please select a positive integer.";
		cin.clear();
		cin.sync();
	}
	return k;
}
