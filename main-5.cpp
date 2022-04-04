/*
James Stockwell

Programming Assignment Chapter 19

October 2021
*/

#include <string>
#include <iostream>
#include "WordStack.h"

using namespace std;

//Prototypes for functions
void menu(WordStack *nouns, WordStack *verbs, WordStack *adjectives);
void callPushNoun(WordStack *nouns, WordStack *verbs, WordStack *adjectives);
void callPopNoun(WordStack *nouns, WordStack *verbs, WordStack *adjectives);
void callPushVerb(WordStack *nouns, WordStack *verbs, WordStack *adjectives);
void callPopVerb(WordStack *nouns, WordStack *verbs, WordStack *adjectives);
void callPushAdj(WordStack *nouns, WordStack *verbs, WordStack *adjectives);
void callPopAdj(WordStack *nouns, WordStack *verbs, WordStack *adjectives);
void displayStacks(WordStack *nouns, WordStack *verbs, WordStack *adjectives);
void makeStory(WordStack *nouns, WordStack *verbs, WordStack *adjectives);
void exit(WordStack *nouns, WordStack *verbs, WordStack *adjectives);
string inputValidation(int type);
bool blankCheck(string word);

/************************************************************************************
name:		main
called by:	none
passed:		none
returns:	none
calls:		menu

Starts the program. Initializes 3 pointers to empty word stacks for use in the rest 
of the program then passes them to menu
************************************************************************************/
int main() {
	WordStack *nouns = new WordStack;		//Stack for nouns
	WordStack *verbs = new WordStack;		//Stack for verb
	WordStack *adjectives = new WordStack;	//Stack for adjectives

	cout << "Welcome to the game!\n\n";		//Greeting message
	menu(nouns, verbs, adjectives);
};

/************************************************************************************
name:		menu
called by:	main, callPushNoun, callPopNoun, callPushVerb, callPopVerb, callPushAdj, callPopAdj,
			displayStacks, makeStory
passed:		WordStack *nouns, WordStack *verbs, WordStack *adjectives
returns:	none
calls:		callPushNoun, callPopNoun, callPushVerb, callPopVerb, callPushAdj, callPopAdj,
			displayStacks, makeStory, exit

Displays a choice menu for the user and asks the user to choose one of them. The user input
then goes into a switch statment to call the appropriate function.
************************************************************************************/
void menu(WordStack *nouns, WordStack *verbs, WordStack *adjectives) {

	int choice;		//Stores user's choice

	cout << "1. Push Noun\n" <<			//Displayed choice menu
		"2. Pop Noun\n" <<
		"3. Push Verb\n"
		"4. Pop Verb\n" <<
		"5. Push Adjective\n" <<
		"6. Pop Adjective\n" <<
		"7. Display all Stacks\n" <<
		"8. Make a Story \n" <<
		"9. Exit Game\n";

	cout << "Please choose a menu option: ";	//Asks for user input
	while (!(cin >> choice) || (choice < 1) || (choice > 9)) { //Validates that the integer is from 1 to 9
		cout << "Invalid input, please try again: ";
		cin.clear();
		cin.ignore(100, '\n');
	}

	switch (choice) {		//Takes user input can calls the appropriate function
		case 1:
			callPushNoun(nouns, verbs, adjectives);
			break;
		case 2: 
			callPopNoun(nouns, verbs, adjectives);
			break;
		case 3:
			callPushVerb(nouns, verbs, adjectives);
			break;
		case 4:
			callPopVerb(nouns, verbs, adjectives);
			break;
		case 5:
			callPushAdj(nouns, verbs, adjectives);
			break;
		case 6:
			callPopAdj(nouns, verbs, adjectives);
			break;
		case 7:
			displayStacks(nouns, verbs, adjectives);
			break;
		case 8:
			makeStory(nouns, verbs, adjectives);
			break;
		case 9:
			exit(nouns, verbs, adjectives);
			break;

	}
}


/************************************************************************************
name:		callPushNoun
called by:	menu
passed:		WordStack *nouns, WordStack *verbs, WordStack *adjectives
returns:	none
calls:		inputValidation, menu

Choice 1
Call inputValidation to get user input for a noun, call the nouns->push method to 
push it onto the top of the noun stack, and then call menu again.
************************************************************************************/
void callPushNoun(WordStack *nouns, WordStack *verbs, WordStack *adjectives) {
	string inputWord = inputValidation(1);		//Calls inputValidation for user input
	nouns->push(inputWord);						//Calls nouns->push to put input on top of the stack
	menu(nouns, verbs, adjectives);
}

