#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int N = 2e5 + 100;
int n, m, k;
vector<int> adjList[N];

int timer, par[N], depth[N], tin[N], tout[N];

void dfs(int v, int p) {
	tin[v] = timer++;
	par[v] = p;
	for (int u : adjList[v]) {
		if (u == p) continue;
		depth[u] = depth[v] + 1;
		dfs(u, v);
	}
	tout[v] = timer++;
}

bool isAns(int u, int v) {
	if (depth[u] > depth[v]) {
		swap(u, v);
	}

	return tin[u] < tin[v] && tout[v] < tout[u];
}

bool query() {
	cin >> k;

	set<pii> nodes;

	int x;
	for (int i = 0; i < k; i++) {
		cin >> x;
		if (x == 1) continue;
		int p = par[x];
		nodes.insert({depth[p], p});
	}

	int last = 1;
	for (pii p : nodes) {
		if (p.first == 0) continue;
		if (!isAns(last, p.second)) {
			return false;
		}
		last = p.second;
	}

	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	int a, b;
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		adjList[a].emplace_back(b);
		adjList[b].emplace_back(a);
	}

	dfs(1, 0);

	for (int qi = 0; qi < m; qi++) {
		if (query()) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}

	return 0;
}
