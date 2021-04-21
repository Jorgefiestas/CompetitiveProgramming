#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100;
int t, n, k, x[N], y[N], best[N];

int solve() {
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> y[i];
	}

	sort(x, x + n);
	
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int idx = lower_bound(x, x + n, x[i] - k) - x;
		best[i] = i - idx + 1;

		int can = best[i];
		if (idx > 0) {
			can += best[idx - 1];
		}

		if (i > 0) {
			best[i] = max(best[i - 1], best[i]);
		}

		ans = max(ans, can);
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
