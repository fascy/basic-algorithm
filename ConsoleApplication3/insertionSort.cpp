#include<iostream>
#define N 10
using namespace std;

int *insertion(int *a) {
	int key = -1;
	for (int j = 1; j < N-1; j++) {
		key = a[j];
		int i = j - 1;
		while (i >= 0 && a[i] > key) {
			a[i + 1] = a[i];
			i--;
		}
		a[i + 1] = key;
	}
	return a;
}

int main() {
	int a[N] = { 1,4,2,7,3,8,4,0,12,6 };
	int *b=insertion(a);
	for (int i = 0; i < N; i++) {
		cout << b[i] << " ";
	}
}