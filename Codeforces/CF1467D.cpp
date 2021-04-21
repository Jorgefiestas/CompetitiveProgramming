#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 10;
const int mod = 1e9 + 7;
int n, k, q, a[N];
int dp[N][N], dp2[N][N], occ[N];

int add(int x, int y) {
	if (x + y >= mod) {
		return x + y - mod;
	}
	return x + y;
}

int sub(int x, int y) {
	if (x - y < 0) {
		return x - y + mod;
	}
	return x - y;
}

int mul(int x, int y) {
	return (long long) x * y % mod;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k >> q;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (int i = 1; i <= n; i++) {
		dp[0][i] = 1;
	}

	for (int j = 1; j <= k; j++) {
		for (int i = 1; i <= n; i++) {
			dp[j][i] = add(dp[j - 1][i - 1], dp[j - 1][i + 1]);
		}
	}

	for (int j = 0; j <= k; j++) {
		for (int i = 1; i <= n; i++) {
			dp2[j][i] = mul(dp[j][i], dp[k - j][i]);
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			occ[i] = add(occ[i], dp2[j][i]);
		}
		ans = add(ans, mul(occ[i], a[i]));
	}

	int i, x;
	for (int qi = 0; qi < q; qi++) {
		cin >> i >> x;

		ans = sub(ans, mul(occ[i], a[i]));
		ans = add(ans, mul(occ[i], x));
		a[i] = x;

		cout << ans << '\n';
	}

	return 0;
}
