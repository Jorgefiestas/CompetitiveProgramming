#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 100;
int n;
long long x, dp[3][N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> x;

	long long a;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		dp[0][i] = max(dp[0][i - 1] + a, a);
		dp[1][i] = max({dp[0][i - 1] + a * x, dp[1][i - 1] + a * x, a * x});
		dp[2][i] = max({dp[1][i - 1] + a, dp[2][i - 1] + a, a});
	}

	long long ans = *max_element(dp[0], dp[0] + n + 1);
	ans = max(ans, *max_element(dp[1], dp[1] + n + 1));
	ans = max(ans, *max_element(dp[2], dp[2] + n + 1));

	cout << ans << '\n';

	return 0;
}
