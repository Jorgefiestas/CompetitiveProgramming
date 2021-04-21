#include <bits/stdc++.h>
using namespace std;
const int N = 505;
int t, n, m;
bool dp[N][N][N];

int solve() {
	cin >> n >> m;

	char mij;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> mij;

			dp[1][i][j] = mij == '*';
		}
	}


	for (int k = 2; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (!dp[1][i][j]) continue;

				bool op1 = dp[k - 1][i + 1][j - 1];
				bool op2 = dp[k - 1][i + 1][j];
				bool op3 = dp[k - 1][i + 1][j + 1];
				dp[k][i][j] = op1 && op2 && op3;
			}
		}
	}

	int ans = 0;
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (dp[k][i][j]) ans += 1;
			}
		}
	}

	return ans;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		memset(dp, 0, sizeof dp);
		cout << solve() << '\n';
	}

	return 0;
}
