#include <iostream>
#include <cctype>
#include <vector>
#include <string>
using namespace std;

//Molina Nhoung, CS163, 6/6/23, Program 5
//The purpose of this file is to organize the graph class where it will be a linear linked
//list of vertices while each will have head ponters to an edge list. This file allows other
//programmers to efficiently output and recieve accurate information from the client and know
//what functions needs what.

const int SIZE{200};

struct vertex
{
	string task;
	struct node * head;
};

struct node
{
	vertex * adjacent;
	node * next;
};

class graph
{
	public:
		graph(int size = 100);	//constructor
		~graph();	//destructor
		int insert_vertex(const string & to_add);	//create a vertex and insert a task, return success/failure
		int insert_edge(const string & current_vertex, const string & to_attach);	//attach the two vertices if found in the list, return success/failure
		int find(const string & to_find);	//find the task in the list. return success if found and return failure otherwise
		int display(const string & to_display);	//display the adjacency list, return success/failure
	private:
		vector<vertex> adjacency_list;
		int list_size;
};
