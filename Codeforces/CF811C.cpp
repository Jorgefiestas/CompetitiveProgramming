#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
int n, a[N], first[N], last[N];
long long dp[N];
bool seen[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];

		last[a[i]] = i;
		if (!first[a[i]]) {
			first[a[i]] = i;
		}
	}

	for (int i = 1; i <= n; i++) {
		dp[i] = dp[i - 1];

		int xr = 0;
		int to = INT_MAX;

		memset(seen, 0, sizeof seen);

		for (int j = i; j > 0; j--) {
			if (last[a[j]] > i) break;

			to = min(to, first[a[j]]);
			if (!seen[a[j]]) {
				xr = xr ^ a[j];
				seen[a[j]] = true;
			}

			if (j == to) {
				dp[i] = max(dp[i], dp[j - 1] + (long long) xr);
			}
		}
	}

	cout << dp[n] << '\n';

	return 0;
}
