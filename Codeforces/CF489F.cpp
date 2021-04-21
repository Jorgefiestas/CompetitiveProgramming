#include <bits/stdc++.h>
using namespace std;
const int N = 505;
int n, m, mod, cnt[N];
int C[N], dp[N], dp0[N];

int add(int x, int y) {
	if (x + y >= mod) {
		return x + y - mod;
	}
	return x + y;
}

int mul(int x, int y) {
	return (long long) x * y % mod;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> mod;

	for (int i = 2; i < N; i++) {
		long long lc = (long long) i * (i - 1) / 2;
		C[i] = (long long) lc % mod;
	}

	char aij;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> aij;
			if (aij == '1') {
				cnt[j] += 1;
			}
		}
	}

	int sj = 0;
	for (int j  = 0; j < n; j++) {
		if (cnt[j] == 0) {
			sj += 1;
		}
	}

	dp[0] = 1;
	for (int i = 1; i <= n - m; i++) {
		for (int j = 0; j <= i; j++) {
			int k = 2 * i - 2 * j;
			if (k + j > n) continue;

			dp0[j] = 0;
			if (j >= 2) {
				dp0[j] = add(dp0[j], mul(C[j], dp[j - 2]));
			}
			if (k >= 2) {
				dp0[j] = add(dp0[j], mul(C[k], dp[j]));
			}
			if (j >= 1 && k >= 1) {
				dp0[j] = add(dp0[j], mul(mul(j, k), dp[j - 1]));
			}
		}

		for (int j = 0; j <= n; j++) {
			dp[j] = dp0[j];
		}
	}

	cout << dp[sj] << endl;

	return 0;
}
