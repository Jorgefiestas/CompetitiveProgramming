#include <bits/stdc++.h>
using namespace std;
const int N = 305;
int t, n, k;
bool mat[N][N];

void solve() {
	cin >> n >> k;

	int rem = k;
	for (int i = 0; i < n; i++) {
		int tp = (rem + n - i - 1) / (n - i);
		rem -= tp;

		for (int j = 0; j < tp; j++) {
			mat[i][(i + j) % n] = 1;
		}
	}

	if (k % n) {
		cout << 2 << '\n';
	}
	else {
		cout << 0 << '\n';
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << mat[i][j];
		}
		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	while (t--) {
		memset(mat, 0, sizeof mat);
		solve();
	}

	return 0;
}
