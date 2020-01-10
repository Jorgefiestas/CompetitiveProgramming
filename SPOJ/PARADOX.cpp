#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, bool>;
int n;
bool vis[105], col[105];
vector<pii> adjList[105];

bool dfs(int v) {
	vis[v] = true;

	for (pii p : adjList[v]) {
		int u = p.first;
		bool st = (p.second == col[v]);

		if (vis[u] && col[u] != st) {
			return false;
		}
		else if (vis[u]) {
			continue;
		}

		col[u] = st;
		if (!dfs(u)) {
			return false;
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int a;
	string val;
	while (cin >> n, n) {
		memset(vis, 0, sizeof vis);
		for (int i = 0; i < n; i++) {
			adjList[i].clear();
		}

		for (int i = 0; i < n; i++) {
			cin >> a >> val;
			int t = (val == "true") ? 1 : 0;
			adjList[i].push_back({a - 1, t});
			adjList[a - 1].push_back({i, t});
		}

		int par = true;
		for (int i = 0; i < n; i++) {
			if (vis[i]) continue;

			col[i] = false;
			par = par && dfs(i);
		}

		if (par) {
			cout << "NOT PARADOX\n";
		}
		else {
			cout << "PARADOX\n";
		}
	}

	return 0;
}
