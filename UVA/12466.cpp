#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
int t, n, k, val[N], sz[N];
int dp[N][105];
vector<int> order, adjList[N];

void dfs(int v) {
	sz[v] = 1;
	for (int u : adjList[v]) {
		dfs(u);
		sz[v] += sz[u];
	}
	order.emplace_back(v);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (cin >> n >> k, n) {
		order.clear();
		for (int i = 1; i <= n; i++) {
			adjList[i].clear();
		}

		for (int i = 1; i <= n; i++) {
			cin >> val[i];
		}

		int p;
		for (int i = 2; i <= n; i++) {
			cin >> p;
			adjList[p + 1].emplace_back(i);
		}

		order.push_back(0);
		dfs(1);

		for (int i = 0; i <= n; i++) {
			for (int j = 1; j <= k; j++) {
				dp[i][j] = -1e7; 
			}
		}

		for (int j = 1; j <= k; j++) {
			for (int i = 1; i <= n; i++) {
				int v = order[i];
				dp[i][j] = max(dp[i - sz[v]][j - 1] + val[v], dp[i - 1][j]);
			}
		}
		
		cout << *max_element(dp[n] + 1, dp[n] + k + 1) << '\n';
	}

	return 0;
}
