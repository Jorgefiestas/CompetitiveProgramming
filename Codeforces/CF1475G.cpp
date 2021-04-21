#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;

int solve() {
	int n;
	cin >> n;

	vector<int> a(n);
	vector<int> dp(N, 0);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a.begin(), a.end());

	int ans = 0;
	for (auto x : a) {
		int can = 0;
		for (int d = 1; d * d <= x; d++) {
			if (x % d) continue;
			can = max(can, dp[d] + 1);
			can = max(can, dp[x / d] + 1);
		}

		dp[x] = max(dp[x], can);
		ans = max(ans, dp[x]);
	}

	return n - ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		cout << solve() << '\n';
	}

	return 0;
}
