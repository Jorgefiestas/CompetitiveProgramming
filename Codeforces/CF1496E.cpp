#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;

	vector<vector<char>> mat(n, vector<char>(m, 0));

	int cnt = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mat[i][j];
		}
	}

	int sx = n % 3 == 1 ? 0 : 1;
	int sy = n % 3 == 1 ? 2 : 3;

	for (int i = sx; i < n; i += 3) {
		for (int j = 0; j < m; j++) {
			mat[i][j] = 'X';
		}
	}

	for (int i = sy; i < n; i += 3) {
		bool done = false;
		for (int j = 0; j < m; j++) {
			if (mat[i][j] == 'X' || mat[i - 1][j] == 'X') {
				mat[i - 1][j] = 'X';
				mat[i][j] = 'X';
				done = true;
				break;
			}
		}

		if (!done) {
			mat[i - 1][0] = 'X';
			mat[i][0] = 'X';
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << mat[i][j];
		}
		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}
