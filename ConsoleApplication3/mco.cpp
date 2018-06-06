#include <iostream>
#define M 7
using namespace std;

void matrix_chain_order(int *p, int m[][M], int s[][M],int n) {
	for (int i = 1; i <= n; i++) {
		m[i][i] = 0;
	}
	for (int l = 2; l <= n; l++) {
		for (int i = 1; i <= n - l + 1; i++) {
			int j = i + l - 1;
			m[i][j] = INT_MAX;
			for (int k = i; k <= j - 1; k++) {
				int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (q < m[i][j]) {
					m[i][j] = q;
					s[i][j] = k;
				}
			}
		}
	}
}

void p_o_p(int s[][M], int i, int j) {
	if (i == j) {
		cout << "A" << i;
	}
	else {
		cout << "(";
		p_o_p(s, i, s[i][j]);
		p_o_p(s, s[i][j] + 1, j);
		cout << ")";
	}
}

int main() {
	int p[M] = { 30,35,15,5,10,20,25 };
	int m[M][M] ;
	int s[M][M] ;
	matrix_chain_order(p, m, s, M-1);
	cout << m[1][6];
	p_o_p(s, 1, 6);
}