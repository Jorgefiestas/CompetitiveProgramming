#include <bits/stdc++.h>
using namespace std;
const int N = 55;
int t, n, m, a, b;
bool mat[N][N];

bool solve() {
	if (n * a != m * b) {
		return false;
	}

	for (int i = 0; i < n; i++) {
		int pend = a;
		for (int nj = 0; nj < a; nj++) {
			int j = (nj + a * i) % m;
			mat[i][j] = 1;
		}
	}

	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		memset(mat, 0, sizeof mat);

		cin >> n >> m >> a >> b;

		if (solve()) {
			cout << "YES\n";
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					cout << mat[i][j];
				}
				cout << '\n';
			}
		}
		else {
			cout << "NO\n";
		}
	}

	return 0;
}
