#include <bits/stdc++.h>
using namespace std;
const int r = 7;
const int c = 8;
int t, mat[r][c];
bool occ[r][c];

bool vcheck(int i, int j, int n1, int n2) {
	bool op1 = mat[i][j] == n1 && mat[i + 1][j] == n2;
	bool op2 = mat[i][j] == n2 && mat[i + 1][j] == n1;
	bool free = !occ[i][j] && !occ[i + 1][j];
	return free && (op1 || op2);
}

bool hcheck(int i, int j, int n1, int n2) {
	bool op1 = mat[i][j] == n1 && mat[i][j + 1] == n2;
	bool op2 = mat[i][j] == n2 && mat[i][j + 1] == n1;
	bool free = !occ[i][j] && !occ[i][j + 1];
	return free && (op1 || op2);
}

int bt(int n1, int n2) {
	if (n1 == 6 && n2 == 7) {
		return 1;
	}

	if (n2 == 7) {
		n1 += 1;
		n2 = n1;
	}

	int ways = 0;
	for (int i = 0; i < r - 1; i++) {
		for (int j = 0; j < c; j++) {
			if (!vcheck(i, j, n1, n2)) {
				continue;
			}

			occ[i][j] = true;
			occ[i + 1][j] = true;

			ways += bt(n1, n2 + 1);

			occ[i][j] = false;
			occ[i + 1][j] = false;
		}
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c - 1; j++) {
			if (!hcheck(i, j, n1, n2)) {
				continue;
			}

			occ[i][j] = true;
			occ[i][j + 1] = true;

			ways += bt(n1, n2 + 1);

			occ[i][j] = false;
			occ[i][j + 1] = false;
		}
	}

	return ways;
}

int solve() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> mat[i][j];
		}
	}

	return bt(0, 0);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	while (t--) {
		cout << solve() << '\n';
	}

	return 0;
}
