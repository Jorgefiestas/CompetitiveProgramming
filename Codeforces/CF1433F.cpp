#include <bits/stdc++.h>
using namespace std;
const int N = 75;
int n, m, k;
int dp[N][N][N], mx[N][N], res[N][N];

void calc(int ans[N]) {
	memset(dp, -1, sizeof dp);

	int vi;
	for (int i = 1; i <= m; i++) {
		cin >> vi;
		dp[i - 1][0][0] = 0;
		for (int c = 1; c <= m / 2; c++) {
			for (int w = 0; w < k; w++) {
				int nw = (k + (w - vi) % k) % k;

				dp[i][c][w] = dp[i - 1][c][w];
				if (dp[i - 1][c - 1][nw] != -1) {
					dp[i][c][w] = max(dp[i][c][w], dp[i - 1][c - 1][nw] + vi);
				}

				ans[w] = max(dp[i][c][w], ans[w]);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;

	memset(mx, -1, sizeof mx);
	for (int i = 1; i <= n; i++) {
		calc(mx[i]);
	}

	memset(res, -1, sizeof res);
	res[0][0] = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < k; j++) {
			res[i][j] = res[i - 1][j];
			for (int w = 0; w < k; w++) {
				int nw = (k + (j - w) % k) % k;
				if (res[i - 1][nw] != -1 && mx[i][w] != -1) {
					res[i][j] = max(res[i][j], res[i - 1][nw] + mx[i][w]);
				}
			}
		}
	}

	cout << res[n][0] << '\n';

	return 0;
}
