#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int N = 2e5 + 10;
int n, deg[N], depth[N];
vector<int> adjList[N];
set<pii, greater<pii>> valid;

void dfs(int v, int p) {
	deg[v] = adjList[v].size();
	for (int u : adjList[v]) {
		if (u == p) continue;
		depth[u] = depth[v] + 1;
		dfs(u, v);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	int par;
	for (int i = 1; i <= n; i++) {
		cin >> par;
		adjList[par].emplace_back(i);
		if (par) {
			adjList[i].emplace_back(par);
		}
	}

	dfs(1, 0);

	for (int v = 1; v <= n; v++) {
		if (deg[v] % 2) continue;
		valid.insert({depth[v], v});
	}

	vector<int> sol;
	while (!valid.empty()) {
		int v = (*valid.begin()).second;
		sol.push_back(v);
		for (int u : adjList[v]) {
			if (!deg[u]) continue;

			deg[u]--;
			if (deg[u] % 2) {
				valid.erase({depth[u], u});
			}
			else {
				valid.insert({depth[u], u});
			}
		}
		valid.erase({depth[v], v});
		deg[v] = 0;
	}

	if (sol.size() != n) {
		cout << "NO\n";
		return 0;
	}

	cout << "YES\n";
	for (int x : sol) {
		cout << x << '\n';
	}

	return 0;
}
