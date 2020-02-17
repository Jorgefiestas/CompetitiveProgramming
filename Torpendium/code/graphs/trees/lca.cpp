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
		dfs(u, v);
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

void lca_preprocess(int root) {
	memset(up, -1, sizeof up);
	dfs(root, -1);
}
