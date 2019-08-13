#include "BFS.h"

void bfs(node n[], int start, int end)
{
	// mv denotes the node num, the road from start to this node
	qnode mv;
	queue<qnode> qe;		//FIFO queue
	int index;
	bool yn = false;

	// initialization
	mv.pnum = start;
	mv.road.push_back(start);
	n[start].flag = 1;
	qe.push(mv);

	while (!qe.empty()) {
		mv = qe.front();
		qe.pop();
		n[mv.pnum].flag = 1;
		
		for (unsigned int i = 0; i < n[mv.pnum].vedge.size(); ++i) {
			index = n[mv.pnum].vedge[i].endnum;
			if (index == end) {
				mv.road.push_back(index);
				yn = true;
				break;
			}
			if (n[index].flag == 0) {
				mv.pnum = index;
				mv.road.push_back(index);
				qe.push(mv);
			}
		}

		if (yn == true) break;
	}

	for (unsigned int i = 0; i < mv.road.size()-1; ++i) {
		cout << mv.road[i] << "->";
	}
	cout << mv.road.back() << endl;

	return;

}
