#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int t, n, mat[N][N];

void solve() {
	cin >> n;

	memset(mat, 0, sizeof mat);

	for (int i = 0; i < n; i++) {
		int skip = (n & 1) ? INT_MAX : n - i - 1;
		int sv = (i & 1) ? 1 : -1;

		for (int j = 0; j < n; j++) {
			int nj = j % n;
			if (nj == i || nj == skip) continue;

			mat[i][nj] = sv;
			sv *= -1;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			cout << mat[i][j] << ' ';
		}
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
