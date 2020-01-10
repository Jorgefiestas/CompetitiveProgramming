#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
int n, m;
bool vis[300005];
int d[300005], deg[300005];
vector<int> adjList[300005];
vector<int> edges;
unordered_map<int, unordered_map<int, int>> eti;

void dfs(int v, int p) {
	vis[v] = 1;

	for (int u : adjList[v]) {
		if (vis[u]) continue;
		dfs(u, v);
	}

	if (deg[v] % 2 != d[v]) {
		edges.push_back(eti[v][p]);
		deg[v]++, deg[p]++;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	int ds = 0;
	int ti = -1;
	for (int i = 1; i <= n; i++) {
		cin >> d[i];
		ds = (d[i] == 1) ? ds + 1 : ds;
		if (d[i] == -1) {
			ti = i;
			d[i] = 0;
		}
	}

	if (ds % 2 && ti == -1) {
		cout << - 1 << endl;
		return 0;
	}

	if (ds % 2 == 1) {
		d[ti] = 1;
	}

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		adjList[a].emplace_back(b);
		adjList[b].emplace_back(a);
		eti[a][b] = i + 1;
		eti[b][a] = i + 1;
	}

	dfs(1, -1);

	cout << edges.size() << endl;
	for (int e : edges) {
		cout << e << endl;
	}

	return 0;
}
