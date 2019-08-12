#include "choose.h"

void choose_sort(int a[], const int size) {
	int temp;
	for (int i = 0; i < size; ++i) {
		for (int j = i; j < size; ++j) {
			if (a[i] > a[j]) {
				temp = a[j];
				a[j] = a[i];
				a[i] = temp;
			}
		}
	}
}