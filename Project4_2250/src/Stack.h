#ifndef STACK_H
#define STACK_H

//class declaration for DYNAMIC stack
class Stack {
private:
	struct StackNode {
		char character;
		int lineNum;
		int charCount;
		StackNode *next;
	};
	StackNode *top;
public:
	//Constructor creates empty stack with top pointing to NULL
	Stack()
		{ top = nullptr;}

	//Destructor
	~Stack();

	//Stack operations
	void push(char, int, int);
	void pop(char &, int &, int &);
	bool isEmpty() const;
};
#endif
