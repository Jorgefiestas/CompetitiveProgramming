#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, m, q;
vector<int> adjList[N];
vector<int> descendants[N];
bool vis[N], art[N];
map<int, bool> bridge[N];

int timer, low[N], tin[N], tout[N];
void dfs(int v, int p, bool root = false) {
	vis[v] = true;
	tin[v] = low[v] = timer++;

	int nc = 0;
	bool any = false;
	for (int u : adjList[v]) {
		if (u == p) continue;
		if (vis[u]) {
			low[v] = min(low[v], tin[u]);
			continue;
		}

		nc++;
		dfs(u, v);
		descendants[v].emplace_back(u);
		low[v] = min(low[v], low[u]);
		any = any || (low[u] >= tin[v]);
		if (low[u] > tin[v]) {
			bridge[u][v] = true;
			bridge[v][u] = true;
		}
	}

	art[v] = root ? nc > 1 : any;
	tout[v] = timer++;
}

bool ancestor(int v, int u) {
	return tin[v] <= tin[u] && tout[u] <= tout[v];
}

bool query1(int a, int b, int g1, int g2) {
	if (tin[g1] < tin[g2]) swap(g1, g2);
	return !bridge[g1][g2] || ancestor(g1, a) == ancestor(g1, b);
}

bool query2(int a, int b, int v) {
	if (!art[v]) return true;

	int c1 = -1, c2 = -1;
	if (ancestor(v, a)) {
		c1 = *prev(upper_bound(descendants[v].begin(), 
					descendants[v].end(), 
					a,
					[](int i, int j) {
						return tin[i] < tin[j];
					}));
		if (low[c1] < tin[v]) c1 = -1;
	}
	if (ancestor(v, b)) {
		c2 = *prev(upper_bound(descendants[v].begin(), 
					descendants[v].end(), 
					b, 
					[](int i, int j) {
						return tin[i] < tin[j];
					}));
		if (low[c2] < tin[v]) c2 = -1;
	}

	return c1 == c2;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adjList[a].emplace_back(b);
		adjList[b].emplace_back(a);
	}

	for (int i = 1; i <= n; i++) {
		if (vis[i]) continue;
		dfs(i, 0, true);
	}

	cin >> q;

	int op, a, b, c, d;
	for (int i = 0; i < q; i++) {
		cin >> op;

		bool pos;
		if (op == 1) {
			cin >> a >> b >> c >> d;
			pos = query1(a, b, c, d);
		}
		else {
			cin >> a >> b >> c;
			pos = query2(a, b, c);
		}

		if (pos) {
			cout << "da\n";
		}
		else {
			cout << "ne\n";
		}
	}

	return 0;
}
