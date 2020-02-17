#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int N = 500005;
int t, n, q, r, sh[N];
vector<int> adjList[N];
int res[N];

int dsu[N];

int find_set(int idx) {
	while (idx != dsu[idx]) {
		dsu[idx] = dsu[dsu[idx]];
		idx = dsu[idx];
	}
	return idx;
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
		dsu[a] = b;
    }
}

bool vis[N];
vector<int> queries[N];
vector<pii> lcaQueries[N];
int sz[N], ancestor[N];

void calcSize(int v, int p) {
	vis[v] = true;
	ancestor[v] = v;
	sz[v] = 1;

	for (int u : adjList[v]) {
		if (u == p) continue;
		calcSize(u, v);
		sz[v] += sz[u];
		union_sets(v, u);
		ancestor[find_set(v)] = v;
	}
	for (pii p : lcaQueries[v]) {
		if (vis[p.first]) {
			queries[ancestor[find_set(p.first)]].emplace_back(p.second);
		}
	}
}

int timer, cnt, st[N], ft[N], ver[N];
int shades[255];
void dfs(int v, int p, bool keep) {
	ver[timer] = v;
	st[v] = timer++;

	int bigChild = -1;

	for (int u : adjList[v]) {
		if (u == p) continue;
		if (bigChild == -1 || sz[u] > sz[bigChild]) {
			bigChild = u;
		}
	}

	for (int u : adjList[v]) {
		if (u == p || u == bigChild) continue;
		dfs(u, v, 0);
	}
	if (bigChild != -1) {
		dfs(bigChild, v, 1);
	}

	ft[v] = timer;

	for (int u : adjList[v]) {
		if (u == p || u == bigChild) continue;
		for (int t = st[u]; t < ft[u]; t++) {
			shades[sh[ver[t]]]++;
			if (shades[sh[ver[t]]] == 1) {
				cnt++;
			}
		}
	}

	shades[sh[v]]++;
	if (shades[sh[v]] == 1) {
		cnt++;
	}

	for (int qu : queries[v]) {
		res[qu] = cnt;
	}

	if (!keep) {
		for (int t = st[v]; t < ft[v]; t++) {
			shades[sh[ver[t]]]--;
			if (shades[sh[ver[t]]] == 0) {
				cnt--;
			}
		}
	}
}


void solve() {
	cin >> n >> q >> r;

	for (int i = 0; i < n; i++) {
		cin >> sh[i];
	}

	int a, b;
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		adjList[a].emplace_back(b);
		adjList[b].emplace_back(a);
	}

	int vi, ui;
	for (int i = 0; i < q; i++) {
		cin >> vi >> ui;
		lcaQueries[vi].push_back({ui, i});
		if (vi != ui) {
			lcaQueries[ui].push_back({vi, i});
		}
	}

	memset(vis, 0, sizeof vis);
	timer = 0;
	calcSize(r, -1);

	dfs(r, -1, 0);

	for (int i = 0; i < q; i++) {
		cout << res[i] << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	for (int i = 0; i < N; i++) {
		dsu[i] = i;
	}

	while (t--) {
		for (int i = 0; i < n; i++) {
			adjList[i].clear();
		}
		for (int i = 0; i < n; i++) {
			lcaQueries[i].clear();
			queries[i].clear();
		}
		for (int i = 0; i < n; i++) {
			dsu[i] = i;
		}
		solve();
	}

	return 0;
}
