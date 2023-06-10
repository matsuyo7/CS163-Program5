#include "table.h"
//using namespace std;

//Molina Nhoung, CS163, 6/9/23, Program 5
//The purpose of this file is to test out the ADT with this client program.
//This will be testing out the graph ADT where it will be a vector with each index having head pointers to
//linear linked lists. The client program will output messages to the client and take in information from them
//to send to the ADT who will send back errors that the client program with interpret.

//Prototypes
int menu();

int main()
{
	//Variables
	int option {0};
	do
	{
		option = menu();
		if (option == 1)
		{}
		if (option == 2)
		{}
		if (option == 3)
		{}
	} while (option != 4);

	return 0;
}

//Functions
int menu()
{
	char pick = 0;
	cout << "\n***TASK MENU***"
		"\n1. Insert a task"
		"\n2. Insert a connection betweek tasks"
		"\n3. Display a connection"
		"\n4. Quit"
		"\nPick an option: ";
	cin >> pick;
	cin.ignore(SIZE, '\n');
	return pick;
}

	
