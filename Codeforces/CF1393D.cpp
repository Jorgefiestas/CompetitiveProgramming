#include <bits/stdc++.h>
using namespace std;
const int N = 205;
int sz[3], a[3][N];
long long dp[N][N][N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 3; i++) {
		cin >> sz[i];
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < sz[i]; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < 3; i++) {
		sort(a[i], a[i] + sz[i], greater<int>());
	}

	long long ans = 0;

	for (int i = 0; i <= sz[0]; i++) {
		for (int j = 0; j <= sz[1]; j++) {
			for (int k = 0; k <= sz[2]; k++) {
				if ((i || j || k) && !dp[i][j][k]) continue;
				long long can;

				can = dp[i][j][k] + (long long) a[0][i] * a[1][j];
				dp[i + 1][j + 1][k] = max(dp[i + 1][j + 1][k], can);

				can = dp[i][j][k] + (long long) a[0][i] * a[2][k];
				dp[i + 1][j][k + 1] = max(dp[i + 1][j][k + 1], can);

				can = dp[i][j][k] + (long long) a[1][j] * a[2][k];
				dp[i][j + 1][k + 1] = max(dp[i][j + 1][k + 1], can);

				ans = max(ans, dp[i][j][k]);
			}
		}
	}


	cout << ans << endl;

	return 0;
}
