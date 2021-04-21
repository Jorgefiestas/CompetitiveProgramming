#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, m, dp[N], col[N];
bool vis[N], root[N];
vector<int> adjList[N];

void dfs(int v) {
	vis[v] = true;
	dp[v] = col[v];

	for (int u : adjList[v]) {
		if (!vis[u]) {
			dfs(u);
		}

		if (col[v] && !col[u]) {
			dp[v] = max(dp[v], dp[u] + 1);
		}
		else {
			dp[v] = max(dp[v], dp[u]);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> col[i];
	}
	
	fill(root, root + n, true);

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		adjList[a].emplace_back(b);
		root[b] = false;
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (!root[i]) continue;
		dfs(i);
		ans = max(ans, dp[i]);
	}

	cout << ans << '\n';

	return 0;
}
