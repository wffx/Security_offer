#include "quick.h"

void swap(int& a, int& b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void quick_sort(int a[],const int l, const int r) {
	if (l >= r) return;
	
	//cout << l << "--" << r << endl;
	int current =a[l], i = l + 1, j = r;

	while (i < j) {
		while (i < r && a[i] < current) i++;
		while (j > l && a[j] >= current) j--;
		
		if (i < j && a[i] >= current && a[j] < current) {
			swap(a[i], a[j]);
			i++; j--;
		}
	}
	if (a[j] > current) {
		j--;
	}
	
	swap(a[l], a[j]);

	/*for (int i = 0; i < 20; ++i) {
		cout << a[i] << " ";
	}
	cout << "\n" << j << "  " << a[j] << endl;*/
	quick_sort(a, l, j -1);
	quick_sort(a, j + 1, r);
}