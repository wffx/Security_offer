#include "DFS.h"

vector<int> vec;

void dfs(node n[], int start, int end)
{
	int index;
	if (start == end)	return;
	n[start].flag = 1;
	vec.push_back(start);

	for (unsigned int i = 0; i < n[start].vedge.size(); ++i) {
		index = n[start].vedge[i].endnum;
		if (index == end) {
			for (unsigned int j = 0; j < vec.size(); ++j) {
				cout << vec[j] << "->";
			}
			cout << end << endl;
			return;
		}
		if (n[index].flag == 0) {
			dfs(n, index, end);
		}
		vec.pop_back();
	}
}
