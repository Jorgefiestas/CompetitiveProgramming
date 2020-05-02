#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
int n, k, a[N];
long long dp[N][N], cost[N][N];

void compute(int idx, int l, int r, int optl, int optr) {
	if (l > r) {
		return;
	}

	int m = (l + r) / 2;
	int opt = -1;
	dp[idx][m] = LLONG_MAX;

	for (int i = optl; i <= min(m, optr); i++) {
		long long temp = cost[i][m] + dp[idx - 1][i - 1];
		if (temp < dp[idx][m]) {
			dp[idx][m] = temp;
			opt = i;
		}
	}

	compute(idx, l, m - 1, optl, opt);
	compute(idx, m + 1, r, opt, optr);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int b = 0; b < 31; b++) {
			long long cnt0 = 0;
			long long cnt1 = 0;

			for (int j = i; j <= n; j++) {
				if (a[j] & (1 << b)) {
					cnt1++;
				}
				else {
					cnt0++;
				}

				cost[i][j] += cnt0 * cnt1 * 1LL * (1LL << b);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		dp[1][i] = cost[1][i];
	}

	for (int i = 2; i <= k + 1; i++) {
		compute(i, i, n, i, n);
	}

	cout << dp[k + 1][n] << '\n';

	return 0;
}
