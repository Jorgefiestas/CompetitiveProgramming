#include <bits/stdc++.h>
using namespace std;
using pii = pair<long long, int>;
const int N = 1e5 + 100;
int n, m, par[N];
long long dist[N];
bool vis[N];
map<int, int> edg[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	int a, b, w;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> w;
		if (!edg[a].count(b)) {
			edg[a][b] = INT_MAX;
			edg[b][a] = INT_MAX;
		}
		edg[a][b] = min(edg[a][b], w);
		edg[b][a] = min(edg[b][a], w);
	}

	memset(dist, 1, sizeof dist);
	priority_queue<pii, vector<pii>, greater<pii>> pq;

	dist[1] = 0;
	pq.push({0, 1});

	while (!pq.empty()) {
		int v = pq.top().second;
		long long d = pq.top().first;
		vis[v] = true;
		pq.pop();
		
		if (v == n) break;
		if (d != dist[v]) continue;

		for (auto p : edg[v]) {
			int u = p.first;
			long long t = p.second;

			if (vis[u] || t + d > dist[u]) continue;
			dist[u] = t + d;
			par[u] = v;
			pq.push({t + d, u});
		}
	}

	vector<int> path;

	int nd = n;
	while (nd) {
		path.emplace_back(nd);
		nd = par[nd];
	}

	reverse(path.begin(), path.end());

	if (path[0] != 1) {
		cout << -1 << '\n';
		return 0;
	}

	for (int x : path) {
		cout << x << ' ';
	}
	cout << '\n';

	return 0;
}
