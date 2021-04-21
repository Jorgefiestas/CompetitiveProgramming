#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int LG = 20;
const int N = 2e5 + 100;
int n, k, dp[N];
vector<int> adjList[N];
map<int, int> ans[N];
pii e[N];

int depth[N], up[LG][N];

void lca_dfs(int v, int p) {
	for (int i = 1; i < LG; i++) {
		int u = up[i - 1][v];
		if (u == -1) break;
		up[i][v] = up[i - 1][u];
	}

	for (int u : adjList[v]) {
		if (u == p) continue;

		depth[u] = depth[v] + 1;
		up[0][u] = v;
		lca_dfs(u, v);
	}
}

void walk(int &v, int k) {
	for (int i = 0; i < LG; i++) {
		if (k & (1 << i)) {
			v = up[i][v];
		}
	}
}

int lca(int v, int u) {
	if (depth[v] < depth[u]) {
		swap(u, v);
	}

	walk(v, depth[v] - depth[u]);

	if (u == v) {
		return u;
	}

	for (int i = LG - 1; i >= 0; i--) {
		if (up[i][v] != up[i][u]) {
			v = up[i][v], u = up[i][u];
		}
	}

	return up[0][v];
}

void lca_preprocess(int root) {
	memset(up, -1, sizeof up);
	lca_dfs(root, -1);
}


void dfs(int v, int p) {
	for (int u : adjList[v]) {
		if (u == p) continue;
		dfs(u, v);
		dp[v] += dp[u];
	}

	if (p != -1) {
		ans[v][p] = dp[v];
		ans[p][v] = dp[v];
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
		e[i] = {a, b};
	}

	lca_preprocess(1);
	lca_dfs(1, -1);

	cin >> k;

	int u, v;
	for (int i = 0; i < k; i++) {
		cin >> u >> v;
		int l = lca(u, v);
		dp[u] += 1;
		dp[v] += 1;
		dp[l] -= 2;
	}


	dfs(1, -1);

	for (int i = 1; i < n; i++) {
		int u = e[i].first;
		int v = e[i].second;
		cout << ans[u][v] << ' ';
	}
	cout << '\n';

	return 0;
}
