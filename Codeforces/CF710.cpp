#include <bits/stdc++.h>
using namespace std;
const int N = 1e7 + 100;
int n, x, y;
long long dp[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < N; i++) {
		dp[i] = LLONG_MAX;
	}
	
	cin >> n >> x >> y;

	dp[0] = 0;
	for (int i = 0; i <= n; i++) {
		dp[i + 1] = min(dp[i + 1], dp[i] + x);
		if (2 * i < N) {
			dp[2 * i] = min(dp[2 * i], dp[i] + y);
			dp[2 * i - 1] = min(dp[2 * i - 1], dp[i] + y + x);
		}
	}

	cout << dp[n] << '\n';

	return 0;
}
