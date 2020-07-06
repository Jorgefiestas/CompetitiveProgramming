#include <bits/stdc++.h>
using namespace std;
using ld = long double;
const int B = 18;
const int N = (1 << B);
int n;
ld a[B][B], dp[N];

bool comp(int x, int y) {
	return __builtin_popcount(x) > __builtin_popcount(y);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	int m = (1 << n);
	vector<int> bitmasks;
	for (int i = 1; i < m; i++) {
		if (__builtin_popcount(i) == 1) continue;
		bitmasks.emplace_back(i);
	}

	sort(bitmasks.begin(), bitmasks.end(), comp);

	dp[m - 1] = 1;
	for (int bm : bitmasks) {
		int size = __builtin_popcount(bm);
		ld ppair = (ld) 1 / (size * (size - 1) / 2);

		for (int i = 0; i < n; i++) {
			if ((bm & (1 << i)) == 0) continue;
			for (int j = 0; j < n; j++) {
				if (i == j || (bm & (1 << j)) == 0) continue;
				int nbm = bm ^ (1 << j);
				dp[nbm] += dp[bm] * ppair * a[i][j];
			}
		}
	}

	cout << setprecision(9) << fixed;
	for (int i = 0; i < n; i++) {
		cout << dp[1 << i] << ' ';
	}
	cout << '\n';

	return 0;
}
