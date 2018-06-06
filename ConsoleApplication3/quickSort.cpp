#include <iostream>

using namespace std;

int partition(int a[], int p, int r) {
	int x = a[r];
	int i = p - 1;
	for (int j = p; j < r; j++) {
		if (a[j] <= x) {
			i++;
			int temp = 0;
			temp = a[i]; a[i] = a[j]; a[j] = temp;
		}
	}
	int t2 = 0;
	t2 = a[i + 1]; a[i + 1] = a[r]; a[r] = t2;
	return i + 1;
}

void quicksort(int a[], int p, int r) {
	if (p < r) {
		int q = partition(a, p, r);
		quicksort(a, p, q - 1);
		quicksort(a, q + 1, r);
	}
}

int main() {
	int a[10] = { 1,0,9,4,0,2,5,2,4,10 };
	quicksort(a, 0, 9);
	for (int i = 0; i < 10; i++) {
		cout << a[i] << "  ";
	}
}