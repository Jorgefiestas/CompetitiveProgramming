#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n;
long long dp[N], dist[N];
map<int, int> weight[N];
vector<int> adjList[N];

void dfs(int v, int p) {
	dist[v] = weight[v][p];
	long long ans = dist[v];

	for (int u : adjList[v]) {
		if (u == p) continue;
		dfs(u, v);
		dist[v] += dist[u];
		ans += 2LL * dist[u];
	}

	long long tot = ans;
	for (int u : adjList[v]) {
		if (u == p) continue;
		ans = min(ans, tot - 2LL * dist[u] + dp[u]);
	}

	dp[v] = ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	int a, b, w;
	for (int i = 1; i < n; i++) {
		cin >> a >> b >> w;
		adjList[a].emplace_back(b);
		adjList[b].emplace_back(a);
		weight[a][b] = w;
		weight[b][a] = w;
	}

	dfs(1, 0);

	cout << dp[1] << '\n';

	return 0;
}
