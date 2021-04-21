#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int N = 5005;
int n, m, s;
bool occ[N], vis[N];
vector<int> adjList[N];

void dfs1(int v) {
	occ[v] = true;
	for (int u : adjList[v]) {
		if (occ[u]) continue;
		dfs1(u);
	}
}

int dfs2(int v) {
	vis[v] = true;
	int ans = 1;
	for (int u : adjList[v]) {
		if (occ[u] || vis[u]) continue;
		ans += dfs2(u);
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> s;

	int a, b;
	for (int i = 1; i <= m; i++) {
		cin >> a >> b;
		adjList[a].emplace_back(b);
	}

	dfs1(s);

	vector<pii> toConnect;

	for (int v = 1; v <= n; v++) {
		if (occ[v]) continue;
		memset(vis, 0, sizeof vis);
		int tv = dfs2(v);
		toConnect.push_back({tv, v});
	}

	sort(toConnect.rbegin(), toConnect.rend());

	int ans = 0;
	for (pii p : toConnect) {
		if (occ[p.second]) continue;
		ans += 1;
		dfs1(p.second);
	}

	cout << ans << '\n';

	return 0;
}
