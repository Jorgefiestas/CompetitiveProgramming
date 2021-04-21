#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using plp = pair<long long, pii>;
const int N = 2e5 + 10;
int n, m;
vector<pii> adjList[N];
long long dist[N][4];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	int a, b, w;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> w;
		adjList[a].push_back({b, w});
		adjList[b].push_back({a, w});
	}

	priority_queue<plp, vector<plp>, greater<plp>> pq;
	memset(dist, 1, sizeof dist);

	dist[1][0] = 0;
	pq.push({0, {1, 0}});

	while (!pq.empty()) {
		auto [d, p] = pq.top();
		auto [v, s] = p;
		pq.pop();

		if (d != dist[v][s]) continue;

		for (auto [u, w] : adjList[v]) {
			long long nd = d + 1LL * w;
			if (nd < dist[u][s]) {
				dist[u][s] = nd;
				pq.push({nd, {u, s}});
			}

			if (s == 0 && nd  < dist[u][3]) {
				dist[u][3] = nd;
				pq.push({nd, {u, 3}});
			}

			if (!(s & 1) && d < dist[u][s ^ 1]) {
				dist[u][s ^ 1] = d;
				pq.push({d, {u, s ^ 1}});
			}

			nd += w;
			if (!(s & 2) && nd < dist[u][s ^ 2]) {
				dist[u][s ^ 2] = nd;
				pq.push({nd, {u, s ^ 2}});
			}
		}
	}

	for (int v = 2; v <= n; v++) {
		cout << dist[v][3] << ' ';
	}
	cout << '\n';

	return 0;
}
