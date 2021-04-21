#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int t, n, k, dp[N], f[N], cost[N][N];

int solve() {
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		cin >> f[i];
	}

	for (int l = 1; l <= n; l++) {
		map<int, int> cnt;

		cnt[f[l]] += 1;
		for (int r = l + 1; r <= n; r++) {
			cost[l][r] = cost[l][r - 1];
			cnt[f[r]] += 1;

			if (cnt[f[r]] == 2) {
				cost[l][r] += 2;
			}
			else if (cnt[f[r]] > 2) {
				cost[l][r] += 1;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		dp[i] = INT_MAX;
		for (int j = 1; j <= i; j++) {
			int c = cost[j][i];
			dp[i] = min(dp[i], dp[j - 1] + k + c);
		}
	}

	return dp[n];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cout << solve() << '\n';
	}

	return 0;
}
