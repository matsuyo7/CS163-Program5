#include "table.h"
//using namespace std;

//Molina Nhoung, CS163, 6/6/23, Program 5
//The purpose of this file is the implement the graph class functions and create an adjacency list
//using a vector. Each index will be a vertex with a string and a head pointer to an edge linear linked list.
//Each node will have a pointer to the next vertex and a next pointer. Other programmers are able to views this file
//to understand what each functions does and know what to input/output to the client.

//constructor
graph::graph(int size)
{
/*	for (int i = 0; i < size; ++i)
	{
		adjacency_list[i].head = nullptr;
	}
	list_size = size;*/
}
//destructor
graph::~graph()
{}
//create a vertex and insert a task, return success/failure
int graph::insert_vertex(const string & to_add)
{
	bool found = false;
	for (int i = 0; i < list_size; ++i)
	{
		if (adjacency_list[i].task.empty())
		{
			adjacency_list[i].task = to_add;
			i = list_size;
			found = true;
		}
	}
	return found;
}
//attach the two vertices if found in the list, return success/failure
int graph::insert_edge(const string & current_vertex, const string & to_attach)
{
	int current = 0;
	int attach = 0;
	node * hold = nullptr;
	current = find(current_vertex);
	attach = find(to_attach);
	if (current == -1 || attach == -1)
		return 0;
	hold = adjacency_list[current].head;
	adjacency_list[current].head = new node;
	adjacency_list[current].head->adjacent = & adjacency_list[attach];
	adjacency_list[current].head->next = hold;
	return 1;
}
//find the task in the list. return success if found and return failure otherwise
int graph::find(const string & to_find)
{
	int match = -1;
	for (int i = 0; i < list_size; ++i)
	{
		if (adjacency_list[i].task == to_find)
		{
			match = i;
			i = list_size;
		}
	}
	return match;
}
//display the adjacency list, return success/failure
int graph::display(const string & to_display)
{}
