#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int LG = 17;
int n, q;
vector<int> adjList[N];

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

int dist(int v, int u) {
	if (depth[v] < depth[u]) {
		swap(u, v);
	}

	int ou = u;
	int ov = v;

	walk(v, depth[v] - depth[u]);

	if (u == v) {
		return depth[ov] - depth[v];
	}

	for (int i = LG - 1; i >= 0; i--) {
		if (up[i][v] != up[i][u]) {
			v = up[i][v], u = up[i][u];
		}
	}

	int lca = up[0][v];

	return depth[ou] + depth[ov] - 2 * depth[lca];
}

void lca_preprocess(int root) {
	memset(up, -1, sizeof up);
	lca_dfs(root, -1);
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
	}

	lca_preprocess(1); 

	cin >> q;

	int x, y, u, v, k;
	for (int i = 0; i < q; i++) {
		cin >> x >> y >> u >> v >> k;

		int par = k % 2;

		int d = dist(u, v);
		if (k >= d && d % 2 == par) {
			cout << "YES\n";
			continue;
		}

		d = dist(u, x) + 1 + dist(y, v);
		if (k >= d && d % 2 == par) {
			cout << "YES\n";
			continue;
		}

		d = dist(u, y) + 1 + dist(x, v);
		if (k >= d && d % 2 == par) {
			cout << "YES\n";
			continue;
		}

		cout << "NO\n";
	}

	return 0;
}
