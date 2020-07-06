#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 100;
int n, sz[N];
ll ans, dp[N];
vector<int> adjList[N];

void dfs1(int v, int p) {
	sz[v] = 1;
	for (int u : adjList[v]) {
		if (u == p) continue;
		dfs1(u, v);
		sz[v] += sz[u];
		dp[v] += dp[u];
	}
	dp[v] += (ll) sz[v];
}

void dfs2(int v, int p) {
	ans = max(ans, dp[v]);
	for (int u : adjList[v]) {
		if (u == p) continue;
		dp[v] -= dp[u] + (ll) sz[u]; 
		sz[v] -= sz[u];
		sz[u] += sz[v];
		dp[u] += dp[v] + (ll) sz[v];

		dfs2(u, v);

		dp[u] -= dp[v] + (ll) sz[v];
		sz[u] -= sz[v];
		sz[v] += sz[u];
		dp[v] += dp[u] + (ll) sz[u]; 
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	int a, b;
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		adjList[a].emplace_back(b);
		adjList[b].emplace_back(a);
	}

	dfs1(1, 0);
	dfs2(1, 0);

	cout << ans << '\n';

	return 0;
}
