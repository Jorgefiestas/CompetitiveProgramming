#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, cnt[N];
long long dp[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	
	int a;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		cnt[a] += 1;
	}

	long long ans = 0;
	for (int i = 1; i < N; i++) {
		dp[i] = (long long) cnt[i] * i;
		if (i > 1) {
			dp[i] += dp[i - 2];
		}

		dp[i] = max(dp[i], dp[i - 1]);
		ans = max(ans, dp[i]);
	}

	cout << ans << '\n';

	return 0;
}
