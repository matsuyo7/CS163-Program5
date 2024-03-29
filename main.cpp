#include "table.h"
//using namespace std;

//Molina Nhoung, CS163, 6/9/23, Program 5
//The purpose of this file is to test out the ADT with this client program.
//This will be testing out the graph ADT where it will be a vector with each index having head pointers to
//linear linked lists. The client program will output messages to the client and take in information from them
//to send to the ADT who will send back errors that the client program with interpret.

//Prototypes
int menu();
void add_task(string & to_add, graph & a_task);
void add_connect(string & current, string & to_attach, graph & a_task);
void display_connect(string & connect, graph & a_task);

int main()
{
	//Variables
	graph a_task;
	int option {0};
	string to_add;
	string current;
	string to_attach;
	string connect;

	do
	{
		option = menu();
		if (option == 1)
		{
			add_task(to_add, a_task);
		}
		if (option == 2)
		{
			add_connect(current, to_attach, a_task);
		}
		if (option == 3)
		{
			display_connect(connect, a_task);
		}
	} while (option != 4);

	return 0;
}

//Functions
int menu()
{
	int pick = 0;
	do
	{
		cout << "\n***TASK MENU***"
			"\n1. Insert a task"
			"\n2. Insert a connection betweek tasks"
			"\n3. Display a connection"
			"\n4. Quit"
			"\nPick an option: ";
		cin >> pick;
		cin.ignore(SIZE, '\n');
		if (pick < 1 || pick > 4)
			cout << "\nTry again" << endl;
	} while (pick < 1 || pick > 4);
	return pick;
}
//Insert a task into the graph
void add_task(string & to_add, graph & a_task)
{
	cout << "\nTask to insert: ";
	getline(cin, to_add);
	if (!a_task.insert_vertex(to_add))
		cout << "\nUnable to insert" << endl;
}
//Insert a connection from one task to another
void add_connect(string & current, string & to_attach, graph & a_task)
{
	cout << "\nWhat's the starting task: ";
	getline(cin, current);
	cout << "\nWhat's the next task to connect: ";
	getline(cin, to_attach);
	if (!a_task.insert_edge(current, to_attach))
		cout << "\nUnable to connect" << endl;
}
//Display the adjacency list
void display_connect(string & connect, graph & a_task)
{
	cout << "\nWhat tasks and its connected task to display: ";
	getline(cin, connect);
	if (!a_task.display(connect))
		cout << "\nCouldn't display" << endl;
}
