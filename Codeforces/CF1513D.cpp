#include <bits/stdc++.h>
using namespace std;

struct Edge {
	int u, v, w;

	bool operator<(const Edge &e) const {
		return w < e.w;
	}
};

struct DSU {
	int n;
	vector<int> par;

	DSU(int n): n(n), par(n){
		for (int i = 0; i < n; i++) {
			par[i] = i;
		}
	}

	int root(int idx) {
		while (idx != par[idx]) {
			par[idx] = par[par[idx]];
			idx = par[idx];
		}
		return idx;
	}

	void join(int a, int b) {
		par[root(a)] = par[root(b)];
	}
};

long long solve() {
	int n, p;
	cin >> n >> p;

	vector<int> a(n + 1);
	vector<Edge> edges;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (int i = 1; i < n; i++) {
		edges.push_back({i, i + 1, p});
	}

	for (int i = 1; i <= n; i++) {
		for (int j = i - 1; j > 0; j--) {
			if (a[j] % a[i]) break;
			edges.push_back({i, j, a[i]});
			if (a[i] == a[j]) break;
		}
		for (int j = i + 1; j <= n; j++) {
			if (a[j] % a[i]) break;
			edges.push_back({i, j, a[i]});
			if (a[i] == a[j]) break;
		}
	}

	sort(edges.begin(), edges.end());
	DSU dsu(n + 1);
 
	long long mst = 0;
	for (auto [u, v, w] : edges) {
		if (dsu.root(u) == dsu.root(v)) continue;
		mst += (long long) w;
		dsu.join(u, v);
	}

	return mst;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		cout << solve() << '\n';
	}

	return 0;
}
