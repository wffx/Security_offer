#pragma once
#include <cstddef>
#include <iostream>
#include <vector>
using namespace std;

struct edge {
	int endnum;
	int len;
	edge();
	edge(int e, int l);
};

struct  node
{
	int mynum;
	// out destination and edge length
	vector<edge> vedge;
	int flag = 0;

	node(int n);
	node();
	void addedge(int endum, int len);
	void addedge(int my, int end, int len);
	void print();
};