/************************************************************************************
name:		callPopNoun
called by:	menu
passed:		WordStack *nouns, WordStack *verbs, WordStack *adjectives
returns:	none
calls:		menu

Choice 2
If the nouns stack is not empty, calls nouns->pop to remove the first entry 
in the nouns stack.
************************************************************************************/
void callPopNoun(WordStack *nouns, WordStack *verbs, WordStack *adjectives) {

	if (!(nouns->getHead())) {		//Checks if the stack is empty
		cout << "Noun stack is empty, nothing to pop.\n";
	}
	else {							//If not empty, pop the top element
		nouns->pop();
		cout << "The nouns stack was successfully poppped.\n";
	}
	cout << '\n';
	menu(nouns, verbs, adjectives);
}


/************************************************************************************
name:		callPushVerb
called by:	menu
passed:		WordStack *nouns, WordStack *verbs, WordStack *adjectives
returns:	none
calls:		inputValidation, menu

Choice 3
Call inputValidation to get user input for a verb, call the verb->push method to
push it onto the top of the verbs stack, and then call menu again.
************************************************************************************/
void callPushVerb(WordStack *nouns, WordStack *verbs, WordStack *adjectives) {
	string inputWord = inputValidation(2);		//Calls inputValidation for user input
	verbs->push(inputWord);						//Calls verbs->push to put input on top of the stack
	menu(nouns, verbs, adjectives);
}

/************************************************************************************
name:		callPopVerb
called by:	menu
passed:		WordStack *nouns, WordStack *verbs, WordStack *adjectives
returns:	none
calls:		menu

Choice 4
If the verbs stack is not empty, calls verbs->pop to remove the first entry
in the noun stack.
************************************************************************************/
void callPopVerb(WordStack *nouns, WordStack *verbs, WordStack *adjectives) {

	if (!(verbs->getHead())) {		//Checks if the stack is empty
		cout << "Verb stack is empty, nothing to pop.\n";
	}
	else {							//If not empty, pop the top element
		verbs->pop();
		cout << "The verbs stack was successfully poppped.\n";
	}
	cout << '\n';
	menu(nouns, verbs, adjectives);
}


/************************************************************************************
name:		callPushAdj
called by:	menu
passed:		WordStack *nouns, WordStack *verbs, WordStack *adjectives
returns:	none
calls:		inputValidation, menu

Choice 5
Call inputValidation to get user input for an adjective, calls the adjectives->push method to
push it onto the top of the adjectives stack, and then calls menu again.
************************************************************************************/
void callPushAdj(WordStack *nouns, WordStack *verbs, WordStack *adjectives) {
	string inputWord = inputValidation(3);		//Calls inputValidation for user input
	adjectives->push(inputWord);				//Calls adjectives->push to put input on top of the stack
	menu(nouns, verbs, adjectives);
}

/************************************************************************************
name:		callPopAdj
called by:	menu
passed:		WordStack *nouns, WordStack *verbs, WordStack *adjectives
returns:	none
calls:		menu

Choice 6
If the adjectives stack is not empty, calls adjectives->pop to remove the first entry
in the adjectives stack.
************************************************************************************/
void callPopAdj(WordStack *nouns, WordStack *verbs, WordStack *adjectives) {

	if (!(adjectives->getHead())) {		//Checks if the stack is empty
		cout << "Adjective stack is empty, nothing to pop.\n";
	}
	else {							//If not empty, pop the top element
		adjectives->pop();
		cout << "The adjective stack was successfully poppped.\n";
	}
	cout << '\n';
	menu(nouns, verbs, adjectives);
}

