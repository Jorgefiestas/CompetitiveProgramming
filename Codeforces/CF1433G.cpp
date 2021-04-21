#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int N = 1005;
int n, m, k, dist[N][N];
vector<pii> edgs, paths, adjList[N];

void dijkstra(int s) {
	priority_queue<pii> pq;
	pq.push({0, s});

	fill(dist[s], dist[s] + n + 1, INT_MAX);
	dist[s][s] = 0;

	while (!pq.empty()) {
		auto [d, v] = pq.top();
		pq.pop();
		d = -d;

		if (dist[s][v] != d) continue;

		for (auto [u, w] : adjList[v]) {
			int nd = d + w;
			if (nd < dist[s][u]) {
				dist[s][u] = nd;
				pq.push({-nd, u});
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	memset(dist, 1, sizeof dist);

	cin >> n >> m >> k;

	int a, b, w;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> w;
		adjList[a].push_back({b, w});
		adjList[b].push_back({a, w});
		edgs.push_back({a, b});
	}

	for (int v = 1; v <= n; v++) {
		dijkstra(v);
	}

	int ans = 0;
	for (int i = 0; i < k; i++) {
		cin >> a >> b;
		paths.push_back({a, b});
		ans += dist[a][b];
	}

	for (auto [u, v] : edgs) {
		int can = 0;
		for (auto [a, b] : paths) {
			int cont = dist[a][b];
			cont = min(cont, dist[a][u] + dist[v][b]);
			cont = min(cont, dist[a][v] + dist[u][b]);
			can += cont;
		}
		ans = min(ans, can);
	}

	cout << ans << '\n';

	return 0;
}
