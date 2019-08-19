#include "redblacktree.h"
#include <iostream>

int main() {
	int size, x, k;
	Tree *tree = new Tree();

	std::cin >> size;
	for (int i = 0; i < size; ++i) {
		std::cin >> x;
		tree->Insert(x);
	}

	std::cout << "key\t" << "color\t" << "parent.key\t" << "left.key\t"<< "child.key\n";
	tree->Print();

	std::cin >> k;
	tree->Delete(k);
	tree->Print();

	return 0;
}