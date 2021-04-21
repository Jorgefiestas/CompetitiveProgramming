#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100;
int t, n, q, par[N];
long long a[N];
vector<int> adjList[N];
bool vis[N];

void precalc(int v, int p) {
	par[v] = p;
	for (int u : adjList[v]) {
		if (u == p) continue;
		precalc(u, v);
	}
}

long long dfs(int v) {
	if (vis[v]) {
		long long ans = a[v];
		a[v] = 0;
		return ans;
	}
	vis[v] = true;

	long long ans = a[v];
	for (int u : adjList[v]) {
		if (u == par[v]) continue;
		for (int w : adjList[u]) {
			if (w == par[u]) continue;
			ans += dfs(w);
		}
	}

	a[v] = 0;
	return ans;
}


void solve() {
	cin >> n >> q;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	int vi, ui;
	for (int i = 1; i < n; i++) {
		cin >> vi >> ui;
		adjList[vi].emplace_back(ui);
		adjList[ui].emplace_back(vi);
	}

	precalc(1, -1);

	int v;
	for (int qi = 0; qi < q; qi++) {
		cin >> v;
		a[v] = dfs(v);
	}

	for (int i = 1; i <= n; i++) {
		cout << a[i] << ' ';
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		memset(vis, 0, sizeof vis);
		for (int i = 0; i <= n; i++) {
			adjList[i].clear();
		}
		solve();
	}

	return 0;
}
