#include <bits/stdc++.h>
using namespace std;
const int N = 100000;
using pii = pair<int, int>;
int n, m;
bool vis[N + 5];
vector<int> adjList[N + 5];
vector<int> adjList2[N + 5];
vector<pii> edges;
unordered_map<int, unordered_map<int, int>> col;

void dfs1(int v) {
	vis[v] = true;

	for (int u : adjList[v]) {
		if (vis[u]) {
			adjList2[v].emplace_back(u);
			if (!col.count(min(u, v)) || !col[min(u,v)].count(max(u, v))) {
				if (v < u) {
					col[v][u] = true;
				}
				else {
					col[u][v] = false;
				}
			}
		}
		else {
			if (v < u) {
				col[v][u] = true;
			}
			else {
				col[u][v] = false;
			}
			dfs1(u);
		}
	}
}

void dfs2(int v) {
	vis[v] = true;

	for (int u : adjList2[v]) {
		if (!vis[u]) {
			dfs2(u);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		adjList[a].emplace_back(b);
		adjList[b].emplace_back(a);
		if (a > b) {
			swap(a, b);
		}
		edges.push_back({a, b});
	}

	dfs1(1);

	memset(vis, 0, sizeof vis);

	dfs2(1);

	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			cout << 0 << endl;
			return 0;
		}
	}

	for (pii e : edges) {
		if (col[e.first][e.second]) {
			cout << e.first << ' ' << e.second << '\n';
		}
		else {
			cout << e.second << ' ' << e.first << '\n';
		}
	}

	return 0;
}
