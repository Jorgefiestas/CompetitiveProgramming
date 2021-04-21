#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100;
int t, n, m, q, w[N];
vector<int> adjList[N];
bool vis[N];

bool parity(int x) {
	return __builtin_popcount(x) & 1;
}

int dfs(int v, bool par) {
	vis[v] = true;
	int ans = 1;
	for (int u : adjList[v]) {
		if (vis[u] || parity(w[u]) != par) continue;
		ans += dfs(u, par);
	}
	return ans;
}

void solve() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> w[i];
	}

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		adjList[a].emplace_back(b);
		adjList[b].emplace_back(a);
	}

	int ev = 0;
	int od = 0;

	for (int i = 1; i <= n; i++) {
		if (parity(w[i])) continue;
		ev = max(ev, dfs(i, 0));
	}
	for (int i = 1; i <= n; i++) {
		if (!parity(w[i])) continue;
		od = max(od, dfs(i, 1));
	}

	cin >> q;

	int op, k, ans;
	for (int qi = 0; qi < q; qi++) {
		cin >> op >> k;
		if (parity(w[0]) == parity(w[0] ^ k)) {
			ans = (op == 1) ? od : ev;
		}
		else {
			ans = (op == 1) ? ev : od;
		}
		cout << ans << '\n';
	}
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
