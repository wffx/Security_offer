#pragma once
#include <list>
#include <queue>
#include <iostream>

using namespace std;

class graph {
public:
	graph(int vn);
	~graph();
	void addedge(int v, int w);
	bool topological_sort();

private:
	int v;			//the number of the point
	list<int>* g;	//the adjacent list to denote graph
	queue<int> qe;	//the queue to save the point of indegree 0
	int* indegree;
	int* flag;		// judge the point whether have accessed or not
};