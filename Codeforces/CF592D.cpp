#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int N = 1.5e5; 
int n, m, sz[N];
vector<int> adjListFull[N];
vector<int> adjList[N];
set<int> bad;
pii dp[N];

bool dfsBuild(int v, int p) {
	bool good = bad.count(v);

	for (int u : adjListFull[v]) {
		if (u == p) continue;
		bool tgood = dfsBuild(u, v);
		good = good || tgood;
		if (tgood) {
			adjList[v].emplace_back(u);
			adjList[u].emplace_back(v);
			sz[v] += sz[u] + 1;
		}
	}

	return good;
}

int border = INT_MAX;
int border_depth = -1;
void dfs(int v, int p, int d) {
	if (d == border_depth) {
		border = min(v, border);
	}
	if (d > border_depth) {
		border = v;
		border_depth = d;
	}

	for (int u : adjList[v]) {
		if (u == p) continue;
		dfs(u, v, d + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	int a, b;
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		adjListFull[a].emplace_back(b);
		adjListFull[b].emplace_back(a);
	}

	for (int i = 0; i < m; i++) {
		cin >> a;
		bad.insert(a);
	}

	int s = *bad.begin();
	dfsBuild(s, -1);
	dfs(s, -1, 0);
	int ob = border;
	dfs(border, -1, 0);
	border = min(ob, border);

	cout << border << '\n';
	cout << 2 * sz[s] - border_depth << '\n';

	return 0;
}
