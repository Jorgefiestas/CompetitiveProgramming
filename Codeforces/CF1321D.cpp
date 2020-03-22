#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 50;
int n, m, k, s, t, route[N], dist[N];
vector<int> adjList[N];
vector<int> adjListR[N];
unordered_set<int> nxt[N];
bool vis[N];

void bfs() {
	queue<int> Q;

	Q.push(t);
	vis[t] = true;
	while (!Q.empty()) {
		int v = Q.front();
		Q.pop();

		for (int u : adjListR[v]) {
			if (vis[u]) continue;
			vis[u] = true;
			dist[u] = dist[v] + 1;
			Q.push(u);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		adjList[a].emplace_back(b);
		adjListR[b].emplace_back(a);
	}

	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> route[i];
	}

	s = route[0];
	t = route[k - 1];

	bfs();

	for (int v = 1; v <= n; v++) {
		int mndist = INT_MAX;
		for (int u : adjList[v]) {
			mndist = min(mndist, dist[u]);
		}
		for (int u : adjList[v]) {
			if (dist[u] != mndist) continue;
			nxt[v].insert(u);
		}
	}

	int mx = 0;
	int mn = 0;
	for (int i = 0; i < k - 1; i++) {
		int v = route[i];
		if (!nxt[v].count(route[i + 1])) {
			mn++;
		}
		if (!nxt[v].count(route[i + 1]) || nxt[v].size() != 1) {
			mx++;
		}
	}

	cout << mn << ' ' << mx << '\n';

	return 0;
}
