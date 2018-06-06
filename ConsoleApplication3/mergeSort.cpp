#include <iostream>
#define N 10
using namespace std;

void merge(int a[], int p, int q, int r) {
	//input a[i...j]
	//output sorted a[i...j]
	int n1 = q - p + 1;
	int n2 = r - q;
	int	L[10] = { 0 };
	for (int i = p; i <=q ; i++) {
		L[i-p] = a[i];
	}
	int R[10] = { 0 };
	for (int i =q+1; i <= r; i++) {
		R[i - q - 1] = a[i];
	}
	L[n1] = 100000;
	R[n2] = 100000;
	int i = 0; int j = 0;
	for (int k = p; k <= r; k++) {
		if (L[i] <= R[j]) {
			a[k] = L[i];
			i++;
		}
		else {
			a[k] = R[j];
			j++;
		}
	}
}

void mergeSort(int a[], int  p, int r) {
	if (p < r) {
		int q = (p + r) / 2;
		mergeSort(a, p, q);
		mergeSort(a, q + 1, r);
		merge(a, p, q, r);
	}
}
int main() {
	int a[N] = { 1,4,2,7,3,8,4,0,12,6 };
	mergeSort(a,0,9);
	for (int i = 0; i < N; i++) {
		cout << a[i] << " ";
	}
}