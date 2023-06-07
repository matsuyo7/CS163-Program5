#include "graph.h"
using namespace std;

//Molina Nhoung, CS163, 6/6/23, Program 5
//The purpose of this file is the implement the graph class functions and create an adjacency list
//using a vector. Each index will be a vertex with a string and a head pointer to an edge linear linked list.
//Each node will have a pointer to the next vertex and a next pointer. Other programmers are able to views this file
//to understand what each functions does and know what to input/output to the client.

//constructor
graph::graph()
{}
//destructor
graph::~graph()
{}
//create a vertex and insert a task, return success/failure
int graph::insert_vertex(const string & to_add)
{}
//attach the two vertices if found in the list, return success/failure
int graph::insert_edge(const string & current, const string & attach)
{}
//find the task in the list. return success if found and return failure otherwise
int graph::find(const string & to_find)
{}
//display the adjacency list, return success/failure
int graph::display(const string & to_display)
{}
