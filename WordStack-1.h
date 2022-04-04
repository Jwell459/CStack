/*
James Stockwell

Programming Assignment Chapter 19

October 2021
*/

#include <string>
#pragma once

using namespace std;

/*----------------------------------------------------------------------------------------------------------------
class name:		WordStack

attributes:		stuct WordNode { string word, struct WordNode *next}, WordNode *head
methods:		WordStack, ~WordStack,
				push, pop, getHead, displayNodes, stackSize, blankCheck

A linked list that acts as a dynamic stack for the Virtual Adlib Game.
----------------------------------------------------------------------------------------------------------------*/


class WordStack {

private:
	struct WordNode {			//Data node that holds a word string and a pointer to the next node
		string word;			//Stores the word element for the node
		struct WordNode *next;	//Points to the next node in the list
	};
	struct WordNode *head;		//Pointer to the first node of the list




	public:
		
		//Constructor
		WordStack();

		//Deconstructor
		~WordStack();
		
		void push(string);				//Insert a new node as head of list
		string pop();					//Delete the current head of the list and return its word
		struct WordNode * getHead();	//Retruns the stack's head pointer
		int stackSize();				//Returns the number of nodes in the stack
		void displayNodes();			//Traverses the stack and displays every word value
		bool blankCheck(string word);	//Determines if given string is made up of only whitespace characters or not

};
