#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include "bubble.h"
#include "choose.h"
#include "insert.h"
#include "heap.h"
#include "merge.h"
#include "quick.h"

#define SIZE_SORT 30

using namespace std;

void print(const int a[], const int size) {
	for (int i = 0; i < size; ++i) {
		cout << a[i] << " ";
	}
	cout << endl;
}

void copy(int a[], int b[], const int size) {
	for (int i = 0; i < size; ++i) {
		b[i] = a[i];
	}
}


int main() {
	int a[SIZE_SORT], b[SIZE_SORT];

	srand(time(NULL));

	cout << "Original sort:" << endl;
	for (int i = 0; i < SIZE_SORT; ++i) {
		a[i] = rand() % 100;
		cout << a[i] << " ";
	}
	cout << endl;
	copy(a, b, SIZE_SORT);

	cout << "Bubble sort:" << endl;
	bubble_sort(a, SIZE_SORT);
	print(a, SIZE_SORT);
	copy(b, a, SIZE_SORT);

	cout << "Choose sort:" << endl;
	choose_sort(a, SIZE_SORT);
	print(a, SIZE_SORT);
	copy(b, a, SIZE_SORT);

	cout << "Insert sort:" << endl;
	insert_sort(a, SIZE_SORT);
	print(a, SIZE_SORT);
	copy(b, a, SIZE_SORT);

	cout << "Heap sort:" << endl;
	heap_sort(a, SIZE_SORT);
	print(a, SIZE_SORT);
	copy(b, a, SIZE_SORT);

	//the range from [0, SIZE_SORT-1]
	cout << "Merge sort:" << endl;
	merge_sort(a, 0, SIZE_SORT - 1);
	print(a, SIZE_SORT);
	copy(b, a, SIZE_SORT);

	// the range from [0, SIZE_SORT-1]
	cout << "Quick sort:" << endl;
	quick_sort(a, 0, SIZE_SORT - 1);
	print(a, SIZE_SORT);
	copy(b, a, SIZE_SORT);

	return 0;
}