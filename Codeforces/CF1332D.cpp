#include <bits/stdc++.h>
using namespace std;
const int N = 505;
int k, mat[4][4];

int main() {
	cin >> k;

	int bad = 1;
	while (bad <= k) {
		bad <<= 1;
	}

	int neutral = bad | k;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			mat[i][j] = bad;
		}
	}
	for (int i = 1; i < 3; i++) {
		mat[0][i] = k;
		mat[i][2] = k;
	}

	mat[0][0] = neutral;
	mat[1][2] = neutral;

	cout << "3 3\n";
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << mat[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}
