#include "merge.h"

void merge(int a[], int l1, int r1, int l2, int r2) {
	int* buffer;

	//cout << l1 << "-" << r1 << "-" << l2 << "-" << r2 << endl;
	
	buffer = (int*)malloc(sizeof(int)*(r2 - l1 + 1));
	if (buffer == NULL) exit(1);

	for (int i = l1, j = l2, index = 0; index < r2 - l1 + 1;) {
		if (a[i] <= a[j] && i <= r1) {
			buffer[index] = a[i];
			++i;
			++index;
		}else if(a[j] < a[i] && j <= r2) {
			buffer[index] = a[j];
			++j;
			++index;
		}

		while (i > r1 && j <= r2) {
			buffer[index] = a[j];
			++j;
			++index;
		}
		while (j > r2 && i <= r1) {
			buffer[index] = a[i];
			++i;
			++index;
		}
	}

	for (int i = 0, j = l1; i < r2 - l1 + 1; ++i, ++j) {
		a[j] = buffer[i];
	}

	free(buffer);
}

// 0 -> size-1
void merge_sort(int a[], int l, int r) {
	if (l == r) return;

	merge_sort(a, l, (l + r) / 2);
	merge_sort(a, (l + r) / 2 + 1, r);

	return merge(a, l, (l + r) / 2, (l + r) / 2 + 1, r);
}