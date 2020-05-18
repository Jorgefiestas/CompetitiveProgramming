#include <bits/stdc++.h>
using namespace std;
const int N = 205;
int t, n, m;
int rowsum[N][N], mat[N][N];

void solve() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> mat[i][j];
			mat[i][j] <<= 1;
			mat[i][j]--;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			rowsum[i][j] = rowsum[i][j - 1] + mat[i][j];
		}
	}

	int ans = INT_MIN;
	int cnt = 0;
	for (int j = 1; j <= m; j++) {
		for (int k = 1; k <= j; k++) {
			int dp = rowsum[1][j] - rowsum[1][j - k];
			int best = dp;
			int nbest = 1;
			int tans = dp;
			int tcnt = 1;

			for (int i = 2; i <= n; i++) {
				int row = rowsum[i][j] - rowsum[i][j - k];
				int borders = mat[i][j];
				if (k > 1) {
					borders += mat[i][j - k + 1];
				}

				dp = max(row + best, row);

				if (dp == tans) {
					if (row + best == tans) {
						tcnt += nbest;
					}
					if (row == tans) {
						tcnt++;
					}
				}
				else if (dp > tans) {
					if (row + best == row) {
						tcnt = nbest + 1;
					}
					else if (row + best > row) {
						tcnt = nbest;
					}
					else {
						tcnt = 1;
					}
					tans = dp;
				}

				best = best + borders;
				if (best == row) {
					nbest++;
				}
				else if (best < row) {
					nbest = 1;
					best = row;
				}

			}

			if (tans == ans) {
				cnt += tcnt;
			}
			else if (tans > ans) {
				ans = tans;
				cnt = tcnt;
			}
		}
	}
	
	cout << ans << ' ' << cnt << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
