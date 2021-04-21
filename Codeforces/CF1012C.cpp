#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
long long n, a[N], val[N], dp[N][N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (int i = 1; i <= n; i++) {
		val[i] += max(a[i - 1] - a[i] + 1, 0LL);
		val[i] += max(a[i + 1] - a[i] + 1, 0LL);
		dp[1][i] = val[i];
	}

	for (int k = 2; k <= (n + 1) / 2; k++) {
		fill(dp[k], dp[k] + n, 1e12);
		long long best = 1e12;;

		for (int i = 2 * k - 1; i <= n; i++) {
			long long c1 = best + val[i];

			long long c2 = dp[k - 1][i - 2];
			c2 += max(min(a[i - 2] - 1, a[i - 1]) - a[i] + 1, 0LL);
			c2 += max(a[i + 1] - a[i] + 1, 0LL);

			dp[k][i] = min(c1, c2);
			best = min(best, dp[k - 1][i - 2]);
		}
	}

	for (int k = 1; k <= (n + 1) / 2; k++) {
		cout << *min_element(dp[k] + 2 * k - 1, dp[k] + n + 1) << ' ';
	}
	cout << '\n';

	return 0;
}
