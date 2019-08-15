#include "base.h"
#include <iostream>

using namespace std;

int main() {
	int v;

	graph gai(6);
	gai.addedge(1, 2);
	gai.addedge(1, 3);
	gai.addedge(2, 5);
	gai.addedge(2, 6);
	gai.addedge(3, 4);
	gai.addedge(4, 5);
	gai.addedge(4, 6);

	if (!gai.topological_sort()) {
		cout << "the gaphy have loop" << endl;
	}

	return 0;
}