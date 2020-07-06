#include <bits/stdc++.h>
using namespace std;
const int B = 20;
const int N = (1 << B);
int n, m;
long long dp[N][B];
bool edg[B][B];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		a--, b--;
		edg[a][b] = true;
		edg[b][a] = true;
		dp[(1 << a) | (1 << b)][a] = 1;
		dp[(1 << a) | (1 << b)][b] = 1;
	}

	long long ans = 0;
	for (int mask = 1; mask < (1 << n); mask++) {
		if (__builtin_popcount(mask) <= 2) continue;
		for (int v = 0; v < n; v++) {
			if (!(mask & (1 << v))) continue;

			int u = 31 - __builtin_clz(mask);
			int smask = mask ^ (1 << v);
			for (int i = 0; i < n; i++) {
				if (i == u || !edg[i][v]) continue;
				dp[mask][v] += dp[smask][i];
			}

			if (edg[u][v]) {
				ans += dp[mask][v];
			}
		}
	}

	cout << ans / 2LL << '\n';
	return 0;
}
