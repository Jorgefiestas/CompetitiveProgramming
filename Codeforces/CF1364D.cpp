#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
int n, k, m, depth[N], par[N];
vector<int> cycle, adjList[N];
bool vis[N];

void makeCycle(int v, int p) {
	while (v != p) {
		cycle.emplace_back(v);
		v = par[v];
	}
	cycle.emplace_back(p);
}

void dfs(int v) {
	vis[v] = true;
	for (int u : adjList[v]) {
		if (vis[u]) {
			if (u == par[v] || depth[v] < depth[u]) continue;
			if (cycle.empty()) {
				makeCycle(v, u);
			}

			int cycleSize = depth[v] - depth[u] + 1;
			if (cycle.size() > k && cycleSize <= k) {
				cycle.clear();
				makeCycle(v, u);
			}
			continue;
		}
		else {
			par[u] = v;
			depth[u] = depth[v] + 1;
			dfs(u);
		}
	}
}

int cnt[2];
bool col[N];
void dfs2(int v, int p) {
	for (int u : adjList[v]) {
		if (u == p) continue;
		col[u] = !col[v];
		cnt[!col[v]] += 1;
		dfs2(u, v);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		adjList[a].emplace_back(b);
		adjList[b].emplace_back(a);
	}

	dfs(1);

	if (!cycle.empty() && cycle.size() <= k) {
		cout << 2 << '\n';
		cout << cycle.size() << '\n';
		for (int v : cycle) {
			cout << v << ' ';
		}
		cout << '\n';
		return 0;
	}

	if (!cycle.empty()) {
		cout << 1 << '\n';
		int j = 0;
		for (int i = 0; j < (k + 1) / 2; i += 2) {
			cout << cycle[i] << ' ';
			j++;
		}
		return 0;
	}

	cnt[0] = 1;
	dfs2(1, 0);

	int c = (cnt[0] > cnt[1]) ? 0 : 1;

	cout << 1 << '\n';

	int j = 0;
	for (int i = 1; j < (k + 1) / 2; i++) {
		if (col[i] != c) continue;
		cout << i << ' ';
		j++;
	}
	cout << '\n';

	return 0;
}
