#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 100;
int n, q;
long long val[N], ans[N];
vector<int> adjList[N];
multiset<long long, greater<long long>> dp[N];

void dfs1(int v, int p) {
	dp[v].insert(0);
	for (int u : adjList[v]) {
		if (u == p) continue;
		dfs1(u, v);
		long long mx = *dp[u].begin();
		long long cont = max(mx, mx + val[u] - val[v]);
		dp[v].insert(cont);
	}
}

void dfs2(int v, int p) {
	ans[v] = *dp[v].begin();

	for (int u : adjList[v]) {
		if (u == p) continue;
		long long mx = *dp[u].begin();
		long long cont = max(mx, mx + val[u] - val[v]);	

		dp[v].erase(dp[v].find(cont));

		long long mxv = *dp[v].begin();
		long long contv = max(mxv, mxv + val[v] - val[u]);
		dp[u].insert(contv);

		dfs2(u, v);

		dp[u].erase(dp[u].find(contv));
		dp[v].insert(cont);
	}
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

	dfs1(0, -1);
	dfs2(0, -1);

	int v;
	for (int qi = 0; qi < q; qi++) {
		cin >> v;
		cout << ans[v] << '\n';
	}

	return 0;
}
