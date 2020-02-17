#include <bits/stdc++.h>
using namespace std;
const int N = 300000;
using pii = pair<int, int>;
int n, m, s, e, c, dsu[N + 5], compv[N + 5];
bool vis[N + 5], cca[N + 5];
vector<int> adjList[N + 5], order, components[N + 5];
unordered_set<int> adjListSC[N + 5];
unordered_map<int, unordered_map<int, bool>> eor, art, cart;

void dfs1(int v) {
	vis[v] = true;
	for (int u : adjList[v]) {
		if (!vis[u]) {
			eor[v][u] = true;
			eor[u][v] = false;
			dfs1(u);
		}
	}
	order.push_back(v);
}

void dfs2(int v) {
	vis[v] = true;
	components[c].emplace_back(v);
	compv[v] = c;
	for (int u : adjList[v]) {
		if (!vis[u] && !eor[v][u]) {
			dfs2(u);
		}
	}
}

bool dfs3(int v, int rwa) {
	vis[v] = true;
	rwa = rwa || cca[v];

	if (v == compv[e]) {
		return rwa;
	}

	for (int u : adjListSC[v]) {
		if (vis[u]) continue;
		if (dfs3(u, rwa || cart[u][v])) {
			return true;
		}
	}

	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	int a, b;
	for (int i = 0; i < m; i++) {
		int c;
		cin >> a >> b >> c;
		adjList[a].push_back(b);
		adjList[b].push_back(a);
		if (c) {
			art[a][b] = true;
			art[b][a] = true;
		}
	}

	cin >> s >> e;

	dfs1(s);

	memset(vis, 0, sizeof vis);

	c = 1;
	for (int i = 0; i < n; i++) {
		int u = order[n - 1 - i];
		if (!vis[u]) {
			dfs2(u);
			c++;
		}
	}

	for (int i = 1; i < c; i++) {
		for (int v : components[i]) {
			for (int u : adjList[v]) {
				if (compv[u] != compv[v]) {
					adjListSC[i].insert(compv[u]);
					cart[i][compv[u]] = cart[i][compv[u]] || art[v][u];
				}
				else {
					cca[i] = cca[i] || art[u][v];
				}
			}
		}
	}

	memset(vis, 0, sizeof vis);

	if (dfs3(compv[s], false)) {
		cout << "YES\n";
	}
	else {
		cout << "NO\n";
	}

	return 0;
}
