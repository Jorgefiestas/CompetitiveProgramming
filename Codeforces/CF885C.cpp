#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e5 + 10;
int n, m, k, x;
int dp1[11], dp[3][N][11];
vector<int> adjList[N];

int add(int x, int y) {
	if (x + y >= mod) {
		return x + y - mod;
	}
	return x + y;
}

int mul(int x, int y) {
	return (long long) x * y % mod;
}

void dfs(int v, int p) {
	dp[0][v][0] = k - 1;
	dp[1][v][1] = 1;
	dp[2][v][0] = m - k;

	for (int u : adjList[v]) {
		if (u == p) continue;
		dfs(u, v);
	}
	
	for (int u : adjList[v]) {
		if (u == p) continue;
		memset(dp1, 0, sizeof dp1);
		for (int i = 0; i <= x; i++) {
			for (int j = 0; i + j <= x; j++) {
				int sum = add(add(dp[0][u][j], dp[1][u][j]), dp[2][u][j]);
				dp1[i + j] = add(dp1[i + j], mul(dp[0][v][i], sum));
			}
		}

		for (int i = 0; i <= x; i++) {
			dp[0][v][i] = dp1[i];
		}
	}

	for (int u : adjList[v]) {
		if (u == p) continue;
		memset(dp1, 0, sizeof dp1);
		for (int i = 1; i <= x; i++) {
			for (int j = 0; i + j <= x; j++) {
				dp1[i + j] = add(dp1[i + j], mul(dp[1][v][i], dp[0][u][j]));
			}
		}

		for (int i = 0; i <= x; i++) {
			dp[1][v][i] = dp1[i];
		}
	}

	for (int u : adjList[v]) {
		if (u == p) continue;
		memset(dp1, 0, sizeof dp1);
		for (int i = 0; i <= x; i++) {
			for (int j = 0; i + j <= x; j++) {
				int sum = add(dp[0][u][j], dp[2][u][j]);
				dp1[i + j] = add(dp1[i + j], mul(dp[2][v][i], sum));
			}
		}

		for (int i = 0; i <= x; i++) {
			dp[2][v][i] = dp1[i];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	int a, b;
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		adjList[a].emplace_back(b);
		adjList[b].emplace_back(a);
	}

	cin >> k >> x;
	dfs(1, 0);

	int ans = 0;
	for (int i = 0; i <= x; i++) {
		for (int j = 0; j < 3; j++) {
			ans = add(ans, dp[j][1][i]);
		}
	}

	cout << ans << '\n';

	return 0;
}
