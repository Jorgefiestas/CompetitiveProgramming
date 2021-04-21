#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 100;
int t, n, a[N], b[N];
bool occ[N];

int gcd(int x, int y) {
	if (y == 0) {
		return x;
	}
	return gcd(y, x % y);
}

void solve() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	int g = 0;
	for (int i = 1; i <= n; i++) {

		int mxj = 0;
		int mxg = 0;

		for (int j = 1; j <= n; j++) {
			if (occ[j]) continue;
			int cg = gcd(g, a[j]);
			if (cg > mxg) {
				mxg = cg;
				mxj = j;
			}
		}

		b[i] = a[mxj];

		g = mxg;
		occ[mxj] = true;
	}

	for (int i = 1; i <= n; i++) {
		cout << b[i] << ' ';
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		memset(occ, 0, sizeof occ);
		solve();
	}

	return 0;
}
