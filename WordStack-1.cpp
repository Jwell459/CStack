/*
James Stockwell

Programming Assignment Chapter 19

October 2021
*/

#include <iostream>
#include "WordStack.h"


/*----------------------------------------------------------------------------------------------------------------
class name:		WordStack

attributes:		stuct WordNode { string word, struct WordNode *next}, WordNode *head
methods:		WordStack, ~WordStack,
				push, pop, getHead, displayNodes, stackSize, blankCheck

A linked list that acts as a dynamic stack for the Virtual Adlib Game.
----------------------------------------------------------------------------------------------------------------*/

/************************************************************************************
name:		WordStack
called by:	main
passed:		none
returns:	none
calls:		none

Default constructor. Initializes head to a nullptr.
************************************************************************************/
WordStack::WordStack() {
	head = nullptr;
}

/************************************************************************************
name:		~WordStack
called by:	main
passed:		none
returns:	none
calls:		none

Default deconstructor. Goes through WordStack and deletes every node and then turns head into a nullptr.
************************************************************************************/
WordStack::~WordStack() {
	WordNode *currentNode = head;
	while (currentNode != nullptr) {
		WordNode *temp = currentNode->next;
		delete currentNode;
		currentNode = temp;
	}
	head = nullptr;
}

/************************************************************************************
name:		push
called by:	main
passed:		string word
returns:	none
calls:		none

First checks if input is within the size specifications. If so, then puts the word into
a node and places it on top of the stack.
************************************************************************************/
void WordStack::push(string word) {
	WordNode *newNode = new WordNode;

	//Input Validation
	if (word.length() < 1 || word == " ") {	//Checks if word is empty
		cout << "Error: no word was given.\n";
		exit(EXIT_FAILURE);
	}
	else if (word.length() > 10) {			//Checks if word is too long
		cout << "Error: word is longer than 10 characters.\n";
		exit(EXIT_FAILURE);
	}
	else if (blankCheck(word) == false) {			//Checks if word is only made of spaces and tabs
		cout << "Error: word is only made up of whitespace characters .\n";
		exit(EXIT_FAILURE);
	}

	newNode->word = word;		//Puts the input into a new node

	if (!head) {		//If the list is empty, this becomes the head
		head = newNode;
		newNode->next = nullptr;

	}
	else {				//If the stack is not empty, the node is inserted as the new head element
		newNode->next = head;
		head = newNode;
	}

}

/************************************************************************************
name:		pop
called by:	main
passed:		none
returns:	string temp
calls:		none

First checks if stack is non-empty. If so, then returns the word stored in the stack's head
and then deletes the head node.
************************************************************************************/
string WordStack::pop() {

	string temp;

	//Validation, check if there are any words in the stack
	if (!head) {
		cout << "The Word Stack is empty, nothing to pop.\n";
		exit(EXIT_FAILURE);
	}

	//Stores the current head->word value so it can be returned after the node's deletion deletion
	temp = head->word;

	//Makes the head->next the new head and deletes the original head
	WordNode *nodePtr = head;
	head = head->next;
	delete nodePtr;

	return temp;
}

/************************************************************************************
name:		getHead
called by:	main
passed:		none
returns:	WordStack::WordNode * head
calls:		none

Returns the head of the linked list.
************************************************************************************/
WordStack::WordNode * WordStack::getHead(){
	return head;
}

/************************************************************************************
name:		displayNodes
called by:	main
passed:		none
returns:	none
calls:		none

Traverses the list and displays the word elmenet of every node. If the list is empty
then it will display a message saying so.
************************************************************************************/
void WordStack::displayNodes() {

	WordNode *nodePtr;
	int count = 0;

	if (!head) {		//If the list is empty then say the stack is empty
		cout << "Empty stack\n";

	}
	else {				//Otherwise, traverse the list and print each word element.
		nodePtr = head;
		while (nodePtr != nullptr){
			cout << "(" << count << ") " << nodePtr->word << "\n";
			nodePtr = nodePtr->next;
			count++;
		}
	}
	cout << '\n';

}

/************************************************************************************
name:		stackSize
called by:	main
passed:		none
returns:	int count
calls:		none

Returns the head of the linked list.
************************************************************************************/
int WordStack::stackSize() {
	WordNode *nodePtr;
	int count = 0;
	if (!head) {
		return count;
	}
	else {
		nodePtr = head;
		while (nodePtr != nullptr) {
			
			nodePtr = nodePtr->next;
			count++;
		}
		return count;
	}

}

/************************************************************************************
name:		blankCheck
called by:	push
passed:		string word
returns:	bool
calls:		none

Determines if the given string is only made of whitespace characters or not.
************************************************************************************/
bool WordStack::blankCheck(string word) {
	int count = 0;
	for (int i = 0; i < word.length(); i++) {		//Loop through the word string
		if (word[i] == ' ' || word[i] == '\t' || word[i] == '\n') {	//If a whitespace character is found, incrament count
			count++;
		}
	}

	if (count == word.length()) {
		return false;	//If only whitespace chracters were found, returnf false
	}
	else {
		return true;	//Otherwise return true
	}
}