#include <iostream>

using namespace std;

int Greedy_Activity_selector(int S[], int F[], int A[], int size) {
	A[0] = 0;
	int pink = 0;
	pink++;
	int j = 0;
	for (int i = 0; i < size; i++) {
		if (S[i] >= F[j]) {
			A[pink] = i;
			j = i;
			pink++;
		}
	}
	return pink;
}

int main() {
	int S[10] = { 8,8,11,10,14,12,16,17,18,13 };
	int F[10] = { 9,10,12,13,15,15,18,19,19,20 };
	int A[10];
	int n = Greedy_Activity_selector(S, F, A, 10);
	int i = 0;
	while (i < n-1) {
		cout << i << " " << A[i] << ":" << S[A[i]] << "-->" << F[A[i]] << endl;
		i++;
	}
}