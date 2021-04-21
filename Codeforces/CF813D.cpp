#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
const int M = 1e5 + 10;
int n, a[N], mmx[8], nmx[M];
int dp[N][N];

bool check(int i, int j) {
	if (!i || !j) {
		return true;
	}
	int d = abs(a[i] - a[j]);
	return d == 1 || d % 7 == 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	int ans = 0;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			int aj = a[j];

			if (i >= j) {
				dp[i][j] = dp[j][i];
			}
			else {
				dp[i][j] = dp[i][0];
				dp[i][j] = max(dp[i][j], nmx[aj - 1]);
				dp[i][j] = max(dp[i][j], nmx[aj + 1]);
				dp[i][j] = max(dp[i][j], mmx[aj % 7]);
				dp[i][j] += 1;
			}

			if (aj > 0) {
				nmx[aj] = max(nmx[aj], dp[i][j]);
				mmx[aj % 7] = max(mmx[aj % 7], dp[i][j]);
			}
			ans = max(ans, dp[i][j]);
		}

		memset(mmx, 0, sizeof mmx);
		for (int j = 1; j <= n; j++) {
			nmx[a[j]] = 0;
		}
	}


	cout << ans << '\n';

	return 0;
}
