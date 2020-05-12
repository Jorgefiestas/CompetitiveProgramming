#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int N = 150;
set<int> adjList[N];
pii children[N];
int n, q, mem[N][N], app[N][N];
bool vis[N][N];

void dfs(int v, int p) {
	if (adjList[v].count(p)) {
		adjList[v].erase(p);
	}

	if (adjList[v].size()) {
		children[v].first = *adjList[v].begin();
		children[v].second = *(next(adjList[v].begin()));

		dfs(children[v].first, v);
		dfs(children[v].second, v);
	}
}

int dp(int v, int k) {
	if (k == 0) {
		return 0;
	}
	if (vis[v][k]) {
		return mem[v][k];
	}
	vis[v][k] = true;

	int cl = children[v].first;
	int cr = children[v].second;

	int ans = 0;
	int l = 0, r = 9;
	if (cr) {
		ans = max(dp(cr, k - 1) + app[v][cr], ans);
	}
	if (cl) {
		ans = max(ans, dp(cl, k - 1) + app[v][cl]);
	}
	if (cl && cr && k > 1) {
		for (int i = 1; i < k; i++) {
			int l = dp(cl, k - i - 1) + app[v][cl];
			int r = dp(cr, i - 1) + app[v][cr];
			ans = max(ans, l + r);
		}
	}

	return mem[v][k] = ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> q;

	int a, b, w;
	for (int i = 1; i < n; i++) {
		cin >> a >> b >> w;
		adjList[a].insert(b);
		adjList[b].insert(a);
		app[a][b] = w;
		app[b][a] = w;
	}

	dfs(1, -1);

	cout << dp(1, q) << '\n';

	return 0;
}
