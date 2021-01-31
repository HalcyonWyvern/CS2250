#include <iostream>
#include <string>
#include "Stack.h"
using namespace std;

void Stack::push(char character, int lineNum, int charCount) {
	StackNode *newNode;

	newNode = new StackNode;
	newNode->character = character;
	newNode->lineNum = lineNum;
	newNode->charCount = charCount;

	if(isEmpty()) {
		top = newNode;
		newNode->next = NULL;
	} else {
		newNode->next = top;
		top = newNode;
	}
}

void Stack::pop(char &character, int &lineNum, int &charCount) {
	StackNode *temp;

	if(isEmpty()) {
		return; //Originally I had this cout something, but it would cause a lot of output messages on multiple missing left delimiters
	} else {
		character = top->character;
		lineNum = top->lineNum;
		charCount = top->charCount;

		temp = top->next;
		delete top;
		top = temp;
	}
}

bool Stack::isEmpty() const {
	bool x;
	if(!top)
		x = true;
	else
		x = false;
	return x;
}

Stack::~Stack(){
	StackNode *nodePtr, *nextNode;
	nodePtr = top;

	while(nodePtr != nullptr) {
		nextNode = nodePtr->next;
		delete nodePtr;
		nodePtr = nextNode;
	}
}
