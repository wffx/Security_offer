#include "heap.h"

void max_heapify(int a[], int i, const int size) {
	int l, r, lagest;
	int temp;

	l = 2 * i + 1;
	r = 2 * i + 2;
	if (l < size && a[l] > a[i]) {
		lagest = l;
	}
	else {
		lagest = i;
	}
	if (r < size && a[r] > a[lagest]) {
		lagest = r;
	}
	if (lagest != i) {
		temp = a[i];
		a[i] = a[lagest];
		a[lagest] = temp;

		max_heapify(a, lagest, size);
	}
}

void build_max_heap(int a[], const int size) {
	for (int i = size/2 - 1; i >= 0; --i) {
		max_heapify(a, i, size);
	}
}


void heap_sort(int a[], const int size) {
	int temp, len = size;

	build_max_heap(a, size);
	for (int i = size-1; i >= 0; --i) {
		temp = a[0];
		a[0] = a[i];
		a[i] = temp;

		len--;
		max_heapify(a, 0, len);
	}
}