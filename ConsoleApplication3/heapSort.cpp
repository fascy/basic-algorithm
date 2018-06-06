#include <iostream>
using namespace std;


void max_heapify(int a[], int i,int hsize) {
	int l = 2 * i + 1; int r = 2 * i + 2;
	int max = 0;
	if (l<=(hsize) && a[l]>a[i]) {
		max = l;
	}
	else
	{
		max = i;
	}
	if (r<=(hsize) && a[r]>a[max]) {
		max = r;
	}
	if (max != i) {
		int temp = 0;
		temp = a[i]; a[i] = a[max]; a[max] = temp;
		max_heapify(a, max, hsize);
	}
	
}

void build_max_heap(int a[],int size) {
	for (int i = (size - 1) / 2; i >= 0; i--) {
		max_heapify(a, i,size-1);
	}
}

void heap_sort(int a[],int size) {
	build_max_heap(a,size);
	int hsize = size - 1;
	for (int i = (size - 1); i > 0; i--) {
		int temp = 0;
		temp = a[0]; 
		a[0] = a[i]; 
		a[i] = temp;
		hsize = hsize - 1;
		max_heapify(a, 0, hsize);
	}
}

int main() {
	int a[10] = { 1,4,2,7,3,8,4,0,12,6 };
	heap_sort(a,10);
	for (int i = 0; i < 10; i++) {
		cout << a[i] << " ";
	}
}