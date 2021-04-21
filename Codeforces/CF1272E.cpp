#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int N = 2e5 + 100;
int n, dist[N];
vector<int> adjList[N];
bool vis[N];

void bfs(vector<int> &vec) {
	memset(vis, 0, sizeof vis);

	queue<pii> q;

	for (int x : vec) {
		vis[x] = true;
		q.push({x, 0});
	}

	while (!q.empty()) {
		int v = q.front().first;
		int d = q.front().second;
		q.pop();

		dist[v] = max(d, dist[v]);
		for (int u : adjList[v]) {
			if (vis[u]) continue;
			vis[u] = true;
			q.push({u, d + 1});
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	vector<int> start[2];

	int x;
	for (int i = 1; i <= n; i++) {
		cin >> x;

		if (i - x >= 1) {
			adjList[i - x].emplace_back(i);
		}
		if (i + x <= n) {
			adjList[i + x].emplace_back(i);
		}

		start[x & 1].emplace_back(i);
	}

	bfs(start[0]);
	bfs(start[1]);

	for (int i = 1; i <= n; i++) {
		int tp = dist[i] ? dist[i] : -1;
		cout << tp << ' ';
	}
	cout << '\n';

	return 0;
}
