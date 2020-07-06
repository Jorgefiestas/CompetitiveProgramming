#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
int n, a[N], b[N];
long long dp[N], dp0[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}

	sort(b + 1, b + n + 1);

	dp[0] = LLONG_MAX;
	for (int i = 1; i <= n; i++) {
		dp0[0] = LLONG_MAX;

		for (int j = 1; j <= n; j++) {
			dp0[j] = (long long) abs(a[i] - b[j]);
			dp0[j] += min(dp[j], dp[j - 1]);

			dp0[j] = min(dp0[j], dp0[j - 1]);
		}

		for (int j = 1; j <= n; j++) {
			dp[j] = dp0[j];
		}
	}

	cout << *min_element(dp + 1, dp + 1 + n) << '\n';

	return 0;
}
