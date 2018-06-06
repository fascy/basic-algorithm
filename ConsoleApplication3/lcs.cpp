#include <iostream>
using namespace std;

#define M 8
#define N 10

void lcs_length(char x[], char y[], char c[][N+1], char b[][N+1]) {
	for (int i = 1; i <= M; i++) {
		c[i][0] = 0;
	}
	for (int j = 1; j <= N; j++) {
		c[0][j] = 0;
	}
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			if (x[i] == y[j]) {
				c[i][j] = c[i - 1][j - 1] + 1; b[i][j] = 'x';
			}
			else if (c[i - 1][j] > c[i][j - 1]) {
				c[i][j] = c[i - 1][j]; b[i][j] = 'u';
			}
			else {
				c[i][j] = c[i][j-1]; b[i][j] = 'l';
			}
		}
	}
}

void p_l(char b[][N + 1], char x[], int i, int j) {
	if (i == 0 || j == 0)return;
	if (b[i][j] == 'x') {
		p_l(b, x, i - 1, j - 1);
		cout << x[i];
	}
	else if (b[i][j] == 'u') {
		p_l(b, x, i - 1, j);
	}
	else
		p_l(b, x, i, j - 1);

}

int main() {
	char x[9]; char y[11];
	char b[9][11]; char c[9][11];
	cout << "please input x:";
	for (int i = 1; i <= M; i++) {
		cin >> x[i];
	}
	cout << "please input y:";
	for (int i = 1; i <= N; i++) {
		cin >> y[i];
	}
	lcs_length(x, y, c, b);
	p_l(b, x, M, N);
}