#pragma once
#include "base.h"
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct qnode {
	int pnum;				// the number of the node
	vector<int> road;		// the road from start node to this node
};

void bfs(node n[], int start, int end);