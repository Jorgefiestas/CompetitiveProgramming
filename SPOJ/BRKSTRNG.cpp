#include <bits/stdc++.h>
using namespace std;
const int M = 1005;
int n, m, k[M][M], b[M];
long long cost[M][M], dp[M][M];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (cin >> n >> m) {
		int nw, lst = 0;
		for (int i = 1; i <= m; i++) {
			cin >> nw;
			b[i] = nw - lst;
			lst = nw;
		}
		m++;
		b[m] = n - lst;

		for (int i = 1; i <= m; i++) {
			k[i][i] = i;
			cost[i][i] = b[i];
			for (int j = i + 1; j <= m; j++) {
				cost[i][j] = (long long) cost[i][j - 1] + b[j];
			}
		}

		for (int l = 1; l <= m; l++) {
			for (int i = m - l; i > 0; i--) {
				int j = i + l;
				long long ans = LLONG_MAX;

				for (int m = k[i][j - 1]; m <= min(j - 1, k[i + 1][j]); m++) {
					long long tans = dp[i][m] + dp[m + 1][j];
					if (tans < ans) {
						k[i][j] = m;
						ans = tans;
					}
				}
				dp[i][j] = cost[i][j] + ans;
			}
		}

		cout << dp[1][m] << '\n';
	}

	return 0;
}
