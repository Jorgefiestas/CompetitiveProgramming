#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 5;
const int mod = 1e9 + 7;
int n, dp1[N][N], dp[N][N], a[N];
string snum;

int add(int x, int y) {
	if (x + y >= mod) {
		return x + y - mod;
	}
	return x + y;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> snum;

	for (int i = 1; i <= n; i++) {
		a[i] = snum[i - 1] - '0';
	}

	memset(dp1, 1, sizeof dp1);
	for (int i = n; i > 0; i--) {
		for (int j = n; j > i; j--) {
			if (a[i] == a[j]) {
				dp1[i][j] = 1 + dp1[i + 1][j + 1];
			}
			else {
				dp1[i][j] = 0;
			}
		}
	}

	if (a[1]) {
		for (int i = 1; i <= n; i++) {
			dp[1][i] = 1;
		}
	}
	
	for (int j = 2; j <= n; j++) {
		for (int i = j; i > 1; i--) {
			int len = j - i + 1;
			int lft = max(1, i - len);

			int dl = dp1[lft][i];
			if (i - len > 0 && i + dl > j) {
				lft++;
			}
			else if (i - len > 0 && i + dl <= j) {
				lft = (a[i + dl] > a[i - len + dl]) ? lft : lft + 1;
			}

			if (a[i]) {
				dp[i][j] = add(dp[i][j], dp[lft][i - 1]);
			}
			dp[i][j] = add(dp[i][j], dp[i + 1][j]);
		}
		dp[1][j] = add(dp[1][j], dp[2][j]);
	}

	cout << dp[1][n] << '\n';

	return 0;
}
