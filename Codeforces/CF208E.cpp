#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, m, quHeight[N];
int par[N], res[N];
vector<int> adjList[N], queries[N];

int sz[N], depth[N];
void calcSize(int v) {
	sz[v] = 1;
	for (int u : adjList[v]) {
		depth[u] = depth[v] + 1;
		calcSize(u);
		sz[v] += sz[u];
	}
}

vector<int> Hqueries[N], toAddQuery[N];
void buildQueries(int v) {
	for (int q : toAddQuery[v]) {
		if (depth[v] - quHeight[q] < 0) {
			res[q] = 0;
		}
		else {
			Hqueries[depth[v] - quHeight[q]].emplace_back(q);
			quHeight[q] = depth[v];
		}
	}
	for (int u : adjList[v]) {
		buildQueries(u);
	}
	for (int q : Hqueries[depth[v]]) {
		queries[v].emplace_back(q);
	}
	Hqueries[depth[v]].clear();
}

int t, st[N], ft[N], ver[N];
int cnt[N];
void dfs(int v, bool keep) {
	ver[t] = v;
	st[v] = t++;

	int bigChild = 0;

	for (int u : adjList[v]) {
		if (sz[u] > sz[bigChild]) {
			bigChild = u;
		}
	}

	for (int u : adjList[v]) {
		if (u == bigChild) continue;
		dfs(u, 0);
	}
	if (bigChild) {
		dfs(bigChild, 1);
	}

	ft[v] = t;

	for (int u : adjList[v]) {
		if (u == bigChild) continue;
		for (int i = st[u]; i < ft[u]; i++) {
			int w = ver[i];
			cnt[depth[w]]++;
		}
	}

	cnt[depth[v]]++;

	for (int q : queries[v]) {
		res[q] = cnt[quHeight[q]] - 1;
	}

	if (keep == 0) {
		for (int i = st[v]; i < ft[v]; i++) {
			int u = ver[i];
			cnt[depth[u]]--;
		}
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> par[i];
		if (par[i]) {
			adjList[par[i]].emplace_back(i);
		}
	}

	for (int i = 1; i <= n; i++) {
		if (par[i]) continue;
		calcSize(i);
	}

	cin >> m;

	int vi, pi;
	for (int i = 0; i < m; i++) {
		cin >> vi >> pi;
		quHeight[i] = pi;
		toAddQuery[vi].push_back(i);
	}

	for (int i = 1; i <= n; i++) {
		if (par[i]) continue;
		buildQueries(i);
	}

	for (int i = 1; i <= n; i++) {
		if (par[i]) continue;
		dfs(i, 0);
	}

	for (int i = 0; i < m; i++) {
		cout << res[i] << ' ';
	}
	cout << endl;

	return 0;
}
