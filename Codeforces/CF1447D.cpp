#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
int n, m, dp[N][N];
char a[N], b[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= m; i++) {
		cin >> b[i];
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dp[i][j] = max(dp[i - 1][j] - 1, dp[i][j - 1] - 1);
			dp[i][j] = max(dp[i][j], 0);

			if (a[i] == b[j]) {
				int can = dp[i - 1][j - 1] + 2;
				dp[i][j] = max(dp[i][j], can);
			}

			ans = max(ans, dp[i][j]);
		}
	}

	cout << ans << '\n';

	return 0;
}
