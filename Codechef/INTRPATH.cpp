#include <bits/stdc++.h>
using namespace std;
const int N = 300005;
const int LG = 19;
int t, n, q, depth[N], up[LG][N];
long long sz[N], up_cnt[LG][N], vp[N];
vector<vector<int>> adjList;

void calcSize(int v, int p) {
	sz[v] = 1;

	for (int u : adjList[v]) {
		if (u == p) continue;
		depth[u] = depth[v] + 1;
		calcSize(u, v);
		sz[v] += sz[u];
	}
	
	for (int u : adjList[v]) {
		if (u == p) continue;
		vp[v] += (sz[v] - sz[u]) * sz[u];
	}
	vp[v] += sz[v] - 1;
	vp[v] /= 2;
	vp[v] += 1;
}

void dfs(int v, int p) {
	for (int i = 1; i < LG; i++) {
		int u = up[i - 1][v];
		if (u == -1) break;
		up_cnt[i][v] = up_cnt[i - 1][v] + up_cnt[i - 1][u];
		up[i][v] = up[i - 1][u];
	}

	for (int u : adjList[v]) {
		if (u == p) continue;
		up_cnt[0][u] = vp[v] - sz[u]*sz[v] + sz[u]*sz[u];
		up[0][u] = v;
		dfs(u, v);
	}
}

long long walk(int &v, int k) {
	long long sm = 0;
	for (int i = 0; i < LG; i++) {
		if (k & (1 << i)) {
			sm += up_cnt[i][v];
			v = up[i][v];
		}
	}
	return sm;
}

long long LCA(int v, int u) {
	long long ans;

	if (u == v) {
		return vp[v] + (sz[1] - sz[v]) * sz[v];
	}

	if (depth[v] < depth[u]) {
		swap(u, v);
	}

	ans = vp[v];

	if (depth[u] != depth[v]) {
		ans += walk(v, depth[v] - depth[u] - 1);

		if (up[0][v] == u) {
			return ans + up_cnt[0][v] + (sz[1] - sz[u]) * (sz[u] - sz[v]);
		}

		ans += up_cnt[0][v];
		v = up[0][v];
	}

	ans += vp[u];
	
	for (int i = LG - 1; i >= 0; i--) {
		if (up[i][v] != up[i][u]) {
			ans += up_cnt[i][v] + up_cnt[i][u];
			v = up[i][v], u = up[i][u];
		}
	}

	int lca = up[0][v];

	ans += vp[lca] - sz[u] * (sz[lca] - sz[u]) - sz[v] * (sz[lca] - sz[v]) + sz[u] * sz[v];
	ans += (sz[1] - sz[lca]) * (sz[lca] - sz[u] - sz[v]);

	return ans;
}


void solve() {
	cin >> n >> q;

	adjList.resize(n + 5);

	int a, b;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		adjList[a].emplace_back(b);
		adjList[b].emplace_back(a);
	}

	calcSize(1, -1);
	dfs(1, -1);

	int u, v;
	for (int i = 0; i < q; i++) {
		cin >> u >> v;
		cout << LCA(v, u) << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> t;
	while (t--) {
		adjList.clear();
		depth[1] = 0;
		memset(up, -1, sizeof up);
		memset(vp, 0, sizeof vp);
		solve();
	}

	return 0;
}
