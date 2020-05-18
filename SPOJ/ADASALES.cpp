#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int N = 5e5 + 100;
int n, q, val[N];
vector<int> adjList[N];
map<int, pii> dp[N];
map<int, bool> vis[N];

void dfs(int v, int p) {
	if (vis[v][p]) return;
	vis[v][p] = true;
	
	int ans = 0;
	int mx = val[v];
	for (int u : adjList[v]) {
		if (u == p) continue;
		dfs(u, v);
		mx = max(mx, dp[u][v].second);
		ans = max(ans, dp[u][v].second - val[v]);
		ans = max(ans, dp[u][v].first);
	}

	dp[v][p].first = ans;
	dp[v][p].second = mx;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> val[i];
	}

	int a, b;
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		adjList[a].emplace_back(b);
		adjList[b].emplace_back(a);
	}

	int s;
	for (int i = 0; i < q; i++) {
		cin >> s;
		dfs(s, -1);
		cout << dp[s][-1].first << '\n';
	}

	return 0;
}
