#include <bits/stdc++.h>
using namespace std;
int n, x;
int par[200005];
int rad[200005];
int len[200005];
bool vis[200005];
vector<int> adjList[200005];

void bfs() {
	queue<int> Q;

	Q.push(1);
	vis[1] = true;
	while (!Q.empty()) {
		int v = Q.front();
		Q.pop();

		for (int u : adjList[v]) {
			if (vis[u]) continue;
			vis[u] = true;
			par[u] = v;
			rad[u] = rad[v] + 1;
			Q.push(u);
		}
	}
}

void dfs(int v, int p) {
	for (int u : adjList[v]) {
		if (u == p) continue;
		dfs(u, v);
		len[v] = max(len[u] + 1, len[v]);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> x;

	int a, b;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		adjList[a].emplace_back(b);
		adjList[b].emplace_back(a);
	}

	bfs();
	dfs(1, 0);
	int ans = 0;
	int stps = 0;

	while (rad[x] > stps) {
		ans = max(ans, 2 * (rad[x] + len[x]));
		x = par[x];
		stps++;
	}

	cout << ans << endl;

	return 0;
}
