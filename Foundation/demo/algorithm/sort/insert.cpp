#include "insert.h"

void insert_sort(int a[], const int size) {
	int current;

	for (int i = 0; i < size-1; ++i) {
		current = a[i + 1];
		int j = i;
		while (j >= 0 && current < a[j]) {
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = current;
	}
}