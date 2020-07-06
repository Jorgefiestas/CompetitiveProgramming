#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int n, dp[N][N], v[N][N];

long long solve() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> v[j][i - j + 1];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n - i + 1; j++) {
			dp[i][j] = v[i][j] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
		}
	}
	
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = n - i + 1; j >= 1; j--) {
			ans = max(ans, dp[i][j] + dp[i - 1][j + 1]);

			int col = dp[i][j] - dp[i][j - 1];
			dp[i][j] = max({col, dp[i][j + 1] + col, dp[i - 1][j + 1] + col, dp[i - 1][j]});
		}
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (cin >> n, n) {
		memset(dp, 0, sizeof dp);
		cout << solve() << '\n';
	}

	return 0;
}
