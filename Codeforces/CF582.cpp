#include <bits/stdc++.h>
using namespace std;
const int X = 305;
const int N = 105;
int n, t, a[N], dp[X], f[X];

int calc(int l, int r, int rep) {
	memset(dp, 0, sizeof dp);

	for (int i = 0; i < n * rep; i++) {
		if (a[i % n] < l || a[i % n] > r) continue;
		int x = a[i % n];
		for (int j = x; j >= l; j--) {
			dp[x] = max(dp[x], dp[j] + 1);
		}
	}

	return *max_element(dp, dp + X);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> t;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		f[a[i]] += 1;
	}

	if (t <= 600) {
		cout << calc(1, 300, t) << '\n';
		return 0;
	}

	long long ans = 0;
	for (int x = 1; x <= 300; x++) {
		if (!f[x]) continue;
		long long can = 0;
		can += calc(1, x, 300) + calc(x, 300, 300);
		can += 1LL * (t - 600) * f[x];
		ans = max(ans, can);
	}

	cout << ans << '\n';

	return 0;
}
