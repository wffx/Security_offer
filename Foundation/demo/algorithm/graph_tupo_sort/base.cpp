#include "base.h"

graph::graph(int vn)
{
	this->v = vn;
	this->g = new list<int>[v+1];

	indegree = new int[v+1];
	flag = new int[v+1];
	for (int i = 0; i <= v; ++i) {
		indegree[i] = 0;
		flag[i] = 0;
	}
}

graph::~graph()
{
	delete[] indegree;
	delete[] g;
	delete[] flag;
}

void graph::addedge(int v, int w)
{
	g[v].push_back(w);
	indegree[w]++;
}

bool graph::topological_sort()
{
	int p;
	list<int>::iterator iter;

	for (int i = 1; i <= v; ++i) {
		if (indegree[i] == 0) {
			qe.push(i);
		}
	}

	while (!qe.empty()) {
		p = qe.front();
		qe.pop();
		flag[p] = 1;

		cout << p << "  ";
		for (iter = g[p].begin(); iter != g[p].end(); ++iter) {
			indegree[*iter]--;
			if (indegree[*iter] == 0 && flag[*iter] == 0) {
				qe.push(*iter);
			}
		}
	}
	cout << endl;

	for (int i = 1; i <= v; ++i) {
		if (flag[i] == 0) {
			return false;
		}
	}

	return true;
}
