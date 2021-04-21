#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
int t, n, m, good[N], pass[N], pop[N], hap[N];
vector<int> adjList[N];

bool poss;
void dfs(int v, int p) {

	pass[v] = pop[v];

	int gchild = 0;
	for (int u : adjList[v]) {
		if (u == p) continue;
		dfs(u, v);
		pass[v] += pass[u];
		gchild += good[u];
	}

	if ((pass[v] & 1) != (hap[v] & 1)) {
		poss = false;
	}
	if (hap[v] < -pass[v] || hap[v] > pass[v]) {
		poss = false;
	}

	good[v] = (pass[v] + hap[v]) / 2;

	if (good[v] < gchild) {
		poss = false;
	}
}

bool solve() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> pop[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> hap[i];
	}

	int a, b;
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		adjList[a].emplace_back(b);
		adjList[b].emplace_back(a);
	}

	poss = true;
	dfs(1, -1);

	return poss;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		for (int i = 0; i <= n; i++) {
			adjList[i].clear();
		}

		if (solve()) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}

	return 0;
}
