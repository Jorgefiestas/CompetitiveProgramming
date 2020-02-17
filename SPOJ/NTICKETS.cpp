#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
const int LG = 17;
int n, q, depth[N];
int up[LG][N], up_mx[LG][N];
vector<vector<int>> adjList;
unordered_map<int, int> cost[N];

void dfs(int v, int p) {
	for (int i = 1; i < LG; i++) {
		int u = up[i - 1][v];
		if (u == -1) break;
		up_mx[i][v] = max(up_mx[i - 1][v], up_mx[i - 1][u]);
		up[i][v] = up[i - 1][u];
	}

	for (int u : adjList[v]) {
		if (u == p) continue;
		depth[u] = depth[v] + 1;
		up[0][u] = v;
		up_mx[0][u] = cost[u][v];
		dfs(u, v);
	}
}

int walk(int &v, int k) {
	int mx = 0;
	for (int i = 0; i < LG; i++) {
		if (k & (1 << i)) {
			mx = max(mx, up_mx[i][v]);
			v = up[i][v];
		}
	}
	return mx;
}

int max_tickets(int v, int u) {
	if (depth[v] < depth[u]) {
		swap(u, v);
	}

	int mx = walk(v, depth[v] - depth[u]);

	if (u == v) {
		return mx;
	}

	for (int i = LG - 1; i >= 0; i--) {
		if (up[i][v] != up[i][u]) {
			mx = max({mx, up_mx[i][v],  up_mx[i][u]});
			v = up[i][v], u = up[i][u];
		}
	}

	return max({mx, up_mx[0][v], up_mx[0][u]});
}


void solve() {
	adjList.resize(n + 5);

	int a, b, c;
	for (int i = 1; i < n; i++) {
		cin >> a >> b >> c;
		cost[a][b] = c;
		cost[b][a] = c;
		adjList[a].emplace_back(b);
		adjList[b].emplace_back(a);
	}

	dfs(1, -1);

	cin >> q;
	int u, v, k;
	for (int i = 0; i < q; i++) {
		cin >> u >> v;
		cout << max_tickets(v, u) << '\n';
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (cin >> n, n) {
		memset(up, -1, sizeof up);
		adjList.clear();
		solve();
	}

	return 0;
}
