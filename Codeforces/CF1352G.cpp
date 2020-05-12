#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int t, n, a[N];
const int b[4][7] = {{2, 4, 1, 3},
					{2, 4, 1, 3, 5},
					{2, 4, 6, 3, 1, 5},
					{2, 4, 6, 3, 1, 5, 7}};

void solve() {
	cin >> n;

	if (n == 1) {
		cout << 1 << '\n';
		return;
	}
	if (n <= 3) {
		cout << -1 << '\n';
		return;
	}

	int d = 0;
	while (n >= 8) {
		for (int i = 0; i < 4; i++) {
			cout << b[0][i] + d<< ' ';
		}
		n -= 4;
		d += 4;
	}

	for (int i = 0; i < n; i++) {
		cout << b[n - 4][i] + d << ' ';
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
