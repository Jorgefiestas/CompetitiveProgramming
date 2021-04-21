#include <bits/stdc++.h>
using namespace std;
const int N = 5e4 + 100;
const int K = 505;
int n, k;
long long ans, dp[N][K];
vector<int> adjList[N];

void dfs(int v, int p) {
	dp[v][0] = 1;

	for (int u : adjList[v]) {
		if (u == p) continue;
		dfs(u, v);

		for (int i = 1; i <= k; i++) {
			ans += dp[v][k - i] * dp[u][i - 1];
		}
		for (int i = 0; i < k; i++) {
			dp[v][i + 1] += dp[u][i];
		}
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
	}

	dfs(1, -1);

	cout << ans << '\n';

	return 0;
}
