#include <bits/stdc++.h>
using namespace std;
const int N = 10005;
const int LG = 15;
int n, q, depth[N];
int up[LG][N];
vector<int> adjList[N];

void dfs(int v) {
	for (int i = 1; i < LG; i++) {
		int u = up[i - 1][v];
		if (u == -1) break;
		up[i][v] = up[i - 1][u];
	}

	for (int u : adjList[v]) {
		depth[u] = depth[v] + 1;
		up[0][u] = v;
		dfs(u);
	}
}

void walk(int &v, int k) {
	for (int i = 0; i < LG; i++) {
		if (k & (1 << i)) {
			v = up[i][v];
		}
	}
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



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	int m, ui;
	for (int vi = 0; vi < n; vi++) {
		cin >> m;
		for (int i = 0; i < m; i++) {
			cin >> ui;
			adjList[vi].emplace_back(ui);
		}
	}

	dfs(0);

	cin >> q;

	int u, v;
	for (int i = 0; i < q; i++) {
		cin >> u >> v;
		cout << LCA(v, u) << '\n';
	}

	return 0;
}
