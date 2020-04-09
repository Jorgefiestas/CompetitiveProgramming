#include <bits/stdc++.h>
using namespace std;
const int N = 4e3 + 5;
const int K = 805;
int n, k, u[N][N];
int dp[K][N], cost[N][N];

void computeRow(int l, int r, int optl, int optr, int idx) {
	if (l > r) {
		return;
	}

	int mid = (l + r) / 2;
	int opt = -1;
	dp[idx][mid] = INT_MAX;

	for (int i = optl; i <= min(mid, optr); i++) {
		int temp = cost[i][mid] + dp[idx - 1][i - 1];
		if (temp < dp[idx][mid]) {
			dp[idx][mid] = temp;
			opt = i;
		}
	}

	computeRow(l, mid - 1, optl, opt, idx);
	computeRow(mid + 1, r, opt, optr, idx);
}

int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			char c = '\0';
			while (!isdigit(c)) {
				c = getchar();
			}
			u[i][j] = c - '0';
			u[i][j] = u[i][j] + u[i][j - 1];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			cost[i][j] = cost[i][j - 1] + u[j][j] - u[j][i  - 1];
		}
	}

	for (int i = 1; i <= n; i++)  {
		dp[1][i] = cost[1][i];
	}

	for (int i = 2; i <= k; i++) {
		computeRow(i, n, i, n, i);
	}

	cout << dp[k][n] << '\n';

	return 0;
}
