#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
int t, n;
long long dp[N], ans;
vector<int> adjList[N];

void dfs(int v, int p) {
	for (int u : adjList[v]) {
		if (u == p) continue;
		dfs(u, v);
		dp[v] += max(dp[u], 0LL);
	}

	ans = max(ans, dp[v]);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cin >> n;

		for (int i = 1; i <= n; i++) {
			cin >> dp[i];
			adjList[i].clear();
		}

		int a, b;
		for (int i = 1; i < n; i++) {
			cin >> a >> b;
			adjList[a].emplace_back(b);
			adjList[b].emplace_back(a);
		}

		ans = -2e17;
		dfs(1, 0);
		cout << ans << '\n';
	}

	return 0;
}
