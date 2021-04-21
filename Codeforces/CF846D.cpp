#include <bits/stdc++.h>
using namespace std;
const int N = 502;
int n, m, k, q;
int dp[N][N], dp1[N][N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	memset(dp1, -1, sizeof dp1);

	cin >> n >> m >> k >> q;

	int xi, yi, ti;
	for (int i = 0; i < q; i++) {
		cin >> xi >> yi >> ti;
		dp1[xi][yi] = ti;
	}

	for (int sz = 2; sz <= k; sz++) {
		memset(dp, -1, sizeof dp);

		for (int i = sz; i <= n; i++) {
			for (int j = sz; j <= m; j++) {
				int v1 = dp1[i - 1][j];
				int v2 = dp1[i][j - 1];
				int v3 = dp1[i - 1][j - 1];
				int v4 = dp1[i][j];

				if (v1 < 0 || v2 < 0 || v3 < 0 || v4 < 0) {
					continue;
				}

				dp[i][j] = max({v1, v2, v3, v4});
			}
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				dp1[i][j] = dp[i][j];
			}
		}
	}

	int ans = INT_MAX;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (dp1[i][j] < 0) continue;
			ans = min(ans, dp1[i][j]);
		}
	}
	ans = (ans == INT_MAX) ? -1 : ans;

	cout << ans << '\n';

	return 0;
}
