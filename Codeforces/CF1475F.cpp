#include <bits/stdc++.h>
using namespace std;

bool solve() {
	int n;
	cin >> n;

	vector<vector<bool>> mat(n, vector<bool>(n));
	vector<int> c(n, -1);

	char ch;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> ch;
			mat[i][j] = ch == '1';
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> ch;
			mat[i][j] = mat[i][j] != (ch == '1');
		}
	}

	for (int i = 0; i < n; i++) {
		c[i] = mat[0][i] ? 1 : 0;
	}

	for (int i = 1; i < n; i++) {
		int r = mat[i][0] ? 1 - c[0] : c[0];
		for (int j = 1; j < n; j++) {		
			int nr = mat[i][j] ? 1 - c[j] : c[j];
			if (r != nr) return false;
		}
	}

	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		cout << (solve() ? "YES" : "NO") << '\n';
	}

	return 0;
}
