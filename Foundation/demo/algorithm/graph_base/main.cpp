#include <iostream>
#include "BFS.h"
#include "base.h"
#include "DFS.h"
using namespace std;

int main() {
	int vn, en;		// vn: the number of point set; en: the number of edge set;
	int start, end, len;
	int sta, des;

	cin >> vn >> en;
	node* v = new node[vn+1]();

	for (int i = 0; i < en; ++i) {
		cin >> start >> end >> len;
		if (start > vn) {
			cout << "error edge" << endl;
			exit(1);
		}
		v[start].addedge(start, end, len);
	}
	cin >> sta >> des;

	bfs(v, sta, des);

	for (int i = 1; i <= vn; ++i) {
		v[i].flag = 0;
	}

	dfs(v, sta, des);

	return 0;
}