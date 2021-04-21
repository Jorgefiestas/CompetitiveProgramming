#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
int n, m, dist[N];
bool vis[N];
vector<int> adjList[N];


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < N; i++) {
		dist[i] = INT_MAX;
	}

	cin >> n >> m;

	int colcnt = 1;

	char c;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> c;
			if (c == '#') {
				adjList[i].push_back(n + j);
				adjList[n + j].push_back(i);
			}
		}
	}

	queue<int> q;
	q.push(n);
	dist[n] = 0;
	vis[n] = true;

	while (!q.empty()) {
		int v = q.front();
		q.pop();

		for (int u : adjList[v]) {
			if (vis[u]) continue;
			vis[u] = true;
			dist[u] = dist[v] + 1;
			q.push(u);
		}
	}

	if (dist[1] == INT_MAX) {
		cout << -1 << '\n';
	}
	else {
		cout << dist[1] << '\n';
	}
	
	return 0;
}
