#include <bits/stdc++.h>
using namespace std;
const int N = 3505;
int t, n, m, k, a[N];

int solve() {
	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	if (k >= m) {
		k = m - 1;
	}

	int ans = 0;
	for (int l = 0; l <= k; l++) {
		int r = k - l;
		int mn = INT_MAX;

		for (int i = 1; i <= m - k; i++) {
			int best = max(a[n + k - r - m + i], a[l + i]);
			mn = min(mn, best);
		}

		ans = max(mn, ans);
	}

	return ans;
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
