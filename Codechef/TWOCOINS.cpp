#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int t, n;
long long dp[N][8];
vector<int> adjList[N];

void dfs(int v, int p) {
	if (adjList[v].size() == 1 && v != 1) {
		dp[v][0] = N;
		dp[v][1] = N;
		dp[v][2] = N;
		dp[v][4] = N;
		dp[v][6] = N;
		return;
	}

	for (int u : adjList[v]) {
		if (u == p) continue;
		dfs(u, v);
		dp[v][7] += min(dp[u][6], 1 + dp[u][7]);
		dp[v][3] += min(dp[u][6], 1 + dp[u][7]);
		dp[v][5] += min(dp[u][2], 1 + dp[u][3]);
		dp[v][1] += min(dp[u][2], 1 + dp[u][3]);
	}

	int nd = 1;
	long long d = N;
	for (int u : adjList[v]) {
		if (u == p) continue;
		dp[v][6] += min(dp[u][4], 1 + dp[u][5]);
		dp[v][2] += min(dp[u][4], 1 + dp[u][5]);

		if (1 + dp[u][5] < dp[u][4]) {
			nd--;
		}
		else {
			d = min(d, 1 + dp[u][5] - dp[u][4]);
		}
	}
	if (nd > 0) {
		dp[v][6] += d;
		dp[v][2] += d;
	}

	nd = 2, d = N; 
	long long d2 = N;
	for (int u : adjList[v]) {
		if (u == p) continue;
		dp[v][0] += min(dp[u][0], 1 + dp[u][1]);
		dp[v][4] += min(dp[u][0], 1 + dp[u][1]);

		if (1 + dp[u][1] <= dp[u][0]) {
			nd--;
		}
		else {
			long long x = 1 + dp[u][1] - dp[u][0];
			if (x < d) {
				d2 = d;
				d = x;
			}
			else if (x < d2) {
				d2 = x;
			}
		}
	}
	if (nd == 2) {
		dp[v][0] += d + d2;
		dp[v][4] += d + d2;
	}
	else if (nd == 1) {
		dp[v][0] += d;
		dp[v][4] += d;
	}

	for (int i = 0; i < 8; i++) {
		dp[v][i] = min((long long) N, dp[v][i]);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		memset(dp, 0, sizeof dp);
		for (int i = 1; i <= n; i++) {
			adjList[i].clear();
		}

		cin >> n;

		int a, b;
		for (int i = 1; i < n; i++) {
			cin >> a >> b;
			adjList[a].emplace_back(b);
			adjList[b].emplace_back(a);
		}

		dfs(1, 0);
		long long ans = min(dp[1][0], 1 + dp[1][1]);
		if (n == 1 || ans >= N) {
			cout << -1 << '\n';
		}
		else {
			cout << ans << '\n';
		}
	}

	return 0;
}
