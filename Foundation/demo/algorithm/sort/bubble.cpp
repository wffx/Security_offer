#include "bubble.h"

void bubble_sort(int a[],const int size) {
	int temp;
	for (int i = 0; i < size; ++i) {
		for (int j = 1; j < size - i; ++j) {
			if (a[j - 1] > a[j]) {
				temp = a[j - 1];
				a[j - 1] = a[j];
				a[j] = temp;
			}
		}
	}
}