/************************************************************************************
name:		displayStacks
called by:	menu
passed:		WordStack *nouns, WordStack *verbs, WordStack *adjectives
returns:	none
calls:		menu

Choice 7
Displays all words currently in each stack by calling the stacks' displayNodes() method.
************************************************************************************/
void displayStacks(WordStack *nouns, WordStack *verbs, WordStack *adjectives) {
	cout << "Here are the current stacks:\n";
	cout << "Nouns:\n";			//Nouns stack
	nouns->displayNodes();
	cout << "Verbs:\n";			//Verbs stack
	verbs->displayNodes();
	cout << "Adjectives:\n";	//Adkjjectives stack
	adjectives->displayNodes();
	cout << '\n';
	
	menu(nouns, verbs, adjectives);

}

/************************************************************************************
name:		makeStory
called by:	menu
passed:		WordStack *nouns, WordStack *verbs, WordStack *adjectives
returns:	none
calls:		menu

Choice 8
Creates a story by pop words from each stack and placing them into the appropriate spots in
the story template. Before doing so, will check each stack to make sure they are enough words
to put into the story.
************************************************************************************/
void makeStory(WordStack *nouns, WordStack *verbs, WordStack *adjectives) {

	int nounReq = 4;	//The requried amount of words from each stack needed to fit into the story
	int verbReq = 2;
	int adjReq = 2;

	if (nouns->stackSize() < nounReq) {				//Checks noun stack for enough elements
		cout << "Not enough nouns. Can't display story\n";
	}
	else if (verbs->stackSize() < verbReq) {		//Checks verb stack for enough elements
		cout << "Not enough verbs. Can't display story\n";
	}
	else if (adjectives->stackSize() < adjReq) {	//Checks adjective stack for enough elements
		cout << "Not enough adjectives. Can't display story\n";
	}
	else {											//If there are enough elements, pop the words into the story template and display it
		cout << "Here is the story: \n";
		cout << "The " << adjectives->pop() << " " << nouns->pop() << " " << verbs->pop() << " around the " << nouns->pop() << ". "
			<< "A " << adjectives->pop() << " " << nouns->pop() << " can be " << verbs->pop() << " in the " << nouns->pop() << ".";
	}
	cout << "\n\n";
	menu(nouns, verbs, adjectives);
}
/************************************************************************************
name:		exit
called by:	menu
passed:		WordStack *nouns, WordStack *verbs, WordStack *adjectives
returns:	none
calls:		none

Choice 9
Displays a goodbye messege, calls each stacks' deconstructor, then ends the program.
************************************************************************************/
void exit(WordStack *nouns, WordStack *verbs, WordStack *adjectives) {
	cout << "Thank you for playing!\n";
	nouns->~WordStack();
	verbs->~WordStack();
	adjectives->~WordStack();
}

/************************************************************************************
name:		inputValidation
called by:	callPushNoun, callPushVerb, callPushAdj
passed:		int type
returns:	none
calls:		menu

Asks for user input of the given type of word and then validates it for length. Then
returns the user input to the callling function.
************************************************************************************/
string inputValidation(int type){
	string wordType;
	string word;

	switch (type) {				//Changes display message depending on the given type value
		case 1:
			wordType = "noun";
			break;
		case 2:
			wordType = "verb";
			break;
		case 3:
			wordType = "adjective";
			break;
	}

	cout << "Enter a " << wordType << ": ";
	cin.ignore();
	getline(cin, word);
	while (word.length() < 1) {	//Error if input is empty 
		cout << "Error: input is blank. Please try again: ";
		getline(cin, word);
	}
	while (word.length() > 10) {					//Error if input is too long
		cout << "Error: " << word << " is more than 10 characters. Please try again: ";
		getline(cin, word);
	}
	while (blankCheck(word) == false) {					//Error if input has only whitespace characters
		cout << "Error: input has only whitespace characters. Please try again: ";
		getline(cin, word);
	}

	cout << '\n';
	return word;
}

/************************************************************************************
name:		blankCheck
called by:	inputValidation
passed:		string word
returns:	bool
calls:		none

Determines if the given string is only made of whitespace characters or not.
************************************************************************************/
bool blankCheck(string word) {
	int count = 0;
	for (int i = 0; i < word.length(); i++){		//Loop through the word string
		if (word[i] == ' ' || word[i] == '\t' || word[i] == '\n') {	//If a whitespace character is found, incrament count
			count++;
		}
	}

	if (count == word.length()) {
		return false;	//If only whitespace chracters were found, return false
	}
	else {
		return true;	//Otherwise return true
	}
}
