#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int N = 1e5 + 10;
int n, m, s, t, dist[2][N], par[N];
vector<int> adjList[N];
map<int, int> weight[N], eid[N];

void dijkstra(int s, int id) {
	priority_queue<pii, vector<pii>, greater<pii>> pq;

	dist[id][s] = 0;
	pq.push({0, s});
	par[s] = -1;

	while (!pq.empty()) {
		int v = pq.top().second;
		int d = pq.top().first;
		pq.pop();

		if (dist[id][v] != d) continue;
		for (int u : adjList[v]) {
			if (d + weight[v][u] < dist[id][u]) {
				dist[id][u] = d + weight[v][u];
				par[u] = v;
				pq.push({dist[id][u], u});
			}
		}
	}
}

bool vis[N];
set<pii> candidates;
void dfs(int v) {
	vis[v] = true;
	
	for (int u : adjList[v]) {
		int d = dist[0][v] + dist[1][u];
		d = min(d, dist[1][v] + dist[0][u]);
		d += weight[v][u];

		if (candidates.count({d, eid[u][v]})) {
			candidates.erase({d, eid[u][v]});
		}
		else {
			candidates.insert({d, eid[u][v]});
		}

		if (!vis[u] && par[u] == v) {
			dfs(u);
		}
	}
}

int solve() {
	if (candidates.size() == 1) {
		return INT_MAX;
	}
	return (++candidates.begin())->first;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	cin >> s >> t;

	int a, b, w;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> w;
		adjList[a].emplace_back(b);
		adjList[b].emplace_back(a);
		weight[a][b] = w;
		weight[b][a] = w;
		eid[a][b] = i;
		eid[b][a] = i;
	}

	memset(dist, 63, sizeof dist);
	dijkstra(t, 1);
	dijkstra(s, 0);

	int ans = 0;
	while (t != s) {
		dfs(t);
		ans = max(ans, solve());
		t = par[t];
	}

	if (ans == INT_MAX) {
		ans = -1;
	}

	cout << ans << '\n';

	return 0;
}
