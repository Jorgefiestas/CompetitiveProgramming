#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, dp[N][2];
vector<int> adjList[N];

void dfs(int v, int p) {
	dp[v][0] = 0;
	dp[v][1] = 1;
	for (int u : adjList[v]) {
		if (u == p) continue;
		dfs(u, v);
		dp[v][0] += dp[u][1];
		dp[v][1] += min(dp[u][1], dp[u][0]);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	int a, b;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		adjList[a].emplace_back(b);
		adjList[b].emplace_back(a);
	}

	dfs(1, -1);
	cout << min(dp[1][0], dp[1][1]) << '\n';

	return 0;
}
