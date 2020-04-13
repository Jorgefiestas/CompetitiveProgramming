#include <bits/stdc++.h>
using namespace std;
const int N = 5001;
int n, k, a[N];
int dp[N][N], cost[N][N];

void compute(int l, int r, int optl, int optr, int idx) {
	if (l > r) {
		return;
	}

	int m = (l + r) / 2;
	int opt = -1;
	dp[idx][m] = INT_MAX;

	for (int i = optl; i<= min(m, optr); i++) {
		int temp = cost[i][m] + dp[idx - 1][i - 1];
		if (temp < dp[idx][m]) {
			dp[idx][m] = temp;
			opt = i;
		}
	}

	compute(l, m - 1, optl, opt, idx);
	compute(m + 1, r, opt, optr, idx);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];

		for (int j = i - 1; j > 0; j--) {
			cost[j][i] = cost[j + 1][i];
			if (a[j] > a[i]) {
				cost[j][i]++;
			}
		}
	}

	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j <= n; j++) {
			cost[i][j] += cost[i][j - 1];
		}
	}

	for (int i = 1; i <= n; i++) {
		dp[1][i] = cost[1][i];
	}

	for (int i = 2; i <= k; i++) {
		compute(i, n, i, n, i);
	}

	cout << dp[k][n] << '\n';

	return 0;
}
