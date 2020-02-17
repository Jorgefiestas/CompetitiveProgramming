#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, m, name[N], res[N], k[N], par[N];
vector<int> adjList[N], queries[N];

map<int, int> trie[50 * N];
int elem, strcnt, term[50 * N];

int str_hash(string &str) {
	int root = 0;

	for (int c : str) {
		if (!trie[root].count(c)) {
			trie[root][c] = ++elem;
		} 
		root = trie[root][c];
	}

	if (!term[root]) {
		term[root] = ++strcnt;
	}

	return term[root];
}

int sz[N], depth[N];

void calcSize(int v) {
	sz[v] = 1;
	for (int u : adjList[v]) {
		depth[u] = depth[v] + 1;
		calcSize(u);
		sz[v] += sz[u];
	}
}

int t, st[N], ft[N], ver[N];
unordered_set<int> nameCnt[N];

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
			nameCnt[depth[w]].insert(name[w]);
		}
	}

	nameCnt[depth[v]].insert(name[v]);

	for (int q : queries[v]) {
		if (k[q] + depth[v] >= N) continue;
		res[q] = nameCnt[k[q] + depth[v]].size();
	}

	if (keep == 0) {
		for (int i = st[v]; i < ft[v]; i++) {
			int u = ver[i];
			nameCnt[depth[u]].erase(name[u]);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	int v;
	string sname;
	for (int i = 1; i <= n; i++) {
		cin >> sname >> v;
		name[i] = str_hash(sname);
		par[i] = v;
		if (v) {
			adjList[v].push_back(i);
		}
	}

	cin >> m;

	int vi, ki;
	for (int i = 0; i < m; i++) {
		cin >> vi >> ki;
		k[i] = ki;
		queries[vi].push_back(i);
	}

	for (int i = 1; i <= n; i++) {
		if (par[i]) continue;
		calcSize(i);
	}

	for (int i = 1; i <= n; i++) {
		if (par[i]) continue;
		dfs(i, 0);
	}

	for (int i = 0; i < m; i++) {
		cout << res[i] << '\n';
	}

	return 0;
}
