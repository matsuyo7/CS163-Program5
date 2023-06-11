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
	adjacency_list.resize(size);
	for (int i = 0; i < size; ++i)
	{
		adjacency_list[i].head = nullptr;
	}
	list_size = size;
}
//destructor
graph::~graph()
{
	node * current = nullptr;
	node * previous = nullptr;
	for (int i = 0; i < list_size; ++i)
	{
		current = adjacency_list[i].head;
		while (current)
		{
			previous = current;
			current = current->next;
			delete previous;
		}
		adjacency_list[i].head = nullptr;
	}
}
//create a vertex and insert a task, return success/failure
int graph::insert_vertex(const string & to_add)
{
	bool found = false;
	int i = 0;
	while (i < list_size && !found)
	{
		if (adjacency_list[i].task.empty())
		{
			adjacency_list[i].task = to_add;
			//cout << "\nTask: " << adjacency_list[i].task;
			found = true;
		}
		++i;
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
{
	int current = find(to_display);
	if (current == -1 || !adjacency_list[current].head)
		return 0;
	node * temp = adjacency_list[current].head;
	while (temp)
	{
		cout << "\nTask: " << temp->adjacent->task;
		temp = temp->next;
	}
	return 1;
}
