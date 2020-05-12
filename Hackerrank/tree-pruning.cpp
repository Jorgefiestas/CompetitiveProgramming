#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 10;
int n, ver[N], sz[N];
ll w[N], dp[N][205];
vector<int> adjList[N];

int t = 0;
void dfs(int v, int p) {
	sz[v] = 1;
	for (int u : adjList[v]) {
		if (u == p) continue;
		dfs(u, v);
		sz[v] += sz[u];
	}

	ver[++t] = v;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		cin >> w[i];
	}
	
	int a, b;
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		adjList[a].emplace_back(b);
		adjList[b].emplace_back(a);
	}

	dfs(1, -1);

	for (int i = 1; i <= n; i++) {
		int v = ver[i];
		dp[i][0] = dp[i - 1][0] + w[v];
	}

	for (int j = 1; j <= k; j++) {
		for (int i = 1; i <= n; i++) {
			int v = ver[i];
			dp[i][j] = max(dp[i - 1][j] + w[v],
					dp[i - sz[v]][j - 1]);
		}
	}

	cout << dp[n][k] << '\n';

	return 0;
}
