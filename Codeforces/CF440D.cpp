#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int N = 402;
int n, k, dp[N][N], dp1[N], edge[N][N], par[N];
short to[N][N][N];
vector<int> adjList[N];

void dfs(int v, int p) {
	par[v] = p;
	memset(dp[v], 1, sizeof dp[v]);
	dp[v][1] = 0;

	for (int u : adjList[v]) {
		if (u == p) continue;
		dfs(u, v);

		memset(dp1, 1, sizeof dp1);
		for (int i = 1; i <= k; i++) {
			for (int j = 0; j <= k - i; j++) {
				if (dp1[i + j] <= dp[v][i] + dp[u][j]) continue;
				dp1[i + j] = dp[v][i] + dp[u][j];
				to[v][i + j][u] = j;
			}
		}

		for (int i = 0; i <= k; i++) {
			dp[v][i] = dp1[i];
		}
	}

	dp[v][0] = 1;
}

void trace_back(int v, int m, int p) {
	reverse(adjList[v].begin(), adjList[v].end());

	for (int u : adjList[v]) {
		if (u == p) continue;
		if (to[v][m][u]) {
			trace_back(u, to[v][m][u], v);
		}
		else {
			cout << edge[v][u] << ' ';
		}
		m -= to[v][m][u];
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	int a, b;
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		adjList[a].emplace_back(b);
		adjList[b].emplace_back(a);
		edge[a][b] = i;
		edge[b][a] = i;
	}

	dfs(1, 0);

	int s = 1;
	for (int i = 2; i <= n; i++) {
		dp[i][k]++;
		if (dp[i][k] < dp[s][k]) {
			s = i;
		}
	}
	
	cout << dp[s][k] << '\n';
	trace_back(s, k, 0);
	cout << '\n';

	return 0;
}
