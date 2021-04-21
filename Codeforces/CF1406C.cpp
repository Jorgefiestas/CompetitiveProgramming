#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int N = 1e5 + 100;
int t, n, sz[N];
vector<int> adjList[N], centroids;

void dfs1(int v, int p) {
	sz[v] = 1;

	bool cent = true;
	for (int u : adjList[v]) {
		if (u == p) continue;
		dfs1(u, v);
		sz[v] += sz[u];
		cent = cent && sz[u] <= n / 2;
	}
	cent = cent && n - sz[v] <= n / 2;
	if (cent) {
		centroids.emplace_back(v);
	}
}

pii dfs2(int v, int p) {
	for (int u : adjList[v]) {
		if (u == p) continue;
		return dfs2(u, v);
	}
	return {v, p};
}


void solve() {
	cin >> n;

	int a, b;
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		adjList[a].emplace_back(b);
		adjList[b].emplace_back(a);
	}

	dfs1(1, -1);

	if (centroids.size() == 1) {
		cout << 1 << ' ' << adjList[1][0] << '\n';
		cout << 1 << ' ' << adjList[1][0] << '\n';
		return;
	}

	int c1 = centroids[0];
	int c2 = centroids[1];


	pii rem = dfs2(c1, c2);

	cout << rem.first << ' ' << rem.second << '\n';
	cout << c2 << ' ' << rem.first << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		centroids.clear();
		for (int i = 0; i <= n; i++) {
			adjList[i].clear();
		}

		solve();
	}

	return 0;
}
