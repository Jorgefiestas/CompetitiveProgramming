#include <bits/stdc++.h>
using namespace std;
const int N = 10005;
const int LG = 14;
int T, n, depth[N];
int up[LG][N], up_d[LG][N];
vector<vector<int>> adjList;
unordered_map<int, int> cost[N];

void dfs(int v, int p) {
	for (int i = 1; i < LG; i++) {
		int u = up[i - 1][v];
		if (u == -1) break;
		up_d[i][v] = up_d[i - 1][v] + up_d[i - 1][u];
		up[i][v] = up[i - 1][u];
	}

	for (int u : adjList[v]) {
		if (u == p) continue;
		depth[u] = depth[v] + 1;
		up[0][u] = v;
		up_d[0][u] = cost[u][v];
		dfs(u, v);
	}
}

int walk(int &v, int k) {
	int d = 0;
	for (int i = 0; i < LG; i++) {
		if (k & (1 << i)) {
			d += up_d[i][v];
			v = up[i][v];
		}
	}
	return d;
}

int LCA(int v, int u) {
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

int kth(int v, int u, int k) {
	int lca = LCA(v, u);

	if (depth[v] - depth[lca] + 1 >= k) {
		walk(v, k - 1);
		return v;
	}
	
	walk(u, depth[v] + depth[u] - 2 * depth[lca] + 1 - k);
	return u;
}

int dist(int v, int u) {
	if (depth[v] < depth[u]) {
		swap(u, v);
	}

	int d = walk(v, depth[v] - depth[u]);

	if (u == v) {
		return d;
	}

	for (int i = LG - 1; i >= 0; i--) {
		if (up[i][v] != up[i][u]) {
			d += up_d[i][v] + up_d[i][u];
			v = up[i][v], u = up[i][u];
		}
	}

	return d + up_d[0][v] + up_d[0][u];
}


void solve() {
	cin >> n;
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

	string type;
	int u, v, k;
	while (cin >> type, type != "DONE") {
		if (type == "DIST") {
			cin >> v >> u;
			cout << dist(v, u) << '\n';
		}
		else {
			cin >> v >> u >> k;
			cout << kth(v, u, k) << '\n';
		}
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		memset(up, -1, sizeof up);
		adjList.clear();
		solve();
	}

	return 0;
}
